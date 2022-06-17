#include "MapCanvas.h"

MapCanvas::MapCanvas(wxWindow* parent, wxWindowID id) : wxPanel(parent, id)
{
    SetPosition(wxPoint(10, 10));
    SetSize(wxSize(480, 480));

    SetBackgroundStyle(wxBG_STYLE_PAINT);
    SetBackgroundColour(wxColour(0,0,0));
}

void MapCanvas::OnPaint(wxPaintEvent &event)
{
    wxBufferedPaintDC dc(this);
    PrepareDC(dc);
    OnDraw(dc);
}
    
void MapCanvas::OnDraw(wxDC& dc)
{
    dc.Clear();

    //dc.Set
    //dc.SetBackground(wxColor(0, 0, 0));

    wxBrush brush = dc.GetBrush();
    wxPen pen = dc.GetPen();

    pen.SetStyle(wxPENSTYLE_SOLID);
    pen.SetColour(wxColour(0, 0, 255));
    dc.SetPen(pen);

    dc.SetBrush(brush);
    dc.DrawRectangle(0, 0, 16, 16);
}

wxBEGIN_EVENT_TABLE(MapCanvas, wxPanel)
    EVT_PAINT(MapCanvas::OnPaint)
wxEND_EVENT_TABLE()