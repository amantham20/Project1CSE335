/**
 * @file SpartyGame.cpp
 * @author Rajmeet Singh Chandok, Milan Mihailovic, zhiqiang ni
 *
 */

#include "pch.h"
#include "SpartyGame.h"
#include "Consts.h"
#include "Block.h"
#include "Background.h"
#include "WoodenSlingshot.h"
#include "Goalpost.h"
#include "Poly.h"
#include "Foe.h"
#include "HelmetSparty.h"
#include "GruffSparty.h"
#include "SpartyTracker.h"
#include "PlayingArea.h"
#include "DebugDraw.h"
#include "FoeTracker.h"

#include <wx/graphics.h>

using namespace std;

/**
 * Constructor
 */
 ///TODO Change where this is! the mPhysicsEngine should be in the level class
SpartyGame::SpartyGame() //:mPhysics(b2Vec2(14.22,8))
{
//    mPhysics = make_shared<Physics>(b2Vec2(14.22*Consts::MtoCM,8*Consts::MtoCM));

    mPictureCache = std::make_shared<PictureManager>();


    /// TODO remove the next line
//    Level *tLevel = new Level(8, 14.22);
//    std::shared_ptr<Item> tempBackground = std::make_unique<Background>(L"../images/background1.png", tLevel);
//    mItems.push_back(tempBackground);

}

/**
 * Draws the SpartyGame
 * @param graphics Graphics context used to draw Angry Sparty game on screen
 * @param width Width of the game
 * @param height Height of the game
 */
void SpartyGame::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height){
    wxBrush background(*wxBLACK);
    graphics->SetBrush(background);
    graphics->DrawRectangle(0, 0, width, height);

    graphics->PushState();

    // Get the playing area size in centimeters
    b2Vec2 playingAreaSize = mLevels[mCurrentLevel]->GetPlayAreaSize();
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

    // Draw current level
    //mLevels[mCurrentLevel]->OnDraw(graphics);
    Update(graphics);
    //todo: delete
    //shared_ptr<Item> a = std::make_shared<ScoreDisplay>(mLevels[0], mTotalScore, 10, 10);
    //shared_ptr<Item> b = std::make_shared<ScoreDisplay>(mLevels[0], mLevels[0]->GetScore(), 1400, 10);
    //a->OnDraw(graphics);
    //->OnDraw(graphics);

    //todo: uncompleted working code don't know put where
//    shared_ptr<Item> a = std::make_shared<ScoreDisplay>(mLevels[0], mTotalScore, 10, 10);
//    shared_ptr<Item> b = std::make_shared<ScoreDisplay>(mLevels[0], mLevels[0]->GetScore(), 1400, 10);
//    a->OnDraw(graphics);
//    b->OnDraw(graphics);

    if(mDebug){
        DebugOnDraw(graphics);
    }

    graphics->PopState();

}

/**
 * Loads the contents of the xml file into the SpartyGame
 * @param filename Filename to load contents from
 */
void SpartyGame::Load(const wxString &filename)
{
    mId = 0;

    // Make sure the given file(s) can be opened
    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Unable to load Level file");
        return;
    }

    // Get the XML document root node
    auto root = xmlDoc.GetRoot();

    // Create a new instance of a level and push it to the SpartyGame.mLevels vector
    std::shared_ptr<Level> tLevel = std::make_shared<Level>(this);
    tLevel->Load(root);
    mLevels.push_back(tLevel);

    //
    // Traverse the children of the root
    // node of the XML document in memory!!!!
    //
    auto child = root->GetChildren();
    for( ; child; child=child->GetNext())
    {
        auto name = child->GetName();
        if(name == L"items")
        {
            // Items tag found. LOAD EVERY ITEM IN THE ITEMS TAG
            LoadXMLItems(child, tLevel);
        }
        else if (name == L"angry")
        {
            // Angry tag found. LOAD EVERY ANGRY SPARTY IN THE ANGRY TAG
            LoadXMLSparties(child, tLevel);
        }
    }

    // Now that all the xml data has been loaded. Load the angry sparty into the slingshot
//    mLevels.back()->ReloadSlingshot();


}

/**
 * Loads every item in the items parent tag
 * @param node Node to start reading xml doc from
 * @param pLevel Level the xml document belongs to
 */
void SpartyGame::LoadXMLItems(wxXmlNode *node, std::shared_ptr<Level> pLevel)
{
    // Get the first item in the items parent tag
    auto child = node->GetChildren();

    // Iterate over every item inside the items tag
    for( ; child; child=child->GetNext())
    {
        // Get tag name to create the correct instance of the object defined by the tag
        auto name = child->GetName();

        // Create a shared pointer to an item and give it the right object type depending on the tag name
        shared_ptr<Item> item;
        if (name == "block")
        {
            item = std::make_shared<Block>(pLevel);
        }
        else if (name == "poly")
        {
            item = std::make_shared<Poly>(pLevel);
        }
        else if (name == "foe")
        {
            item = std::make_shared<Foe>(pLevel);
        }
        else if (name == "goalposts")
        {
            item = std::make_shared<Goalpost>(pLevel);
            pLevel->SetSlingShot(std::static_pointer_cast<Slingshot>(item));
        }
        else if (name == "slingshot")
        {
            item = std::make_shared<WoodenSlingshot>(pLevel);
            pLevel->SetSlingShot(std::static_pointer_cast<Slingshot>(item));
        }
        else if (name == "background")
        {
            item = std::make_shared<Background>(pLevel);
        }

        // If the item is not a null pointer, add it to the level mItems vector and load the item's attributes based defined by the xml doc
        if (item != nullptr)
        {
            // Add item to the Level
            pLevel->Add(item);

            // Cache the picture
            item->setCache(mPictureCache);

            // Load item's attributes defined by xml document
            item->XmlLoad(child);


            item->SetId(mId);
            mId += 1;
        }
    }
}

/**
 * Loads every angry sparty in the angry parent tag
 * @param node Node to start reading contents from
 */
void SpartyGame::LoadXMLSparties(wxXmlNode *node, std::shared_ptr<Level> pLevel)
{
    // Get location where the sparties line should start
    double x_start;
    double y_start;
    node->GetAttribute(L"x", L"0").ToDouble(&x_start);
    node->GetAttribute(L"y", L"0").ToDouble(&y_start);

    // Current location based on the offset
    double x_current = x_start;

    // Get spacing between angry sparties
    double spacing;
    node->GetAttribute(L"spacing", "0.6").ToDouble(&spacing);

    // Get the first item in the items parent tag
    auto child = node->GetChildren();

    // Pointer to the item we are loading
    shared_ptr<Item> item;

    // Iterate over the tags within the angry tag
    for( ; child; child=child->GetNext())
    {
        auto name = child->GetName();

        // Create right instance of an angry sparty depending on the tag name
        shared_ptr<Item> item;
        if (name == "gruff-sparty")
        {
            item = std::make_shared<GruffSparty>(pLevel);

        }
        else if (name == "helmet-sparty")
        {
            item = std::make_shared<HelmetSparty>(pLevel);

        }

        if (item != nullptr)
        {
            // Add angry sparty to its level
            pLevel->Add(item);

            // Cache the picture
            item->setCache(mPictureCache);

            // Set image location
            item->SetLocation(x_current, y_start);
            x_current += spacing;

            // Load item data based on xml file
            item->XmlLoad(child);

            item->SetId(mId);
            mId += 1;
        }
    }
}

void SpartyGame::Reset()
{
    mPlayingArea.reset();
    double score = 0;
    if(mTotalScore != NULL)
    {
        score = mTotalScore->GetScore();
    }
    mTotalScore = std::make_shared<Score>(mLevels.at(mCurrentLevel), score, 10 ,10);
    mPlayingArea = std::make_shared<PlayingArea>(mLevels.at(mCurrentLevel), mTotalScore);
    mLevels[mCurrentLevel]->AddItemDepp(mPlayingArea);
    mPlayingArea->SetSlingShot(mLevels[mCurrentLevel]->GetSlingshot());
    mPlayingArea->ReloadSlingshot();
    mPlayingArea->InstallPhysics();
}

//todo delete? should done in playingarea
void SpartyGame::DebugOnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mPlayingArea->DebugOnDraw(graphics);
}

void SpartyGame::Update(double frameDuration)
{
    if(mPlayingArea != NULL)
    {
        mPlayingArea->Update(frameDuration);
        mPlayingArea->SetLevel(mCurrentLevel);
        mPlayingArea->SetEnd(mLevelEnd);
    }
}

void SpartyGame::Update(std::shared_ptr<wxGraphicsContext> graphics)
{
    if(mPlayingArea == NULL)
    {
        Reset();
    }
//    mPlayingArea->SetSlingShot(mLevels[mCurrentLevel]->GetSlingshot());
//    mPlayingArea->ReloadSlingshot();
    mPlayingArea->Draw(graphics);

    std::shared_ptr<FoeTracker> visitor = std::make_shared<FoeTracker>();
    mPlayingArea->Accept(visitor);
    if(visitor->GetNumberFoe() <= 0)
    {
        mLevelEnd = true;
        mCurrentLevel++;
        if (mCurrentLevel >= 4){
            mCurrentLevel = 0;
        }
        Reset();
    }
    if(visitor->GetNumberAngry() <= 0){
        Reset();
    }
}

/**
 * Runs a hit test on the current level to determine if an item has been clicked on
 * @param x x coordinate
 * @param y y coordinate
 * @return A pointer to an item that has been clicked on. Nullptr if no item has been clicked on.
 */
Angry* SpartyGame::HitTest(int x, int y)
{
    // Return the current level's hit test
//    return mLevels[mCurrentLevel]->HitTest(x, y);
    return mPlayingArea->HitTest(x, y);
}


/**
 * Gets the position of the loading spot of the slingshot in the current level
 * @return Position of the loading spot
 */
b2Vec2 SpartyGame::GetSlingshotLoadingPosition()
{
    return mLevels[mCurrentLevel]->GetSlingshotLoadingPosition();
}

int SpartyGame::GetRubberBandLength()
{
    return mLevels[mCurrentLevel]->GetRubberBandLength();
}

void SpartyGame::ClearLoadedSparty()
{
    mLevels[mCurrentLevel]->ClearLoadedSparty();
}