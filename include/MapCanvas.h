#ifndef MAPCANVAS_H
#define MAPCANVAS_H

#include <wx/wx.h>
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/dcbuffer.h>

#include "map.h"

class MapCanvas : public wxPanel
{
public:
    MapCanvas(wxWindow* parent, wxWindowID id, Map* map);

    void OnPaint(wxPaintEvent &event);

private:
    Map* m_map;
    
    void render(wxDC& dc);
    void render_blank_map(wxDC& dc);

    wxDECLARE_EVENT_TABLE();
};

#endif