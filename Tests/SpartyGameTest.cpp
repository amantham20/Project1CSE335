/**
 * @file SpartyGameTest.cpp
 * @author Ian Valdovinos Granados
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <wx/filename.h>
#include <string>
#include <fstream>

using namespace std;

class SpartyGameTest : public ::testing::Test
{
protected:
    /**
    * Create a path to a place to put temporary files
    */
    wxString TempPath()
    {
        // Create a temporary filename we can use
        auto path = wxFileName::GetTempDir() + L"/spartygame";
        if(!wxFileName::DirExists(path))
        {
            wxFileName::Mkdir(path);
        }

        return path;
    }

    /**
    * Read a file into a wstring and return it.
    * @param filename Name of the file to read
    * @return File contents
    */
    wstring ReadFile(const wxString &filename)
    {
        ifstream t(filename.ToStdString());
        wstring str((istreambuf_iterator<char>(t)),
                istreambuf_iterator<char>());

        return str;
    }

};

TEST_F(SpartyGameTest, Load)
{

}


