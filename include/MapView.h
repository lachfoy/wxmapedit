#ifndef MAPVIEW_H
#define MAPVIEW_H

#include <wx/wx.h>

class MapView : public wxPanel
{
public:
    MapView(wxFrame* parent, wxWindowID id);

    void OnPaint(wxPaintEvent &event);

private:
    void render(wxDC& dc);
};

#endif