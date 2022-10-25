/**
 * @file Foe.cpp
 * @author Milan Mihailovic
 */

#include "pch.h"
#include "Foe.h"
#include "Consts.h"

/**
 * Constructor
 * @param level Level the foe is in.
 */
Foe::Foe(std::shared_ptr<Level> level) : BodyItem(level)
{

}

/**
 * Load the attributes for a Foe.
 *
 * @param node The Xml node we are loading the Foe from
 */
void Foe::XmlLoad(wxXmlNode *node)
{
    BodyItem::XmlLoad(node);
}

/**
 * Draws this foe
 * @param graphics Graphics context to draw this foe
 */
void Foe::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{

    //TODO : Get b2Body working to enable Easy Access to these values
//    b2Body* body = BodyItem::GetBody();
//    auto position = body->GetPosition();
//    auto angle = body->GetAngle();

    auto position = PositionalItem::GetPosition();
    auto angle = BodyItem::GetAngle();

    //TODO : Couldn't figure out how to make foes exact height, change the 0.6 later
    auto wid = Consts::MtoCM * 0.6;
    auto x = position.x * Consts::MtoCM;
    auto y = position.y * Consts::MtoCM;

    graphics->PushState();
    graphics->Translate(x, y);
    graphics->Rotate(angle);

    std::shared_ptr<wxBitmap> bitmap = Item::GetBitMap();

    graphics->Scale(1, -1);
    graphics->DrawBitmap(*bitmap,
            -wid/2,
            -wid/2,
            wid, wid);

    graphics->PopState();
}
