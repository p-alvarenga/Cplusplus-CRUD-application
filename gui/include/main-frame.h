#ifndef MAIN_FRAME_H_
#define MAIN_FRAME_H_

#include <wx/listctrl.h>

#include "../../data/include/DAL.h"

#include "./menubar.h"
#include "./data-view.h"
#include "./user-dialog.h"
#include "./unique-dialog.h"


namespace controls_id
{
    constexpr int add    = 201;
    constexpr int remove = 202;
    constexpr int update = 203;
    constexpr int search = 204;
    constexpr int refresh = 200;
}

namespace gui
{
    class MainFrame : public wxFrame
    {
        private:    
            data::db::DAL dal;

           
            std::vector<data::Person> p_set;

            gui::DataView *data_view;
            wxBoxSizer *user_options_container, *screen;
            wxButton *btn_add_person, *btn_remove_person, *btn_update_person, *btn_search, *btn_refresh;
            
            wxSize btn_defsize;

            void handleButtonsControl(wxCommandEvent &ev);
            void buttonAddPerson(wxCommandEvent &ev);
            void buttonRemovePerson(wxCommandEvent &ev);
            void buttonUpdatePerson(wxCommandEvent &ev);

            void configureControlButtons();

            DECLARE_EVENT_TABLE();

        public:
            MainFrame(std::string _title);
    };
}

#endif