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

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* WoodenSlingshot::XmlSave(wxXmlNode* node)
{
    auto itemNode = Slingshot::XmlSave(node);
    //todo: uncomplete code

    return itemNode;
}