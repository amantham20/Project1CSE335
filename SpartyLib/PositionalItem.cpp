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
PositionalItem::PositionalItem(b2World *world) : Item(world)
{
    // Configure box2d for every item
    // Create the body definition
    b2BodyDef bodyDefinition;
    bodyDefinition.position.Set(0.0f, -10.0f); // The position has to be set to the actual item's position
    // Create body
    mBody = world->CreateBody(&bodyDefinition);

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
    //todo: uncomplete code
    Item::XmlLoad(node);
}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* PositionalItem::XmlSave(wxXmlNode* node)
{
    auto itemNode = Item::XmlSave(node);
    //todo: uncomplete code

    return itemNode;
}