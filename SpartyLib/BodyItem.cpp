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
BodyItem::BodyItem(b2World *world) : PositionalItem(world)
{
    // Configure box2d for the item
    // Create the body definition
    b2BodyDef bodyDefinition;
    bodyDefinition.position.Set(0.0f, -10.0f); // todo: The position has to be set to the actual item's position
    mBody = world->CreateBody(&bodyDefinition);
}
