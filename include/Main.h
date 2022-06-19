#ifndef MAIN_H
#define MAIN_H

#include <wx/wx.h>

#include <string>
#include "MapCanvas.h"
#include "MapWrapper.h"
#include "TileCanvas.h"
#include "ObjectList.h"

class Main : public wxFrame
{
public:
    Main();

private:
    MapWrapper test_map;
    std::string current_map_name;
    MapCanvas* m_mapCanvas;
    TileCanvas* m_tileCanvas;
    wxListBox* m_objectList;

    void OnNewMap(wxCommandEvent &event);
    void OnLoadMap(wxCommandEvent &event);
    void OnSaveMap(wxCommandEvent &event);
    void OnGenerateMap(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
};

enum
{
    ID_NewMap = 1,
    ID_LoadMap = 2,
    ID_SaveMap = 3,
    ID_GenerateMap = 4,
    ID_MapCanvas = 5,
    ID_TileCanvas = 6,
    ID_ObjectList = 7
};

#endif