/**
 * @file BodyItem.cpp
 * @author Milan Mihailovic
 */

#include "pch.h"
#include "BodyItem.h"

/**
 * BodyItem constructor
 * @param world
 */
BodyItem::BodyItem(std::shared_ptr<Level> level) : PositionalItem(level)
{
    // Configure box2d for the item
    // Create the body definition
    b2BodyDef bodyDefinition;
    bodyDefinition.position.Set(0.0f, -10.0f); // todo: The position has to be set to the actual item's position
    // Create body
//    mBody = world->CreateBody(&bodyDefinition);

}

/**
 * Loads XML data to BodyItem
 * @param node Xml note containing data for BodyItem
 */
void BodyItem::XmlLoad(wxXmlNode *node)
{
    node->GetAttribute(L"width").ToDouble(&mWidth);
    node->GetAttribute(L"height").ToDouble(&mHeight);

    PositionalItem::XmlLoad(node);
}