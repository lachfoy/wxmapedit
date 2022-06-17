#ifndef MAIN_H
#define MAIN_H

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "map.h"

class Main : public wxFrame
{
public:
    Main();

private:
    wxButton *generateMapButton;
    Map test_map;

    void OnNewMap(wxCommandEvent &event);
    void OnLoadMap(wxCommandEvent &event);
    void OnSaveMap(wxCommandEvent &event);
    void OnGenerateMap(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
};

enum
{
    ID_NewMap = 1,
    ID_LoadMap = 2,
    ID_SaveMap = 3,
    ID_GenerateMap = 4
};

#endif