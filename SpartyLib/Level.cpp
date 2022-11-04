/**
 * @file Level.cpp
 * @author Aman Dhruva Thamminana
 */

#include "pch.h"
#include "Level.h"
#include "Consts.h"
#include "SpartyGame.h"
#include "Block.h"
#include "WoodenSlingshot.h"
#include "Background.h"
#include "SpartyTracker.h"
#include "PlayingArea.h"

//class PlayingArea;

/**
 * Level constructor
 * @param spartyGame Game the level is part of
 */
Level::Level(SpartyGame *spartyGame) : mSpartyGame(spartyGame)
{
}

/**
 * Loads the contents of the xml file into the Level
 * @param node Xml node to read from
 */
void Level::Load(wxXmlNode *node)
{
    node->GetAttribute(L"height", L"0").ToDouble(&mHeight);
    node->GetAttribute(L"width", L"0").ToDouble(&mWidth);
}

/**
 * Add an item to the level
 * @param item New item to add
 */
void Level::Add(std::shared_ptr<Item> item)
{
    item->SetLocation(Consts::InitialX, Consts::InitialY);   // [210, 200]    200
    mItems.push_back(item);
}

/**
 * Sets the slingshot for this level, this allows fast access to the level's slingshot instead of having to
 * iterate over its mItems.
 * @param slingshot Slingshot to set to this level
 */
void Level::SetSlingShot(std::shared_ptr<Slingshot> slingshot)
{
    mSlingShot = slingshot;
}

/**
 * Reload the slingshot with an Angry sparty in this level
 */
void Level::ReloadSlingshot()
{
    mSpartyTracker = std::make_shared<SpartyTracker>();
    Accept(mSpartyTracker);
    mSpartyTracker->ReloadSlingshot(mSlingShot);
}

/**
 * Draws this level on screen
 * @param graphics Graphics context to be used
 */
void Level::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    for( auto item : mItems){
        item->OnDraw(graphics);
    }
}

/**
 * Accept an visitor that visit ever item in this level
 * @param visitor Visitor that will visit items in this level.
 */
void Level::Accept(std::shared_ptr<ItemVisitor> visitor)
{
    for (auto item : mItems)
    {
        item->Accept(visitor);
    }
}

///**
// * Checks if an item in the level has been clicked
// * @param x x coordinate to test
// * @param y y coordinate to test
// */
//Angry* Level::HitTest(int x, int y)
//{
//    return mSpartyTracker->HitTest(x, y);
//}

/**
 * Draws the right slingshot rubber band portion in this level
 * @param graphics graphics context used
 */
void Level::DrawRightSlingshotRubberBand(std::shared_ptr<wxGraphicsContext> graphics)
{
    mSlingShot->DrawRightRubberBand(graphics);
}

/**
 * Draws the front of the slingshot in this level
 * @param graphics graphics context used
 */
void Level::DrawSlingshotFront(std::shared_ptr<wxGraphicsContext> graphics)
{
    mSlingShot->DrawFront(graphics);
}

/**
 * Gets the position of the loading spot of the slingshot in this level
 * @return Position of the loading spot
 */
b2Vec2 Level::GetSlingshotLoadingPosition()
{
    return b2Vec2(mSlingShot->GetXLoadSpot(), mSlingShot->GetYLoadSpot());
}

int Level::GetRubberBandLength()
{
    return mSlingShot->GetRubberBandLength();
}

void Level::AddItemDepp(std::shared_ptr<PlayingArea> playingArea){
    for(auto item : mItems)
    {
        playingArea->Add(item);
    }
}

/**
 * Clears the loaded sparty of the slingshot in this level
 */
void Level::ClearLoadedSparty()
{
    mSlingShot->ClearLoadedAngrySparty();
}

std::shared_ptr<Slingshot> Level::GetSlingshot()
{
    return mSlingShot;
}


void Level::ResetItemXY()
{
    for (auto item : mItems) {
        item->ResetXY();
    }
}