/**
 * @file PositionalItem.cpp
 * @author Rajmeet Singh Chandok, zhiqiang ni, Milan Mihailovic
 */

#include "pch.h"
#include "PositionalItem.h"

/**
 * PositionalItem constructor
 * @param world
 */
PositionalItem::PositionalItem(std::shared_ptr<Level> level) : Item(level)
{

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
void PositionalItem::XmlLoad(wxXmlNode *node)
{
    node->GetAttribute(L"x", L"0").ToDouble(&mX);
    node->GetAttribute(L"y", L"0").ToDouble(&mY);
    Item::XmlLoad(node);
}

void PositionalItem::SetLocation(double x, double y)
{
    mX = x;
    mY = y;
}
