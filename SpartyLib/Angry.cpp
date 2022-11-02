/**
 * @file Angry.cpp
 * @author James
 *
 */

//
// Created by James on 10/25/22.
//

#include "pch.h"
#include "Angry.h"
#include "Level.h"

Angry::Angry(std::shared_ptr<Level> level)
        :BodyItem(level)
{

}



void Angry::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    //TODO : Get b2Body working to enable Easy Access to these values
    b2Body* body = BodyItem::GetBody();
//    auto position = PositionalItem::GetPosition();
    auto position = mLoaded ? PositionalItem::GetPosition() : body->GetPosition();
//    std::cout << mLoaded << " " << "Position x: " << position.x << " " << "Position y: " << position.y << std::endl;

//    auto angle = body->GetAngle();

    const int heightOffset = 0;

//    auto position = PositionalItem::GetPosition();

    auto wid = Consts::MtoCM*0.5;
    auto x = position.x*Consts::MtoCM;
    auto y = position.y*Consts::MtoCM+heightOffset;

    graphics->PushState();
    graphics->Translate(x, y);

    std::shared_ptr<wxBitmap> bitmap = Item::GetBitMap();

    graphics->Scale(1, -1);
    graphics->DrawBitmap(*bitmap,
            -wid/2,
            -wid/2,
            wid, wid);

    graphics->PopState();

    if (IsLoadedInSlingshot())
    {
        mLevel->DrawSlingshotFront(graphics);
        DrawRubberBand(graphics);
    }
}

void Angry::DrawRubberBand(std::shared_ptr<wxGraphicsContext> graphics)
{
    // Draw slingshot rubber band that wraps around the body of the angry sparty

    graphics->PushState();

    // Set pen color and create a graphics path
    wxPen pen(wxColour(41, 13, 1), 15);
    graphics->SetPen(pen);
    wxGraphicsPath path = graphics->CreatePath();

    // Draw line based on the position of the angry sparty
    auto position = PositionalItem::GetPosition();
    path.MoveToPoint(position.x*Consts::MtoCM, position.y*Consts::MtoCM);
    path.AddLineToPoint(position.x*Consts::MtoCM-18.5, position.y*Consts::MtoCM-2);
    graphics->StrokePath(path);
    graphics->PopState();

    // Draw right rubber band portion on top of the angry sparty
    mLevel->DrawRightSlingshotRubberBand(graphics);
}


void Angry::InstallPhysics(std::shared_ptr<Physics> physics) {
    // Create the body definition
    BodyItem::SetPhysics(physics);

    b2BodyDef bodyDefinition;
    // Todo: Change to dynamics body on the fly instead of hard coding it
    bodyDefinition.type = b2_dynamicBody;
    bodyDefinition.position = PositionalItem::GetPosition();

    auto world = physics->GetWorld();
    auto body = world->CreateBody(&bodyDefinition);

    // Create the shape
    b2CircleShape circle;

    circle.m_radius = (float)BodyItem::GetAngle();

    body->CreateFixture(&circle, 0.0f);
    BodyItem::SetBody(body);
}

void Angry::Launch(b2Vec2 vel)
{
    mBody->SetLinearVelocity(vel);
}

