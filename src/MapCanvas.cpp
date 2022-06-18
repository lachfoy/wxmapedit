#include "MapCanvas.h"

MapCanvas::MapCanvas(wxWindow* parent, wxWindowID id, Map* map) : wxPanel(parent, id)
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
    const int tile_size = 24;
    for (int y = 0; y < m_map->h; y++)
        for (int x = 0; x < m_map->w; x++)
        {
            if (m_map->wall_data[y * m_map->w + x] > 0)
                dc.DrawRectangle(x * tile_size, y * tile_size, tile_size, tile_size);
        }
}

wxBEGIN_EVENT_TABLE(MapCanvas, wxPanel)
EVT_PAINT(MapCanvas::OnPaint)
wxEND_EVENT_TABLE()