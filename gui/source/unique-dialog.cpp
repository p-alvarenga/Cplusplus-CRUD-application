#include "../include/unique-dialog.h"

namespace gui
{
    template<>
    void UniqueDialog<int>::handleApply(wxCommandEvent &ev)
    {
        int i_info_buf; 

        if (info_field->GetValue().ToInt(&i_info_buf)) 
        { 
            *info_ptr = i_info_buf;

            this -> EndModal(wxID_OK); 
            return;
        }
        else 
        {
            wxMessageBox("Must be a number!", "Error");
        }

        return;
    }
}