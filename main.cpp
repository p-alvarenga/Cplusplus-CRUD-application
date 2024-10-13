#include <wx/wx.h>
#include <iostream>
#include <memory>
#include <vector>

#include "./data/include/Person.h"
#include "./gui/include/main-frame.h"

class App : public wxApp
{
    public:
        virtual bool OnInit()
        {
            gui::MainFrame *main_frame = new gui::MainFrame("pedro");
            main_frame->Show(true);
        
            return true;
        }
};

wxIMPLEMENT_APP(App);