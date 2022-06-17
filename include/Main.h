#ifndef MAIN_H
#define MAIN_H

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class Main : public wxFrame
{
public:
    Main();

private:
    void OnNewMap(wxCommandEvent &event);
    void OnLoadMap(wxCommandEvent &event);
    void OnSaveMap(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
};

#endif