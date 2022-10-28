/**
 * @file SpartyGame.cpp
 * @author Rajmeet Singh Chandok, Milan Mihailovic
 *
 */

#include "pch.h"
#include "SpartyGame.h"
#include "Consts.h"
#include "Block.h"
#include "Background.h"
#include "WoodenSlingshot.h"
#include "Goalpost.h"
#include "ScoreDisplay.h"
#include "Poly.h"
#include "Foe.h"
#include "HelmetSparty.h"
#include "GruffSparty.h"
#include "SpartyTracker.h"
#include "sstream"
#include "DebugDraw.h"

#include <wx/graphics.h>

using namespace std;


/**
 * Constructor
 */
 ///TODO Change where this is! the mPhysicsEngine should be in the level class
SpartyGame::SpartyGame() :mPhysics(b2Vec2(14.22,8))
{
    mTotalScore = std::make_shared<Score>(0);

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

//    PlayAreaSize playArea;
//    b2Vec2 playingAreaSize = playArea.Temp();
//    b2Vec2 playingAreaSize = b2Vec2(14.22,8);

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
    // INSERT YOUR DRAWING CODE HERE

    mLevels[mCurrentLevel]->Draw(graphics);
    // graphics->DrawBitmap(*mBackground, 0, 0);
//    graphics->DrawBitmap(*mBackground,0,0, scaleX, scaleY);
//    for( auto item : mItems){
//        if(item->GetLevel() == mLevels[mCurrentLevel]){
//            item->OnDraw(graphics);
//        }
   // }

    //todo: uncompleted working code don't know put where
//    shared_ptr<Item> a = std::make_shared<ScoreDisplay>(mLevels[0], mTotalScore, 10, 10);
//    shared_ptr<Item> b = std::make_shared<ScoreDisplay>(mLevels[0], mLevels[0]->GetScore(), 1400, 10);
//    a->OnDraw(graphics);
//    b->OnDraw(graphics);
//    graphics->PopState();
}


/**
 * Loads the contents of the xml file into the SpartyGame
 * @param filename Filename to load contents from
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
    std::shared_ptr<Level> tLevel = std::make_shared<Level>(this, mPictureCache);

    tLevel->Load(root);
    mLevels.push_back(tLevel);
}

void SpartyGame::Reset()
{
    //mItems.clear();
}

void SpartyGame::Accept(ItemVisitor* visitor)
{
//    for (auto item : mItems)
//    {
//        item->Accept(visitor);
//    }
}

void SpartyGame::DebugOnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    // Draw the background
    // Draw the items

    DebugDraw debugDraw(graphics);
    debugDraw.SetFlags(b2Draw::e_shapeBit | b2Draw::e_centerOfMassBit);
    mPhysics.GetWorld()->SetDebugDraw(&debugDraw);
    mPhysics.GetWorld()->DebugDraw();

}
