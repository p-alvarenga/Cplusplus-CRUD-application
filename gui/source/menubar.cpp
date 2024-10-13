#include "../include/menubar.h"

namespace gui
{
    Menubar::Menubar() 
    {
        this->menu_file = new wxMenu();

        menu_file->Append(menubar_id::file_export, "Export Database View \tCtrl+E");
        menu_file->AppendSeparator();
        menu_file->Append(menubar_id::file_about, "About");
    
        this->Append(menu_file, "&File");
    }

    void Menubar::handleMenuItemEvent(wxCommandEvent &ev)
    {
        switch (ev.GetId())
        {
            case menubar_id::file_export:
                wxMessageBox("MySQL Inserted", "File Exporter");
                break;

            case menubar_id::file_about:
                wxMessageBox("This is a organized app", "About");
                break;

            default:
                wxMessageBox("switch on handleMenuItemEvent() got default", "gui::Menubar error");
                break;
        }

        return;
    }

    wxBEGIN_EVENT_TABLE(gui::Menubar, wxMenuBar)
        EVT_MENU(menubar_id::file_export, gui::Menubar::handleMenuItemEvent)
        EVT_MENU(menubar_id::file_about , gui::Menubar::handleMenuItemEvent)
    wxEND_EVENT_TABLE()
}