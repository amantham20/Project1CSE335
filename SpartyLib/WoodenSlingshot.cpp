/**
 * @file WoodenSlingshot.cpp
 * @author Milan Mihailovic, zhiqiang ni
 */

#include "pch.h"
#include "WoodenSlingshot.h"
#include "Consts.h"

using namespace std;

/**
 * WoodenSlingshot constructor
 * @param level
 */
WoodenSlingshot::WoodenSlingshot(std::shared_ptr<Level> level) : Slingshot(level)
{
}

void WoodenSlingshot::OnDraw(std::shared_ptr<wxGraphicsContext> graphics){

    graphics->PushState();

    auto position = PositionalItem::GetPosition();

    graphics->Translate(position.x * Consts::MtoCM,
            position.y * Consts::MtoCM);

    std::shared_ptr<wxBitmap> bitmap = Item::GetBitMap();

    graphics->Scale(1, -1);

    graphics->DrawBitmap(*bitmap,
            position.x * Consts::MtoCM,
            position.y * Consts::MtoCM,
            50 * Consts::MtoCM, 50 * Consts::MtoCM);

    graphics->PopState();
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
    //todo: uncomplete code
    Slingshot::XmlLoad(node);
}