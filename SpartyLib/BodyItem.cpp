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
//    // Configure box2d for the item
//    // Create the body definition
//    b2BodyDef bodyDefinition;
//    bodyDefinition.position.Set(0.0f, -10.0f); // todo: The position has to be set to the actual item's position
//    // Create body
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
    mType = node->GetAttribute(L"type").ToStdWstring();
    node->GetAttribute(L"angle").ToDouble(&mAngle);
    node->GetAttribute(L"density").ToDouble(&mDensity);
    node->GetAttribute(L"friction").ToDouble(&mFriction);
    node->GetAttribute(L"restitution").ToDouble(&mRestitution);

    PositionalItem::XmlLoad(node);

    mSize = b2Vec2(mWidth, mHeight);


}

void BodyItem::InstallPhysics(std::shared_ptr<Physics> physics)
{
    mPhysics = physics;
    b2World* world = physics->GetWorld();

    // Create the box
    b2PolygonShape box;
    box.SetAsBox(mSize.x/2, mSize.y/2);

    // Create the body definition
    b2BodyDef bodyDefinition;
    bodyDefinition.position = PositionalItem::GetPosition();
    bodyDefinition.angle = mAngle*Consts::DtoR;
    bodyDefinition.type = mStatic ? b2_staticBody : b2_dynamicBody;
    auto body = world->CreateBody(&bodyDefinition);

    if(mStatic)
    {
        body->CreateFixture(&box, 0.0f);
    }
    else
    {
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &box;
        fixtureDef.density = (float)mDensity;
        fixtureDef.friction = (float)mFriction;
        fixtureDef.restitution = (float)mRestitution;

        body->CreateFixture(&fixtureDef);
    }
    mBody = body;
}