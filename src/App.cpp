#include "App.h"
#include "Main.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    Main *main = new Main();
    main->Show(true);
    return true;
}