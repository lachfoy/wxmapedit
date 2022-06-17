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

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();

    Bind(wxEVT_MENU, &Main::OnNewMap, this, ID_NewMap);
    Bind(wxEVT_MENU, &Main::OnLoadMap, this, ID_LoadMap);
    Bind(wxEVT_MENU, &Main::OnSaveMap, this, ID_SaveMap);
    Bind(wxEVT_MENU, &Main::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &Main::OnExit, this, wxID_EXIT);

    generateMapButton = new wxButton(this, ID_GenerateMap, _T("Generate Map"));
    Bind(wxEVT_BUTTON, &Main::OnGenerateMap, this, ID_GenerateMap);
}

void Main::OnNewMap(wxCommandEvent &event)
{
    wxLogMessage("Create a new map");
}

void Main::OnLoadMap(wxCommandEvent &event)
{
    wxLogMessage("Load a new map");
}

void Main::OnSaveMap(wxCommandEvent &event)
{
    wxLogMessage("Save a new map");
    printf("Saving test map....");
    save_map(&test_map, "maps/testmap");
}

void Main::OnGenerateMap(wxCommandEvent &event)
{
    wxLogMessage("Generate");
    printf("Generating test map....");
    generate_map(&test_map);
}

void Main::OnExit(wxCommandEvent &event)
{
    Close(true);
}

void Main::OnAbout(wxCommandEvent &event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}