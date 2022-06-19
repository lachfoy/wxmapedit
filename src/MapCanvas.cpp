#include "MapCanvas.h"

MapCanvas::MapCanvas(wxWindow* parent, wxWindowID id, MapWrapper* map) : wxPanel(parent, id)
{
    m_map = map;
    m_tileSize = 32;
    SetPosition(wxPoint(10, 10));
    SetSize(wxSize(544, 416));

    SetBackgroundStyle(wxBG_STYLE_PAINT);
    SetBackgroundColour(wxColour(0,0,0));
}

void MapCanvas::OnPaint(wxPaintEvent &event)
{
    wxBufferedPaintDC dc(this);
    PrepareDC(dc);
    render_blank_map(dc);
}

void MapCanvas::OnMouseEvent(wxMouseEvent &event)
{
    wxPoint pos = event.GetPosition();
    if (event.LeftDown() || event.Dragging())
    {
        m_map->setTile(pos.x / m_tileSize, pos.y / m_tileSize, 1);
        Refresh(false); // only render what we changed
    }
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

    dc.DrawRectangle(0, 0, m_tileSize, m_tileSize);
}

void MapCanvas::render_blank_map(wxDC& dc)
{
    dc.Clear();

    wxBrush brush = dc.GetBrush();

    // draw a background
    brush.SetColour(wxColour(137, 137, 137));
    dc.SetBrush(brush);
    dc.DrawRectangle(0, 0, m_map->getWidth() * m_tileSize, m_map->getHeight() * m_tileSize);

    // draw the tiles
    brush.SetColour(wxColour(255, 255, 255));
    dc.SetBrush(brush);

    // wrapping the map C code into a C++ class could help with these sorts of things
    for (int y = 0; y < m_map->getHeight(); y++)
        for (int x = 0; x < m_map->getWidth(); x++)
        {
            if (m_map->isSolid(x, y))
                dc.DrawRectangle(x * m_tileSize, y * m_tileSize, m_tileSize, m_tileSize);
        }
}

wxBEGIN_EVENT_TABLE(MapCanvas, wxPanel)
EVT_PAINT(MapCanvas::OnPaint)
EVT_MOUSE_EVENTS(MapCanvas::OnMouseEvent) // handle ALL mouse events at once
wxEND_EVENT_TABLE()