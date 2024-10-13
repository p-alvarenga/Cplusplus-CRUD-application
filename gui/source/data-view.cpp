#include "../include/data-view.h"

namespace gui
{
    DataView::DataView(wxWindow *win, wxSize size): wxListCtrl(win, wxID_ANY, wxDefaultPosition, size, wxLC_REPORT)
    {
        InsertColumn(0, "ID", wxLIST_FORMAT_CENTER, 80);
        InsertColumn(1, "Name", wxLIST_FORMAT_LEFT, 120);
        InsertColumn(2, "CPF", wxLIST_FORMAT_LEFT, 120);
        InsertColumn(3, "Age", wxLIST_FORMAT_CENTER, 100);

        return;
    }

    void DataView::updateListView(std::vector<data::Person> &p_set)
    {
        DeleteAllItems();

        for (auto i = 0; i < p_set.size(); i++)
        {
            InsertItem(i, std::to_string(p_set[i].getId()));
            SetItem(i, 1, p_set[i].getName());
            SetItem(i, 2, p_set[i].getCpf());
            SetItem(i, 3, std::to_string(p_set[i].getAge()));
        }
    }
}