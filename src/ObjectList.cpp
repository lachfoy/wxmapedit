#include "ObjectList.h"

ObjectList::ObjectList(wxWindow* parent, wxWindowID id) : wxListBox(parent, id)
{
    SetPosition(wxPoint(10, 10));
    SetSize(wxSize(192, 128));

    // assign items
    m_objectNames = {
        "Player",
        "Cool_Powerup",
        "Enemy1",
        "Enemy2"};
    
    // insert the items into list box
    for (int i = 0; i < m_objectNames.size(); i++)
        InsertItems(1, &m_objectNames[i], i);
}
