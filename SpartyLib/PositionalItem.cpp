/**
 * @file PositionalItem.cpp
 * @author Rajmeet Singh Chandok
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