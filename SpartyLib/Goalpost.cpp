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

    // Set position of the laoding spot for an angry sparty
    auto position = PositionalItem::GetPosition();
    Slingshot::SetXLoadSpot(position.x+0.5);
    Slingshot::SetYLoadSpot(position.y+2.5);

    Slingshot::SetXLeftAttachment(-5.4*Consts::MtoCM);
    Slingshot::SetYLeftAttachment(2.7*Consts::MtoCM);
    Slingshot::SetXRightAttachment(-4.6*Consts::MtoCM);
    Slingshot::SetYRightAttachment(2.8*Consts::MtoCM);
}

/**
 * Draw this Goalpost
 * @param graphics Graphics context used to draw this Goalpost
 */
void Goalpost::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
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
 * Loads an Angry Sparty for launch
 * @param sparty Angry Sparty to load in the goalpost
 */
void Goalpost::LoadAngrySparty(Angry* sparty)
{
    // Set the Angry Sparty position between the goalpost's arms.
    sparty->SetLocation(Slingshot::GetXLoadSpot(), Slingshot::GetYLoadSpot());
}