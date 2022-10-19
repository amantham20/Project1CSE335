/**
 * @file PositionalItem.cpp
 * @author Rajmeet Singh Chandok, zhiqiang ni
 */

#include "pch.h"
#include "PositionalItem.h"

/**
 * PositionalItem constructor
 * @param world
 */
PositionalItem::PositionalItem(Level *level, const std::wstring& filename) : Item(level, filename)
{
/*    // Configure box2d for the item
    // Create the body definition
    b2BodyDef bodyDefinition;
    bodyDefinition.position.Set(0.0f, -10.0f); // todo: The position has to be set to the actual item's position
    // Create body
    mBody = world->CreateBody(&bodyDefinition);*/

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
}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* PositionalItem::XmlSave(wxXmlNode* node)
{
    node->AddAttribute(L"x", wxString::FromDouble(mX));
    node->AddAttribute(L"y", wxString::FromDouble(mY));

    return node;
}