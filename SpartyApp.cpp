/**
 * @file SpartyApp.cpp
 * @author Ian Valdovinos Granados
 */

#include "pch.h"
#include "SpartyApp.h"
#include "MainFrame.h"


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
