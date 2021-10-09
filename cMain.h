//
// Created by Rukshan Perera on 2021-10-02.
//

#ifndef WATCHNEXT_CMAIN_H
#define WATCHNEXT_CMAIN_H

#include "wx/wxprec.h"


#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

class cMain : public wxFrame {

public:
    cMain();
    ~cMain();

public:
    int nFieldWidth = 10;
    int nFieldHeight = 10;
    wxButton **m_pButtons;
    int *nFields = nullptr;
    bool bFirstClick = true;

    void OnButtonClicked(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};


#endif //WATCHNEXT_CMAIN_H
