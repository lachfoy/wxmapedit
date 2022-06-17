#ifndef MAIN_H
#define MAIN_H

#include <wx/wx.h>

#include <string>
#include "MapCanvas.h"

extern "C" {
    #include "map.h"
}

class Main : public wxFrame
{
public:
    Main();

private:
    Map test_map;
    std::string current_map_name;

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
    ID_GenerateMap = 4,
    ID_MapCanvas = 5
};

#endif