/**
 * @file SpartyApp.cpp
 * @author Ian Valdovinos Granados, and  Aman Dhruva Thamminana
 */

#include "pch.h"
#include "SpartyApp.h"
#include "MainFrame.h"

/**
 * Initializes the application and creates the main frame
 * @return true on success otherwise false
 */
bool SpartyApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    // Add image type handlers
    wxInitAllImageHandlers();


    auto frame = new MainFrame();

    frame->Initialize();
    frame->Show(true);


    return true;

}
