/**
 * @file Block.cpp
 * @author Rajmeet Singh Chandok, zhiqiang ni
 */

#include "pch.h"
#include "Block.h"
#include "Consts.h"
#include "BodyItem.h"
#include "Item.h"
#include <box2d.h>

/**
 * Load the attributes for an Block node.
 * @param node The Xml node we are loading the Block from
 */
void Block::XmlLoad(wxXmlNode *node)
{
    node->GetAttribute(L"repeat-x").ToInt(&mRepeatX);
    BodyItem::XmlLoad(node);
}

/**
 * Constructor
 * @param level Level the block is in.
 */
Block::Block(std::shared_ptr<Level> level) : BodyItem(level)
{

}

/**
 * Draws this block
 * @param graphics Graphics context to draw this block
 */
void Block::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{

    graphics->PushState();
    auto mSize = BodyItem::GetSize();

    b2Body* body = BodyItem::GetBody();
    auto position = body->GetPosition();
    auto angle = body->GetAngle();


    graphics->Translate(position.x * Consts::MtoCM,
            position.y * Consts::MtoCM);
    graphics->Rotate(angle);

    // Make this is left side of the rectangle
    double x = -mSize.x/2 * Consts::MtoCM;

    // And the top
    double y = mSize.y/2 * Consts::MtoCM;

    // The width of each repeated block
    double xw = mSize.x / mRepeatX * Consts::MtoCM;

    std::shared_ptr<wxBitmap> bitmap = Item::GetBitMap();

    graphics->Translate(0, y);
    graphics->Scale(1, -1);
    for(int ix=0; ix<mRepeatX;  ix++)
    {
        graphics->DrawBitmap(*bitmap,
                x,
                0,
                xw, mSize.y * Consts::MtoCM);

        x += xw;
    }

    graphics->PopState();
}

/**
 * Installs physics for this item
 * @param physics Physics object to install
 */
void Block::InstallPhysics(std::shared_ptr<Physics> physics){

    BodyItem::SetPhysics(physics);
    b2World* world = physics->GetWorld();

    // Create the box
    b2PolygonShape box;
    auto size = BodyItem::GetSize();
    box.SetAsBox(size.x/2, size.y/2);

    // Create the body definition
    b2BodyDef bodyDefinition;
    bodyDefinition.position = PositionalItem::GetPosition();
    bodyDefinition.angle = BodyItem::GetAngle();
    bodyDefinition.type =  BodyItem::GetStatic() ? b2_staticBody : b2_dynamicBody;
    auto body = world->CreateBody(&bodyDefinition);

    if( BodyItem::GetStatic())
    {
        body->CreateFixture(&box, 0.0f);
    }
    else
    {
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &box;
        fixtureDef.density = (float) BodyItem::GetDensity();
        fixtureDef.friction = (float) BodyItem::GetFriction();
        fixtureDef.restitution = (float) BodyItem::GetResolution();

        body->CreateFixture(&fixtureDef);
    }
    BodyItem::SetBody(body);
}