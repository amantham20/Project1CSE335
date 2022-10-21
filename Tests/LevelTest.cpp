/**
 * @file LevelTest.cpp
 * @author Ian Valdovinos Granados
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <wx/filename.h>

class LevelTest : public ::testing::Test
{
protected:
    /**
    * Create a path to a place to put temporary files
    */
    wxString TempPath()
    {
        // Create a temporary filename we can use
        auto path = wxFileName::GetTempDir() + L"/aquarium";
        if(!wxFileName::DirExists(path))
        {
            wxFileName::Mkdir(path);
        }

        return path;
    }

};