#include "../include/user-dialog.h"

namespace gui
{
    UserDialog::UserDialog(wxWindow *parent, std::string title, data::Person *_p): wxDialog(parent, wxID_ANY, title, wxDefaultPosition, wxDefaultSize)
    {
        _person = _p;   

        btn_apply = new wxButton(this, userdialog_ID::b_apply, _T("Apply"), wxDefaultPosition, wxDefaultSize, 0);
        btn_cancel = new wxButton(this, userdialog_ID::b_cancel, _T("Cancel"), wxDefaultPosition, wxDefaultSize, 0);

        txt_name = new wxTextCtrl(this, userdialog_ID::t_name, _T("name"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER , wxDefaultValidator, wxTextCtrlNameStr);
        txt_cpf = new wxTextCtrl(this, userdialog_ID::t_name, _T("cpf"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER , wxDefaultValidator, wxTextCtrlNameStr);
        txt_age = new wxTextCtrl(this, userdialog_ID::t_name, _T("age"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER , wxDefaultValidator, wxTextCtrlNameStr);

        wxBoxSizer *btn_box = new wxBoxSizer(wxHORIZONTAL);
        wxBoxSizer *form_box = new wxBoxSizer(wxVERTICAL);

        btn_box->Add(btn_apply, 0, wxALL, 0);
        btn_box->AddSpacer(8);
        btn_box->Add(btn_cancel, 0, wxALL, 0);

        form_box->AddSpacer(10);
        form_box->Add(txt_name, 0, wxALL, 0);
        form_box->AddSpacer(10);
        form_box->Add(txt_cpf, 0, wxALL, 0);
        form_box->AddSpacer(10);
        form_box->Add(txt_age, 0, wxALL, 0);
        form_box->AddSpacer(15);

        form_box->Add(btn_box);

        this -> SetSizer(form_box);
    }

    void UserDialog::handleApply(wxCommandEvent &ev)
    {
        int age_verify_buff = 0;

        if (!txt_age->GetValue().ToInt(&age_verify_buff)) 
        { 
            _person->setId(-1);
            wxMessageBox("Age must be a number", "Add User - error");

            return; 
        }


        _person->setPerson(0, 
            txt_name->GetValue().ToStdString(), 
            txt_cpf->GetValue().ToStdString(), 
            age_verify_buff
        );

        this -> EndModal(wxID_OK);

        return;
    }

    void UserDialog::fillPeopleFields(data::Person &p)
    {
        txt_name->SetValue(p.getName());
        txt_cpf->SetValue(p.getCpf());
        txt_age->SetValue(std::to_string(p.getAge()));
    
        return;
    }

    void UserDialog::close(wxCommandEvent &ev) { this -> EndModal(wxID_OK); }

    BEGIN_EVENT_TABLE(UserDialog, wxDialog)
        EVT_BUTTON(userdialog_ID::b_cancel, UserDialog::close)
        EVT_BUTTON(userdialog_ID::b_apply, UserDialog::handleApply)
    END_EVENT_TABLE()
}