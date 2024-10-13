#ifndef UNIQUE_DIALOG 
#define UNIQUE_DIALOG

#include <wx/wx.h>
#include <type_traits>

namespace uniquedialog_ID 
{
    constexpr int t_info = 9001;
    constexpr int b_ok = 9002;
    constexpr int b_cancel = 9003;
}

namespace gui
{
    template <typename T> 
    class UniqueDialog : public wxDialog
    {
        private:
            T *info_ptr;

            wxTextCtrl *info_field;
            wxButton *btn_ok, *btn_cancel;

            void close(wxCommandEvent &ev);
            void handleApply(wxCommandEvent &ev);

        public:
            UniqueDialog(wxWindow *parent, std::string title, std::string label, T *_info_ptr);
    };


    template <typename T> 
    UniqueDialog<T>::UniqueDialog(wxWindow *parent, std::string title, std::string label, T *_info_ptr): wxDialog(parent, wxID_ANY, title, wxDefaultPosition, wxDefaultSize) 
    {
        wxBoxSizer *dialog_box = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer *submit_buttons = new wxBoxSizer(wxHORIZONTAL); 

        info_ptr = _info_ptr; 

        info_field = new wxTextCtrl(this, uniquedialog_ID::t_info, label, wxDefaultPosition, wxDefaultSize, 0);
        btn_ok = new wxButton(this, uniquedialog_ID::b_ok, "Ok");
        btn_cancel = new wxButton(this, uniquedialog_ID::b_cancel, "Cancel");

        submit_buttons->Add(btn_ok, 0 , wxALL, 10);
        submit_buttons->Add(btn_cancel, 0, wxALL, 10);

        dialog_box->Add(info_field, 0, wxALL, 10);
        dialog_box->Add(submit_buttons);

        btn_cancel->Bind(wxEVT_BUTTON, &UniqueDialog<T>::close, this);
        btn_ok->Bind(wxEVT_BUTTON, &UniqueDialog<T>::handleApply, this);

        this->SetSizer(dialog_box);
        this->ShowModal();
    }

    template <typename T>
    void UniqueDialog<T>::close(wxCommandEvent &ev) 
    { 
        this -> EndModal(wxID_OK);
    }
}

namespace gui 
{
    template<typename T>
    void UniqueDialog<T>::handleApply(wxCommandEvent &ev)
    {
        std::cout << "\n" << "called generic, bitch" << "\n";

        return;
    }

}

#endif 