/**
 * @file SpartyApp.cpp
 * @author Ian Valdovinos Granados
 */

#include "pch.h"
#include "SpartyApp.h"


bool SpartyApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    // Add image type handlers
    wxInitAllImageHandlers();


    return true;

}
