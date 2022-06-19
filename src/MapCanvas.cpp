#include "MapCanvas.h"

MapCanvas::MapCanvas(wxWindow* parent, wxWindowID id, MapWrapper* map) : wxPanel(parent, id)
{
    m_map = map;

    SetPosition(wxPoint(10, 10));
    SetSize(wxSize(480, 480));

    SetBackgroundStyle(wxBG_STYLE_PAINT);
    SetBackgroundColour(wxColour(0,0,0));
}

void MapCanvas::OnPaint(wxPaintEvent &event)
{
    wxBufferedPaintDC dc(this);
    PrepareDC(dc);
    render_blank_map(dc);
}
    
void MapCanvas::render(wxDC& dc)
{
    dc.Clear();

    wxBrush brush = dc.GetBrush();
    wxPen pen = dc.GetPen();

    pen.SetStyle(wxPENSTYLE_SOLID);
    pen.SetColour(wxColour(0, 0, 255));
    brush.SetColour(wxColour(0, 255, 0));

    dc.SetPen(pen);
    dc.SetBrush(brush);

    dc.DrawRectangle(0, 0, 16, 16);
}

void MapCanvas::render_blank_map(wxDC& dc)
{
    dc.Clear();

    wxBrush brush = dc.GetBrush();
    wxPen pen = dc.GetPen();

    pen.SetStyle(wxPENSTYLE_TRANSPARENT); // dont use outline
    pen.SetColour(wxColour(0, 0, 255));
    brush.SetColour(wxColour(255, 255, 255));
    
    dc.SetPen(pen);
    dc.SetBrush(brush);

    // wrapping the map C code into a C++ class could help with these sorts of things
    for (int y = 0; y < m_map->getHeight(); y++)
        for (int x = 0; x < m_map->getWidth(); x++)
        {
            if (m_map->isSolid(x, y))
                dc.DrawRectangle(x * m_tile_size, y * m_tile_size, m_tile_size, m_tile_size);
        }
}

wxBEGIN_EVENT_TABLE(MapCanvas, wxPanel)
EVT_PAINT(MapCanvas::OnPaint)
wxEND_EVENT_TABLE()