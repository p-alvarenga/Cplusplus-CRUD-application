#include "../include/main-frame.h"

namespace gui 
{
    MainFrame::MainFrame(std::string _title): wxFrame(NULL, wxID_ANY, _title)
    {
        this->SetMenuBar(new Menubar());
        configureControlButtons();

        screen = new wxBoxSizer(wxHORIZONTAL);
        data_view = new gui::DataView(this, wxSize(-1, 600));

        p_set = dal.getAll();
        data_view->updateListView(p_set);

        screen->Add(user_options_container, 0, wxALL, 0);
        screen->AddSpacer(30);
        screen->Add(data_view, 0, wxALL, 5);

        SetSizer(screen);
    }
    
    void MainFrame::configureControlButtons()
    {
        user_options_container = new wxBoxSizer(wxVERTICAL);
        
        btn_defsize = wxSize(200, -1);


        btn_add_person = new wxButton(this, controls_id::add, _T("Add Person"), wxDefaultPosition, btn_defsize, 0);
        btn_remove_person = new wxButton(this, controls_id::remove, _T("Remove Person"), wxDefaultPosition, btn_defsize    , 0);
        btn_update_person = new wxButton(this, controls_id::update, _T("Update Person"), wxDefaultPosition, btn_defsize, 0);                
        btn_search = new wxButton(this, controls_id::search, _T("Search Person"), wxDefaultPosition, btn_defsize, 0);
        btn_refresh = new wxButton(this, controls_id::refresh, _T("Refresh Data"), wxDefaultPosition, btn_defsize, 0);

        user_options_container->Add(btn_add_person, 0, wxALL, 5);
        user_options_container->Add(btn_remove_person, 0, wxALL, 5);
        user_options_container->Add(btn_update_person, 0, wxALL, 5);
        user_options_container->Add(btn_search, 0, wxALL, 5);
        user_options_container->Add(btn_refresh, 0, wxALL, 5);

        return;
    }

    void MainFrame::handleButtonsControl(wxCommandEvent &ev)
    {        
        switch (ev.GetId())
        {
            case controls_id::update:
                wxMessageBox("Update", "Controls");
                break;
            
            case controls_id::search:
                wxMessageBox("Search", "Controls");
                break;

            case controls_id::refresh:
                p_set = dal.getAll();
                data_view->updateListView(p_set);

            default: 
                break;
        }

        return;
    }

    void MainFrame::buttonAddPerson(wxCommandEvent &ev)
    {
        data::Person add_p;

        gui::UserDialog user_dialog(this, "Add User", &add_p);
        user_dialog.ShowModal();

        if (add_p.getId() != -1)
        {
            dal.addPerson(add_p);
        }
    
        return;
    }

    void MainFrame::buttonRemovePerson(wxCommandEvent &ev)
    {
        int *id_ptr = new int(-1);
        UniqueDialog<int> *id_dialog = new UniqueDialog<int>(this, "Remove Person", "", id_ptr);

        if (*id_ptr != -1)
        {
            dal.deletePersonById(*id_ptr);
        }

        delete id_ptr;

        return;
    }

    void MainFrame::buttonUpdatePerson(wxCommandEvent &ev)
    {
        int *id_ptr = new int(-1);
        
        data::Person *p = new data::Person();
        data::Person p_copy = *p;


        UniqueDialog<int> id_dialog(this, "Update Person", "", id_ptr);

        if (*id_ptr == -1)
        {
            wxMessageBox("Error: Person ID does not exist");
            return;
        }

        *p = dal.getPersonById(*id_ptr);
        
        p_copy = *p;

        UserDialog user_dialog(this, "Update Person Information", p);
        user_dialog.fillPeopleFields(*p);
        user_dialog.ShowModal();

        p->setId(*id_ptr);
        
        if (p_copy != *p)
        {
            if (dal.updatePerson(*p) != 200)
                wxMessageBox("error updating person");
            else
                wxMessageBox("Updated Person Successfully");
        }

        delete p;
        delete id_ptr;

        return;
    }

    BEGIN_EVENT_TABLE(MainFrame, wxFrame)
        EVT_BUTTON(controls_id::add, MainFrame::buttonAddPerson)
        EVT_BUTTON(controls_id::remove, MainFrame::buttonRemovePerson)
        EVT_BUTTON(controls_id::update, MainFrame::buttonUpdatePerson)
        EVT_BUTTON(controls_id::search, MainFrame::handleButtonsControl)
        EVT_BUTTON(controls_id::refresh, MainFrame::handleButtonsControl)
    END_EVENT_TABLE()
}