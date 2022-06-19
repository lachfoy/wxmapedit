#ifndef TILECANVAS_H
#define TILECANVAS_H

#include <wx/wx.h>
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/dcbuffer.h>

class TileCanvas : public wxPanel
{
public:
    TileCanvas(wxWindow* parent, wxWindowID id);

    void OnPaint(wxPaintEvent &event);
    void OnMouseEvent(wxMouseEvent &event);

private:
    int m_tileSize;
    
    void render_tiles(wxDC& dc);

    wxDECLARE_EVENT_TABLE();
};

#endif