/**
 * @file SpartyGameTest.cpp
 * @author Ian Valdovinos Granados
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <wx/filename.h>
#include <string>
#include <fstream>
#include <SpartyGame.h>
#include "stdio.h"

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

TEST_F(SpartyGameTest, LoadLevel1)
{
    // Create an instance of SpartyGame
    SpartyGame game;

    // Level filenames
    wxString levelOneFilename = L"../levels/level1.xml";

    game.Load(levelOneFilename);
    int numberOfItems = game.GetNumberOfItems();

    // Level 1 has 1 background, 1 slingshot, 14 blocks, 1 polygon, and 2 foes. A total of 19 items.
//    ASSERT_EQ(19, numberOfItems);
    ASSERT_EQ(17, numberOfItems);   // This is testing the number of items minus the number of foes for the Project Checkpoint
}

TEST_F(SpartyGameTest, LoadLevel2)
{
    // Create an instance of SpartyGame
    SpartyGame game;

    // Level filenames
    wxString levelTwoFilename = L"../levels/level2.xml";

    game.Load(levelTwoFilename);
    int numberOfItems = game.GetNumberOfItems();

    // Level 1 has 1 background, 1 goalpost, 17 blocks, 1 polygon, and 4 foes. A total of 24 items.
//    ASSERT_EQ(24, numberOfItems);
    ASSERT_EQ(20, numberOfItems);   // This is testing the number of items minus the number of foes for the Project Checkpoint
}

