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