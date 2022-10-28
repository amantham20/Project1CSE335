/**
 * @file Goalpost.cpp
 * @author Milan Mihailovic, zhiqiang ni
 */

#include "pch.h"
#include "Goalpost.h"
#include "Consts.h"

using namespace std;

/// Slingshot filename
const wstring GoalpostsImageName = L"images/goalposts.png";

/**
 * Constructor
 * @param level Level the Goalpost is in
 */
Goalpost::Goalpost(std::shared_ptr<Level> level) : Slingshot(level)
{
    Item::SetImageName(GoalpostsImageName);
}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
 */
void Goalpost::XmlLoad(wxXmlNode *node)
{
    //todo: uncomplete code
    Slingshot::XmlLoad(node);
}

/**
 * Draw this Goalpost
 * @param graphics Graphics context used to draw this Goalpost
 */
void Goalpost::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Slingshot::OnDraw(graphics);
}

/**
 * Loads an Angry Sparty for launch
 * @param sparty Angry Sparty to load in the goalpost
 */
void Goalpost::LoadAngrySparty(Angry* sparty)
{
    // Get the position of the middle of the goalpost
    auto position = PositionalItem::GetPosition();
    auto xPosition = position.x+0.5;
    auto yPosition = position.y+2.5;

    // Set the Angry Sparty position between the goalpost's arms.
    sparty->SetLocation(xPosition, yPosition);
}