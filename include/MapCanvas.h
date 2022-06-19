#ifndef MAPCANVAS_H
#define MAPCANVAS_H

#include <wx/wx.h>
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/dcbuffer.h>

#include "MapWrapper.h"
#include "ImageLoader.h"

class MapCanvas : public wxPanel
{
public:
    MapCanvas(wxWindow* parent, wxWindowID id, MapWrapper* map);

    void OnPaint(wxPaintEvent &event);
    void OnMouseEvent(wxMouseEvent &event);

private:
    MapWrapper* m_map;
    int m_tileSize;
    wxBitmap m_tileBitmap;
    
    void render(wxDC& dc);
    void render_blank_map(wxDC& dc);

    wxDECLARE_EVENT_TABLE();
};

#endif