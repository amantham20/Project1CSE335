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
    std::shared_ptr<SpartyTracker> visitor = std::make_shared<SpartyTracker>();
    Accept(visitor);
    visitor->ReloadSlingshot(mSlingShot);
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