//
// Created by James on 10/25/22.
//

#include "Angry.h"

Angry::Angry(std::shared_ptr<Level> level) : BodyItem(level)
{

}

void Angry::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    //TODO : Get b2Body working to enable Easy Access to these values
//    b2Body* body = BodyItem::GetBody();
//    auto position = body->GetPosition();
//    auto angle = body->GetAngle();

    const int heightOffset = 0;

    auto position = PositionalItem::GetPosition();

    //TODO : Couldn't figure out how to make foes exact height, change the 0.6 later
    auto wid = Consts::MtoCM * 0.5;
    auto x = position.x * Consts::MtoCM;
    auto y = position.y * Consts::MtoCM + heightOffset;

    graphics->PushState();
    graphics->Translate(x, y);

    std::shared_ptr<wxBitmap> bitmap = Item::GetBitMap();

    graphics->Scale(1, -1);
    graphics->DrawBitmap(*bitmap,
            -wid/2,
            -wid/2,
            wid, wid);

    graphics->PopState();
}

void Angry::InstallPhysics(std::shared_ptr<Physics> physics) {
    // Create the body definition
    b2BodyDef bodyDefinition;
    bodyDefinition.type = b2_staticBody;

    auto world = physics->GetWorld();
    auto body = world->CreateBody(&bodyDefinition);

    // Create the shape
    b2CircleShape circle;

    circle.m_radius = (float)BodyItem::GetAngle();

    body->CreateFixture(&circle, 0.0f);
    BodyItem::SetBody(body);
}
