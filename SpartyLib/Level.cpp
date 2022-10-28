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
    mLevelScore = std::make_shared<Score>(0);
}

//void Level::Draw(wxDC *dc)
//{
//    for(auto item : mItems){
//        item->Draw(dc);
//    }
//}
/**
 * Handle drawing the game on the screen including all subsystems.
 * @param graphics Graphics context to draw on
 * @param width Width of the window in pixels
 * @param height Height of the window in pixels
 */
//void Level::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
//{
//    wxBrush background(*wxBLACK);
//    graphics->SetBrush(background);
//    graphics->DrawRectangle(0, 0, width, height);
//
//    graphics->PushState();
//
//    // Get the playing area size in centimeters
//    auto playingAreaSize = redacted;
//    playingAreaSize *= Consts::MtoCM;
//
//    //
//    // Automatic Scaling
//    // We use CM display units instead of meters
//    // because a 1-meter wide line is very wide
//    //
//    auto scaleX = double(height) / double(playingAreaSize.y);
//    auto scaleY = double(width) / double(playingAreaSize.x);
//    mScale = scaleX < scaleY ? scaleX : scaleY;
//    graphics->Scale(mScale, -mScale);
//
//    // Determine the virtual size in cm
//    auto virtualWidth = (double)width / mScale;
//    auto virtualHeight = (double)height / mScale;
//
//    // And the offset to the middle of the screen
//    mXOffset = virtualWidth / 2.0;
//    mYOffset = -(virtualHeight - playingAreaSize.y) / 2.0 - playingAreaSize.y;
//
//    graphics->Translate(mXOffset, mYOffset);
//
//    //
//    // From here we are dealing with centimeter pixels
//    // and Y up being increase values
//    //
//    // INSERT YOUR DRAWING CODE HERE
//
//    graphics->PopState();
//}

//void Level::LoadXMLItems(wxXmlNode *node)
//{
//    std::shared_ptr<Item> item;
//    auto name = node->GetName();
//
//    if(name == L"background")
//    {
//        //item = std::make_shared<Background>(this, filename);
//    }
//    if(name == L"block")
//    {
//        item = std::make_shared<Block>(this);
//    }
//    if (item != nullptr)
//    {
////        mItems.push_back(item);
//        item->XmlLoad(node);
//    }

//}

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

void Level::SetSlingShot(std::shared_ptr<Slingshot> slingshot)
{
    mSlingShot = slingshot;
}

void Level::ReloadSlingshot()
{
    std::shared_ptr<SpartyTracker> visitor = std::make_shared<SpartyTracker>();
    Accept(visitor);
    visitor->ReloadSlingshot(mSlingShot, this);
}

void Level::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    for( auto item : mItems){
        item->OnDraw(graphics);
    }
}

void Level::Accept(std::shared_ptr<ItemVisitor> visitor)
{
    for (auto item : mItems)
    {
        item->Accept(visitor);
    }
}