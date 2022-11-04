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
#include <stdio.h>

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

TEST_F(SpartyGameTest, Construct)
{
    SpartyGame game;
}

TEST_F(SpartyGameTest, LoadLevel1)
{
    // Create an instance of SpartyGame
    SpartyGame game;

    // Level filenames
    wxString levelZeroFilename = L"../levels/level0.xml";
    wxString levelOneFilename = L"../levels/level1.xml";

    game.Load(levelZeroFilename);
    game.Load(levelOneFilename);
    game.SetLevel(1);
    game.Reset();
    int numberOfItems = game.GetNumberOfItems();

    // Level 1 has 1 background, 1 slingshot, 14 blocks, 1 polygon, 2 foes, and 3 angry Sparties. A total of 22 items.
    ASSERT_EQ(22, numberOfItems);
}

TEST_F(SpartyGameTest, LoadLevel2)
{
    // Create an instance of SpartyGame
    SpartyGame game;

    // Level filenames
    wxString levelZeroFilename = L"../levels/level0.xml";
    wxString levelOneFilename = L"../levels/level1.xml";
    wxString levelTwoFilename = L"../levels/level2.xml";

    game.Load(levelZeroFilename);
    game.Load(levelOneFilename);
    game.Load(levelTwoFilename);
    game.SetLevel(2);
    game.Reset();

    int numberOfItems = game.GetNumberOfItems();

    // Level 1 has 1 background, 1 goalpost, 17 blocks, 1 polygon, 4 foes, and 6 Sparties. A total of 24 items.
    ASSERT_EQ(30, numberOfItems);
}

