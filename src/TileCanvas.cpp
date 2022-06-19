#include "TileCanvas.h"

TileCanvas::TileCanvas(wxWindow* parent, wxWindowID id) : wxPanel(parent, id)
{
    m_tileSize = 48;
    SetPosition(wxPoint(10, 10));
    SetSize(wxSize(192, 128));

    SetBackgroundStyle(wxBG_STYLE_PAINT);
    SetBackgroundColour(wxColour(0,0,0));
}

void TileCanvas::OnPaint(wxPaintEvent &event)
{
    wxBufferedPaintDC dc(this);
    PrepareDC(dc);
    render_tiles(dc);
}

void TileCanvas::OnMouseEvent(wxMouseEvent &event)
{
    // wxPoint pos = event.GetPosition();
    // if (event.LeftDown() || event.Dragging())
    // {
    //     m_map->setTile(pos.x / m_tileSize, pos.y / m_tileSize, 1);
    //     Refresh(false); // only render what we changed
    // }
}

void TileCanvas::render_tiles(wxDC& dc)
{
    dc.Clear();

    wxBrush brush = dc.GetBrush();

    // draw the tiles
    brush.SetColour(wxColour(255, 255, 255));
    dc.SetBrush(brush);

    // just draw 2 tiles for now
    for (int y = 0; y < 1; y++)
        for (int x = 0; x < 2; x++)
        {
            dc.DrawRectangle(x * m_tileSize, y * m_tileSize, m_tileSize, m_tileSize);
        }
}

wxBEGIN_EVENT_TABLE(TileCanvas, wxPanel)
EVT_PAINT(TileCanvas::OnPaint)
EVT_MOUSE_EVENTS(TileCanvas::OnMouseEvent) // handle ALL mouse events at once
wxEND_EVENT_TABLE()