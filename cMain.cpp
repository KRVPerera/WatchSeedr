//
// Created by Rukshan Perera on 2021-10-02.
//

#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
//                EVT_BUTTON(10001, cMain::OnButtonClicked)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "WatchNext Seedr Client",
                         wxPoint(10, 50),
                         wxSize(800, 600)) {

    m_pButtons = new wxButton *[nFieldWidth * nFieldHeight];
    wxGridSizer *grid = new wxGridSizer(nFieldWidth, nFieldHeight, 0, 0);

    nFields = new int[nFieldHeight * nFieldWidth];

    wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

    for (int x = 0; x < nFieldHeight; ++x) {
        for (int y = 0; y < nFieldHeight; ++y) {
            m_pButtons[y * nFieldWidth + x] = new wxButton(this, 10000 + (y * nFieldWidth + x));
            m_pButtons[y * nFieldWidth + x]->SetFont(font);
            m_pButtons[y * nFieldWidth + x]->SetAutoLayout(true);
            grid->Add(m_pButtons[y * nFieldWidth + x], 1, wxEXPAND | wxALL);

            m_pButtons[y * nFieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnButtonClicked, this);

            nFields[y * nFieldWidth + x] = 0;
        }
    }

    this->SetSizer(grid);
    grid->Layout();
}

cMain::~cMain() {
    delete[] m_pButtons;
}

void cMain::OnButtonClicked(wxCommandEvent &event) {

    int x = (event.GetId() - 10000) % nFieldWidth;
    int y = (event.GetId() - 10000) / nFieldWidth;

    if (bFirstClick) {
        int mines = 30;

        while (mines) {
            int rx = rand() % nFieldWidth;
            int ry = rand() % nFieldHeight;
            if (nFields[ry * nFieldWidth + rx] == 0 && rx != x && ry != y) {
                nFields[ry * nFieldWidth + rx] = -1;
                --mines;
            }
        }

        bFirstClick = false;
    }

    m_pButtons[y * nFieldWidth + x]->Enable(false);

    if (nFields[y * nFieldWidth + x] == -1) {
        wxMessageBox("Oooops! - Game Over :(");

        // reset game
        bFirstClick = true;
        for (int x = 0; x < nFieldHeight; ++x) {
            for (int y = 0; y < nFieldHeight; ++y) {
                nFields[y * nFieldWidth + x] = 0;
                m_pButtons[y * nFieldWidth + x]->SetLabel("");
                m_pButtons[y * nFieldWidth + x]->Enable(true);
            }
        }
        bFirstClick = false;
    } else {
        int mine_count = 0;
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {

                if (x + i >= 0 && x+1 < nFieldWidth && y+j >= 0 && y + j < nFieldHeight) {
                    if (nFields[(y+j)*nFieldWidth + (x +i )] == -1) {
                        ++mine_count;
                    }
                }
            }
        }

        if (mine_count > 0) {
            m_pButtons[y*nFieldWidth + x]->SetLabel(std::to_string(mine_count));
        }
    }

    event.Skip();
}

