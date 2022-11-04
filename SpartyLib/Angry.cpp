/**
 * @file Angry.cpp
 * @author James, Rajmeet Singh Chandok
 *
 */


#include "pch.h"
#include "Angry.h"
#include "Level.h"

/**
 * Constructor
 * @param level
 */
Angry::Angry(std::shared_ptr<Level> level)
        :BodyItem(level)
{

}

/**
 * Drawing of angry sparty
 * @param graphics
 */
void Angry::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    b2Body* body = BodyItem::GetBody();
    auto position = mLoaded ? PositionalItem::GetPosition() : body->GetPosition();
    auto angle = body->GetAngle();


    const int heightOffset = 0;

    auto wid = Consts::MtoCM*0.5;
    auto x = position.x*Consts::MtoCM;
    auto y = position.y*Consts::MtoCM+heightOffset;

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

    if (IsLoadedInSlingshot())
    {
        mLevel->DrawSlingshotFront(graphics);
        DrawRubberBand(graphics);
    }
}

/**
 * Draws the rubber band that scales with the position
 * @param graphics
 */
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

/**
 * Installs physics to each angry sparty
 * @param physics
 */
void Angry::InstallPhysics(std::shared_ptr<Physics> physics) {

    BodyItem::SetPhysics(physics);

    b2BodyDef bodyDefinition;
    bodyDefinition.type = b2_staticBody;
    bodyDefinition.position = PositionalItem::GetPosition();

    auto world = physics->GetWorld();
    auto body = world->CreateBody(&bodyDefinition);

    // Create the shape
    b2CircleShape circle;

    circle.m_radius = (float)BodyItem::GetAngle();

    body->CreateFixture(&circle, 0.0f);
    BodyItem::SetBody(body);
}

/**
 * Invoked with the angry sparty is launched
 * @param vel mPullDirection vector
 */
void Angry::Launch(b2Vec2 vel)
{
    auto body = BodyItem::GetBody();
    // Get the position and angle before
    // we destroy the body.
    auto position = body->GetPosition();
    auto angle = body->GetAngle();

    auto world = mPhysics->GetWorld();

    // Destroy the body in the physics system
    world->DestroyBody(body);

    // Create the body definition
    b2BodyDef bodyDefinition;
    bodyDefinition.position = position;
    bodyDefinition.angle = angle;
    bodyDefinition.type = b2_dynamicBody;
    bodyDefinition.angularDamping = 0.9;
    bodyDefinition.linearDamping = 0.1;
    body = world->CreateBody(&bodyDefinition);

    // Create the shape
    b2CircleShape circle;
    circle.m_radius = (float)mRadius;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circle;
    fixtureDef.density = (float)5;
    fixtureDef.friction = 1;
    fixtureDef.restitution = 0.3;

    body->CreateFixture(&fixtureDef);
    BodyItem::SetBody(body);


    vel *= mVelocityFactor;
    body->SetLinearVelocity(vel);
}

/**
 * Gets the physics world and destroys the body
 */
void Angry::DeleteBody()
{
    auto body = BodyItem::GetBody();
    auto world = mPhysics->GetWorld();
    // Destroy the body in the physics system
    world->DestroyBody(body);
}

/**
 * Function that makes an angry foe dive down (special ability)
 */
void Angry::Dive()
{
    auto body = BodyItem::GetBody();

    b2Vec2 vel = b2Vec2(0, -30);
    body->SetLinearVelocity(vel);
}
