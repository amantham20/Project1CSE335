/**
 * @file MainFrame.cpp
 * @author Ian Valdovinos Granados, zhiqiang ni, and Aman Dhruva Thamminana
 */

#include "pch.h"
#include "ids.h"
#include "MainFrame.h"
#include "SpartyView.h"

/**
 * Initialize function for the MainFrame
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"SpartyApp", wxDefaultPosition,  wxSize( 1200,700 ));

    auto sizer = new wxBoxSizer( wxVERTICAL );

    mSpartyView = new SpartyView();
    mSpartyView->Initialize(this);

    sizer->Add(mSpartyView,1, wxEXPAND | wxALL );

    // Set the sizer for this frame
    SetSizer( sizer );

    // Layout (place) the child windows.
    Layout();

    auto menuBar = new wxMenuBar( );
    auto fileMenu = new wxMenu();
    auto levelMenu = new wxMenu();
    auto helpMenu = new wxMenu();
    auto viewMenu = new wxMenu();

    menuBar->Append(fileMenu, L"&File");
    menuBar->Append(levelMenu, L"&Level" );
    menuBar->Append(helpMenu, L"&Help");
    menuBar->Append(viewMenu, L"&View");

    fileMenu->Append(wxID_EXIT, "&Exit\tAlt-X", "Quit this program");

    helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");

    levelMenu->Append(IDM_LEVEL0, "&Level 0", "Jump to Level 0");
    levelMenu->Append(IDM_LEVEL1, "&Level 1", "Jump to Level 1");
    levelMenu->Append(IDM_LEVEL2, "&Level 2", "Jump to Level 2");
    levelMenu->Append(IDM_LEVEL3, "&Level 3", "Jump to Level 3");

    viewMenu->Append(IDM_DEBUG, "Debug mode\tF5", "go to debug mode", wxITEM_CHECK);
    SetMenuBar( menuBar );

    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnMenuHelpAbout, this, wxID_ABOUT);
    Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);

    CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
}



/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

/**
 * Show about message handlers
 * @param event
 */
void MainFrame::OnMenuHelpAbout(wxCommandEvent& event)
{
    wxMessageBox(L"Welcome to the Angry Sparty app!\nAuthors: Aman, Ian, Milan, James, Rajmeet",
                 L"About Angry Sparty",
                 wxOK,
                 this);
}

/**
 * Handle a close event. Stop the animation and destroy this window.
 * @param event The Close event
 */
void MainFrame::OnClose(wxCloseEvent& event)
{
    mSpartyView->Stop();
    Destroy();
}