/**
 * @file Poly.cpp
 * @author Rajmeet Singh Chandok, zhiqiang ni
 */

#include "pch.h"
#include "Poly.h"

/**
 * Constructor
 * @param level
 */
Poly::Poly(std::shared_ptr<Level> level) : BodyItem(level)
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
void Poly::XmlLoad(wxXmlNode *node)
{
    //todo: this may be wong place but it got be some where in the code


    //todo: this may be not the best way
    mVertices.clear();
    //load vertex
    auto child = node->GetChildren();
    for( ; child; child=child->GetNext())
    {
        auto name = child->GetName();
        if(name == L"v")
        {
            double x, y;
            child->GetAttribute(L"x", L"0").ToDouble(&x);
            child->GetAttribute(L"y", L"0").ToDouble(&y);
            b2Vec2 b2vertex(x, y);
            mVertices.push_back(b2vertex);
        }
    }


    BodyItem::XmlLoad(node);
}

/**
 * Draws a polygon using the graphics context given
 * @param graphics
 */
void Poly::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    b2Body* body = BodyItem::GetBody();
    auto position = body->GetPosition();
    auto angle = body->GetAngle();

    // Find the minimum and maximum x/y values
    b2Vec2 minimums = mVertices[0];
    b2Vec2 maximums = mVertices[0];
    for(auto v : mVertices)
    {
        minimums.x = fmin(minimums.x, v.x);
        minimums.y = fmin(minimums.y, v.y);
        maximums.x = fmax(maximums.x, v.x);
        maximums.y = fmax(maximums.y, v.y);
    }

    auto size = maximums - minimums;

    auto x = position.x * Consts::MtoCM;
    auto y = position.y * Consts::MtoCM;

    graphics->PushState();
    graphics->Translate(x, y);
    graphics->Rotate(angle);

    std::shared_ptr<wxBitmap> bitmap = Item::GetBitMap();

    graphics->Scale(1, -1);
    graphics->DrawBitmap(*bitmap,
                         minimums.x * Consts::MtoCM,
                         minimums.y * Consts::MtoCM,
                         size.x * Consts::MtoCM,
                         size.y * Consts::MtoCM);

    graphics->PopState();
}

/**
 * Install physics for poly given the physics object
 * @param physics
 */
void Poly::InstallPhysics(std::shared_ptr<Physics> physics){

    b2World* world = physics->GetWorld();

    // Create the poly
    const int polySize = mVertices.size();
    b2PolygonShape poly;
    poly.Set(&mVertices[0], polySize);


    // Create the body definition
    b2BodyDef bodyDefinition;
    bodyDefinition.position = PositionalItem::GetPosition();
    bodyDefinition.angle = BodyItem::GetAngle();
    bodyDefinition.type =  BodyItem::GetStatic() ? b2_staticBody : b2_dynamicBody;
    auto body = world->CreateBody(&bodyDefinition);

    if( BodyItem::GetStatic())
    {
        body->CreateFixture(&poly, 0.0f);
    }
    else
    {
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &poly;
        fixtureDef.density = (float) BodyItem::GetDensity();
        fixtureDef.friction = (float) BodyItem::GetFriction();
        fixtureDef.restitution = (float) BodyItem::GetResolution();

        body->CreateFixture(&fixtureDef);
    }
    BodyItem::SetBody(body);
}