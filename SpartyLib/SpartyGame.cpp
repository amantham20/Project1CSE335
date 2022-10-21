/**
 * @file SpartyGame.cpp
 * @author Rajmeet Singh Chandok
 *
 */

#include "pch.h"
#include "SpartyGame.h"
#include "Consts.h"
#include "PlayAreaSize.h"
#include "Block.h"
#include "Background.h"
#include "WoodenSlingshot.h"
#include "ScoreDisplay.h"
#include <wx/graphics.h>
using namespace std;


/**
 * constructor
 */
SpartyGame::SpartyGame()
{
    mTotalScore = new Score(0);
    mLevelScore = new Score(0);
    /// TODO remove the next line
//    Level *tLevel = new Level(8, 14.22);
//    std::shared_ptr<Item> tempBackground = std::make_unique<Background>(L"../images/background1.png", tLevel);
//    mItems.push_back(tempBackground);

}


void SpartyGame::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height){
    wxBrush background(*wxBLACK);
    graphics->SetBrush(background);
    graphics->DrawRectangle(0, 0, width, height);

    graphics->PushState();

    // Get the playing area size in centimeters

//    PlayAreaSize playArea;
//    b2Vec2 playingAreaSize = playArea.Temp();
    b2Vec2 playingAreaSize = b2Vec2(14.22,8);
    playingAreaSize *= Consts::MtoCM;

    //
    // Automatic Scaling
    // We use CM display units instead of meters
    // because a 1-meter wide line is very wide
    //
    auto scaleX = double(height) / double(playingAreaSize.y);
    auto scaleY = double(width) / double(playingAreaSize.x);
    mScale = scaleX < scaleY ? scaleX : scaleY;
    graphics->Scale(mScale, -mScale);

    // Determine the virtual size in cm
    auto virtualWidth = (double)width / mScale;
    auto virtualHeight = (double)height / mScale;

    // And the offset to the middle of the screen
    mXOffset = virtualWidth / 2.0;
    mYOffset = -(virtualHeight - playingAreaSize.y) / 2.0 - playingAreaSize.y;

    graphics->Translate(mXOffset, mYOffset);

    //
    // From here we are dealing with centimeter pixels
    // and Y up being increase values
    //
    // INSERT YOUR DRAWING CODE HERE
    // graphics->DrawBitmap(*mBackground, 0, 0);
//    graphics->DrawBitmap(*mBackground,0,0, scaleX, scaleY);
    for( auto item : mItems){
        item->OnDraw(graphics);
    }

    //todo: uncompleted working code don't know put where
    shared_ptr<Item> a = std::make_shared<ScoreDisplay>(mLevels[0], mTotalScore, 10, 10);
    shared_ptr<Item> b = std::make_shared<ScoreDisplay>(mLevels[0], mLevelScore, 1400, 10);
    a->OnDraw(graphics);
    b->OnDraw(graphics);
    graphics->PopState();
}


/**
 * Save the SpartyGame as a .sparty XML file.
 *
 * Open an XML file and stream the aquarium data to it.
 *
 * @param filename The filename of the file to save the aquarium to
 */
void SpartyGame::Save(const wxString &filename)
{
    wxXmlDocument xmlDoc;

    auto root = new wxXmlNode(wxXML_ELEMENT_NODE, L"sparty");
    xmlDoc.SetRoot(root);

    // Iterate over all items and save them
    for (const auto& item : mItems)
    {
        item->XmlSave(root);
    }

    if(!xmlDoc.Save(filename, wxXML_NO_INDENTATION))
    {
        wxMessageBox(L"Write to XML failed");
        return;
    }
}

/**
 * Loads the contents of the xml file into the SpartyGame
 * @param filename
 */
void SpartyGame::Load(const wxString &filename)
{

    // Make sure the given file(s) can be opened
    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Unable to load Level file");
        return;
    }

    // Get the XML document root node
    auto root = xmlDoc.GetRoot();

    //
    // Traverse the children of the root
    // node of the XML document in memory!!!!
    //
    std::shared_ptr<Level> tLevel = std::make_shared<Level>();
    tLevel->Load(root);



    mLevels.push_back(tLevel);

    auto child = root->GetChildren();
    for( ; child; child=child->GetNext())
    {
        auto name = child->GetName();
        if(name == L"items"){

            // Items tag found. LOAD EVERY ITEM IN THE ITEMS TAG
            LoadXMLItems(child, tLevel);

        } else if (name == L"angry")
        {
            // Angry tag found. LOAD EVERY ANGRY SPARTY IN THE ANGRY TAG
            LoadXMLSparties(child);

        }
    }
}

/**
 * Loads every item in the items parent tag
 * @param node
 */
void SpartyGame::LoadXMLItems(wxXmlNode *node, std::shared_ptr<Level> pLevel)
{
    // Get the first item in the items parent tag
    auto child = node->GetChildren();

    // Pointer to the item we are loading
    shared_ptr<Item> item;

    // Iterate over every item inside the items tag
    for( ; child; child=child->GetNext())
    {
        auto name = child->GetName();

        shared_ptr<Item> item;

        if (name == "block")
        {
            item = std::make_shared<Block>(pLevel);
        }
//        else if (name == "poly")
//        {
//
//        }
//        else if (name == "foe")
//        {
//
//        }
//        else if (name == "goalposts")
//        {
//
//        }
//        else if (name == "slingshot")
//        {
//            item = std::make_shared<WoodenSlingshot>(pLevel);
//        }
        else if (name == "background")
        {
//            std::shared_ptr<Item> tempBackground = std::make_shared<Background>(L"../images/background1.png", pLevel);
            item = std::make_shared<Background>(pLevel);
        }

        if (item != nullptr){
            mItems.push_back(item);
            item->XmlLoad(child);
        }



    }
}

/**
 * Loads every angry sparty in the angry parent tag
 * @param node
 */
void SpartyGame::LoadXMLSparties(wxXmlNode *node)
{
    // todo: Implement load function to load the angry sparties

}

void SpartyGame::OnDraw(wxDC *dc)
{

}