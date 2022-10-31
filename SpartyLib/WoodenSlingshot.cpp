/**
 * @file WoodenSlingshot.cpp
 * @author Milan Mihailovic, zhiqiang ni
 */

#include "pch.h"
#include "WoodenSlingshot.h"
#include "Consts.h"
#include "Item.h"

using namespace std;

/// Slingshot filename
const wstring WoodenSlingshotImageName = L"images/slingshot.png";

/**
 * WoodenSlingshot constructor
 * @param level
 */
WoodenSlingshot::WoodenSlingshot(std::shared_ptr<Level> level) : Slingshot(level)
{
    Item::SetImageName(WoodenSlingshotImageName);
}

void WoodenSlingshot::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Slingshot::OnDraw(graphics);

    // Draw slingshot rubber band
    wxPen pen(wxColour(41,13,1), 20);
    graphics->SetPen(pen);
    wxGraphicsPath path = graphics->CreatePath();
    path.MoveToPoint(Slingshot::GetXLeftAttachment(), Slingshot::GetYLeftAttachment());
    path.AddLineToPoint(Slingshot::GetXRightAttachment(), Slingshot::GetYRightAttachment());
    graphics->StrokePath(path);
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
void WoodenSlingshot::XmlLoad(wxXmlNode *node)
{
    Slingshot::XmlLoad(node);

    // Set position of the laoding spot for an angry sparty
    auto position = PositionalItem::GetPosition();
    Slingshot::SetXLoadSpot(position.x+0.3);
    Slingshot::SetYLoadSpot(position.y+1.5);

    Slingshot::SetXLeftAttachment(-5.35*Consts::MtoCM);
    Slingshot::SetYLeftAttachment(1.7*Consts::MtoCM);
    Slingshot::SetXRightAttachment(-5.0*Consts::MtoCM);
    Slingshot::SetYRightAttachment(1.8*Consts::MtoCM);
}

/**
 * Loads an Angry Sparty for launch
 * @param sparty Angry Sparty to load in the slingshot
 */
void WoodenSlingshot::LoadAngrySparty(Angry* sparty)
{
    // Set the Angry Sparty position between the slingshot's arms.
    sparty->SetLocation(Slingshot::GetXLoadSpot(), Slingshot::GetYLoadSpot());
}