/**
 * @file Item.cpp
 * @author Milan Mihailovic
 */

#include "pch.h"
#include "Item.h"
#include <box2d.h>
//#include "Level.h"

using namespace std;

/**
 * Destructor
 */
Item::~Item()
{

}

/**
 * Item constructor
 * @param world
 */
Item::Item(b2World *world)
{
    // Configure box2d for every item
    // Create the body definition
    b2BodyDef bodyDefinition;
    bodyDefinition.position.Set(0.0f, -10.0f); // The position has to be set to the actual item's position
    // Create body
    mBody = world->CreateBody(&bodyDefinition);

}
