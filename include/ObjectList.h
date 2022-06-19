#ifndef OBJECTLIST_H
#define OBJECTLIST_H

#include <vector>

#include <wx/wx.h>

class ObjectList : public wxListBox
{
public:
    ObjectList(wxWindow* parent, wxWindowID id);

private:
    std::vector<wxString> m_objectNames;
};

#endif