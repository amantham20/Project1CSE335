/**
 * @file Slingshot.cpp
 * @author Milan Mihailovic
 */

#include "pch.h"
#include "Slingshot.h"
#include "Consts.h"

using namespace std;

/**
 * Constructor
 * @param world
 */
Slingshot::Slingshot(std::shared_ptr<Level> level) : PositionalItem(level)
{
    level->SetSlingShot(std::shared_ptr<Slingshot>(this));
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
void Slingshot::XmlLoad(wxXmlNode *node)
{
    //todo: uncomplete code
    PositionalItem::XmlLoad(node);
}

/**
 * Draws a slingshot
 * @param graphics Graphics context used to draw this slingshot
 */
void Slingshot::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    const int heightOffset = 50;

    auto tLevel = Item::GetLevel();
    auto wid = tLevel->GetWidth() * Consts::MtoCM;
    auto hit = tLevel->GetHeight()  * Consts::MtoCM;

    auto position = PositionalItem::GetPosition();
    auto image = Item::GetBitMap();

    graphics->PushState();

    graphics->Scale(1, -1);
    graphics->DrawBitmap(*Item::GetBitMap(),
            position.x * Consts::MtoCM,
            (position.y  * Consts::MtoCM) - image->GetHeight() - heightOffset,
            image->GetWidth(), image->GetHeight());
    wxPen pen(wxColour(41,13,1), 20);
    graphics->SetPen(pen);
    wxPoint2DDouble band[2] =
            {
            wxPoint2DDouble(position.x * Consts::MtoCM +15,
                            (position.y  * Consts::MtoCM) - image->GetHeight() - heightOffset+42),
            wxPoint2DDouble(position.x * Consts::MtoCM + 45,
                            (position.y  * Consts::MtoCM) - image->GetHeight() - heightOffset + 35),
            };
    graphics->DrawLines(2, band);
    graphics->PopState();
}

/**
 * Loads an Angry Sparty for launch
 * @param sparty Angry Sparty to load in the slingshot
 */
void Slingshot::LoadAngrySparty(Angry* sparty)
{
    sparty->SetLocation(0, 0);
}