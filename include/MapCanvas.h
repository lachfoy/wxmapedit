#ifndef MAPCANVAS_H
#define MAPCANVAS_H

#include <wx/wx.h>
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/dcbuffer.h>

class MapView : public wxPanel
{
public:
    MapView(wxFrame* parent, wxWindowID id);

    void OnPaint(wxPaintEvent &event);

private:
    void OnDraw(wxDC& dc);
};

#endif