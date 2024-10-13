#ifndef MENUBAR_H_
#define MENUBAR_H_

#include <wx/wx.h>
#include <iostream> 

namespace menubar_id 
{
    constexpr int file_export = 121;
    constexpr int file_about = 122;
}

namespace gui 
{
    class Menubar : public wxMenuBar
    {
        private:
            wxMenu *menu_file;
            void handleMenuItemEvent(wxCommandEvent &ev);
            
            wxDECLARE_EVENT_TABLE();
        public:
            Menubar();
    };
}

#endif