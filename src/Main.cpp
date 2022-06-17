#include "Main.h"

Main::Main() : wxFrame(NULL, wxID_ANY, "wxmapedit", wxDefaultPosition, wxSize(800,600))
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_NewMap, "&New map\tCtrl-N",
                     "Create a new map");
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
    Bind(wxEVT_MENU, &Main::OnLoadMap, this, ID_LoadMap);
    Bind(wxEVT_MENU, &Main::OnSaveMap, this, ID_SaveMap);
    Bind(wxEVT_MENU, &Main::OnExit, this, wxID_EXIT);

    MapView* mapView = new MapView(this, ID_MapView);
    //mapView->SetPosition(wxPoint(10, 10));
    //mapView->SetSize(wxSize(480, 480));
    //mapView->SetBackgroundColour(wxColor(0,0,0));
    Bind(wxEVT_PAINT, &MapView::OnPaint, mapView, ID_MapView);
    mapView->Refresh();

    wxButton *generateMap = new wxButton(this, ID_GenerateMap, "Generate Map", wxPoint(10, 500), wxSize(125, 35));
    //generateMap->Show();
    Bind(wxEVT_BUTTON, &Main::OnGenerateMap, this, ID_GenerateMap);
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
    const char* map_name = "testmap.map";
    printf("Saving map %s...\n", map_name);
    save_map(&test_map, map_name);
    printf("Map %s saved to \"%s\" directory\n", map_name, MAPS_DIR);
}

void Main::OnGenerateMap(wxCommandEvent &event)
{
    printf("Generating test map....\n");
    generate_map(&test_map);
    printf("Test map generated\n");
}

void Main::OnExit(wxCommandEvent &event)
{
    printf("Quitting program\n");
    Close(true);
}