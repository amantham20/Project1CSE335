/**
 * @file Foe.cpp
 * @author Milan Mihailovic
 */

#include "pch.h"
#include "Foe.h"
#include "Consts.h"

/**
 * Constructor
 * @param level Level the foe is in.
 */
Foe::Foe(std::shared_ptr<Level> level) : BodyItem(level)
{

}

/**
 * Load the attributes for a Foe.
 *
 * @param node The Xml node we are loading the Foe from
 */
void Foe::XmlLoad(wxXmlNode *node)
{
    BodyItem::XmlLoad(node);
}

/**
 * Draws this foe
 * @param graphics Graphics context to draw this foe
 */
void Foe::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{

    //TODO : Get b2Body working to enable Easy Access to these values
    b2Body* body = BodyItem::GetBody();
    auto position = body->GetPosition();
    auto angle = body->GetAngle();

    //TODO : Couldn't figure out how to make foes exact height, change the 0.6 later
    auto wid = Consts::MtoCM * 0.6;
    auto x = position.x * Consts::MtoCM;
    auto y = position.y * Consts::MtoCM;

    graphics->PushState();
    graphics->Translate(x, y);
    graphics->Rotate(angle);

    std::shared_ptr<wxBitmap> bitmap = Item::GetBitMap();

    graphics->Scale(1, -1);
    graphics->DrawBitmap(*bitmap,
            -wid/2,
            -wid/2,
            wid, wid);

    graphics->PopState();
}

void Foe::InstallPhysics(std::shared_ptr<Physics> physics) {
    b2World* world = physics->GetWorld();

    // Create the box
    const int Octa = 8;
    const b2Vec2 vertices[] = {
            { 0.35355/2, 0.35355/2 },
            { 0.0 , 0.5/2 },
            { -0.35355/2 , 0.35355/2 },
            { -0.5/2 ,  0.0 },
            { -0.35355/2 , -0.35355/2 },
            { -0.0  ,  -0.5/2 },
            { 0.35355/2 , -0.35355/2 },
            { 0.5/2 ,  -0.0 },
    };

    b2PolygonShape OctaSexy;
    OctaSexy.Set(vertices, Octa);

    b2BodyDef bodyDefinition;
    bodyDefinition.position = PositionalItem::GetPosition();
    bodyDefinition.angle = BodyItem::GetAngle();
    bodyDefinition.type =  BodyItem::GetStatic() ? b2_staticBody : b2_dynamicBody;
    auto body = world->CreateBody(&bodyDefinition);

    if( BodyItem::GetStatic())
    {
        body->CreateFixture(&OctaSexy, 0.0f);
    }
    else
    {
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &OctaSexy;
        fixtureDef.density = (float) BodyItem::GetDensity();
        fixtureDef.friction = (float) BodyItem::GetFriction();
        fixtureDef.restitution = (float) BodyItem::GetResolution();

        body->CreateFixture(&fixtureDef);
    }
    BodyItem::SetBody(body);
}
