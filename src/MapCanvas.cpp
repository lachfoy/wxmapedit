#include "MapCanvas.h"

MapView::MapView(wxFrame* parent, wxWindowID id) : wxPanel(parent, id)
{
    SetBackgroundStyle(wxBG_STYLE_PAINT);
}

void MapView::OnPaint(wxPaintEvent &event)
{
    wxBufferedPaintDC dc(this);
    PrepareDC(dc);
    OnDraw(dc);
}
    
void MapView::OnDraw(wxDC& dc)
{
    dc.Clear();

    wxBrush brush = dc.GetBrush();
    wxPen pen = dc.GetPen();

    pen.SetStyle(wxPENSTYLE_LONG_DASH);
    pen.SetColour(wxColour(0,0,255));
    dc.SetPen(pen);

    dc.SetBrush(brush);
    dc.DrawRectangle(10, 10, 100, 100);
}