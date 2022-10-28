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
#include "GruffSparty.h"
#include "HelmetSparty.h"
#include "Poly.h"
#include "Foe.h"
#include "Goalpost.h"

/**
 * Level constructor
 * @param spartyGame Game the level is part of
 */
Level::Level(SpartyGame *spartyGame, std::shared_ptr<PictureManager> pictureManager) : mSpartyGame(spartyGame)
{
    mLevelScore = std::make_shared<Score>(0);
    mPictureCache = pictureManager;
}

void Level::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    for(auto item : mItems){
        item->OnDraw(graphics);
    }
}
/**
 * Handle drawing the game on the screen including all subsystems.
 * @param graphics Graphics context to draw on
 * @param width Width of the window in pixels
 * @param height Height of the window in pixels
 */


/**
 * Loads the contents of the xml file into the Level
 * @param node Xml node to read from
 */
void Level::Load(wxXmlNode *node)
{
    auto child = node->GetChildren();
    for( ; child; child=child->GetNext())
    {
        auto name = child->GetName();
        if(name == L"items")
        {
            // Items tag found. LOAD EVERY ITEM IN THE ITEMS TAG
            LoadXMLItems(child);
        }
        else if (name == L"angry")
        {
            // Angry tag found. LOAD EVERY ANGRY SPARTY IN THE ANGRY TAG
            LoadXMLSparties(child);
        }
    }

    node->GetAttribute(L"height", L"0").ToDouble(&mHeight);
    node->GetAttribute(L"width", L"0").ToDouble(&mWidth);

}
/**
 * Loads every angry sparty in the angry parent tag
 * @param node Node to start reading contents from
 */
void Level::LoadXMLSparties(wxXmlNode *node)
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

    // Iterate over the tags within the angry tag
    for( ; child; child=child->GetNext())
    {
        auto name = child->GetName();

        std::shared_ptr<Item> item;

        if (name == L"gruff-sparty")
        {
            item = std::make_shared<GruffSparty>(this);

        } else if (name == L"helmet-sparty")
        {
            item = std::make_shared<HelmetSparty>(this);

        }

        if (item != nullptr)
        {
            mItems.push_back(item);

            item->setCache(mPictureCache);

            // Set image location
            item->SetLocation(x_current, y_start);
            x_current += spacing;

            item->XmlLoad(child);
        }

    }
}

/**
 * Loads every item in the items parent tag
 * @param node Node to start reading xml doc from
 * @param pLevel Level the xml document belongs to
 */
void Level::LoadXMLItems(wxXmlNode *node)
{
    // Get the first item in the items parent tag
    auto child = node->GetChildren();

    // Iterate over every item inside the items tag
    for( ; child; child=child->GetNext())
    {
        auto name = child->GetName();

        std::shared_ptr<Item> item;

        if (name == "block")
        {
            item = std::make_shared<Block>(this);
        }
        else if (name == "poly")
        {
            item = std::make_shared<Poly>(this);
        }
        else if (name == "foe")
        {
            item = std::make_shared<Foe>(this);
        }
        else if (name == "goalposts")
        {
            item = std::make_shared<Goalpost>(this);
        }
        else if (name == "slingshot")
        {
            item = std::make_shared<WoodenSlingshot>(this);
        }
        else if (name == "background")
        {
//            std::shared_ptr<Item> tempBackground = std::make_shared<Background>(L"../images/background1.png", pLevel);
            item = std::make_shared<Background>(this);
        }

        if (item != nullptr)
        {
            mItems.push_back(item);

            item->setCache(mPictureCache);

            item->XmlLoad(child);
        }
    }
}

