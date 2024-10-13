#ifndef DATA_VIEW_H_
#define DATA_VIEW_H_

#include <wx/wx.h>
#include <wx/listctrl.h>

#include "../../data/include/Person.h"

namespace gui
{
    class DataView : public wxListCtrl
    {   
        private:  

        public:
            DataView(wxWindow *win, wxSize size);
            void updateListView(std::vector<data::Person> &p_set);
    };
}

#endif