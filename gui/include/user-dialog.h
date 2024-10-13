#ifndef USER_FRAME_H_
#define USER_FRAME_H_

#include <wx/wx.h>

#include "../../data/include/Person.h"

namespace userdialog_ID
{
    constexpr int t_name   = 1001;
    constexpr int t_cpf    = 1002;
    constexpr int t_age    = 1003;
    constexpr int b_apply  = 1004;
    constexpr int b_cancel = 1005;
}

namespace gui
{
    class UserDialog : public wxDialog
    {
        private:
            wxButton *btn_apply, *btn_cancel;
            wxTextCtrl *txt_name, *txt_cpf, *txt_age;

            data::Person *_person;

            void handleApply(wxCommandEvent &ev);
            void close(wxCommandEvent &ev);

            DECLARE_EVENT_TABLE();        
        
        public:
            UserDialog(wxWindow *parent, std::string title, data::Person *_p);
            void fillPeopleFields(data::Person &p);
    };
}

#endif 