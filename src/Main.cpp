#include "Main.h"

Main::Main() : wxFrame(NULL, wxID_ANY, "wxmapedit", wxDefaultPosition, wxSize(800,600))
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_NewMap, "&New map\tCtrl-N",
                     "Create a new map");
    menuFile->Append(ID_GenerateMap, "&Generate map",
                     "Generate a new map from dummy data");
    menuFile->Append(ID_LoadMap, "&Load map\tCtrl-L",
                     "Load map from file");
    menuFile->Append(ID_SaveMap, "&Save map\tCtrl-S",
                     "Save map to file");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");

    SetMenuBar(menuBar);

    CreateStatusBar();

    Bind(wxEVT_MENU, &Main::OnNewMap, this, ID_NewMap);
    Bind(wxEVT_MENU, &Main::OnGenerateMap, this, ID_GenerateMap);
    Bind(wxEVT_MENU, &Main::OnLoadMap, this, ID_LoadMap);
    Bind(wxEVT_MENU, &Main::OnSaveMap, this, ID_SaveMap);
    Bind(wxEVT_MENU, &Main::OnExit, this, wxID_EXIT);

    printf("Generating test map....\n");
    test_map = MapWrapper::generateMap();
    printf("Test map generated\n");
    printf("Creating map canvas...\n");
    m_mapCanvas = new MapCanvas(this, ID_MapCanvas, &test_map);
    printf("Test map drawn to canvas...\n");

    // m_tileCanvas = new TileCanvas(this, ID_TileCanvas);
    // m_tileCanvas->SetPosition(wxPoint(10 + m_mapCanvas->GetSize().GetX() + 10, 10));

    wxStaticText* objectListTitle = new wxStaticText(this, wxID_ANY, "Objects");
    objectListTitle->SetPosition(wxPoint(10 + m_mapCanvas->GetSize().GetX() + 10, 10));
    m_objectList = new ObjectList(this, ID_ObjectList);
    m_objectList->SetPosition(wxPoint(10 + m_mapCanvas->GetSize().GetX() + 10, 30));
}

void Main::OnNewMap(wxCommandEvent &event)
{
    wxLogMessage("");
}

void Main::OnLoadMap(wxCommandEvent &event)
{
    wxLogMessage("");
}

void Main::OnSaveMap(wxCommandEvent &event)
{
    // const char* map_name = "testmap.map";
    // printf("Saving map %s...\n", map_name);
    // save_map(&test_map, map_name);
    // printf("Map %s saved to \"%s\" directory\n", map_name, MAPS_DIR);
}

void Main::OnGenerateMap(wxCommandEvent &event)
{
    printf("Generating test map....\n");
    test_map = MapWrapper::generateMap();
    printf("Test map generated\n");
    printf("Creating map canvas...\n");
    m_mapCanvas = new MapCanvas(this, ID_MapCanvas, &test_map);
    printf("Test map drawn to canvas...\n");
}

void Main::OnExit(wxCommandEvent &event)
{
    printf("Quitting program\n");
    Close(true);
}