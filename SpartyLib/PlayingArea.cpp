/**
 * @file PlayingArea.cpp
 * @author Rajmeet Singh Chandok
 */

#include "PlayingArea.h"
#include "DebugDraw.h"

PlayingArea::PlayingArea(std::vector<std::shared_ptr<Item>> items) : mItems(items)
{
}

void PlayingArea::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    for(auto item : mItems)
    {
        item->OnDraw(graphics);
    }
}

void PlayingArea::DebugOnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    DebugDraw debugDraw(graphics);
    debugDraw.SetFlags(b2Draw::e_shapeBit | b2Draw::e_centerOfMassBit);
    mPhysics->GetWorld()->SetDebugDraw(&debugDraw);
    mPhysics->GetWorld()->DebugDraw();
}