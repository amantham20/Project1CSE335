/**
 * @file PlayingArea.cpp
 * @author Rajmeet Singh Chandok, zhiqiang ni
 */

#include "PlayingArea.h"
#include "DebugDraw.h"
#include "Level.h"

PlayingArea::PlayingArea(std::shared_ptr<Level> level, std::shared_ptr<Score> totalScore) : mItems(level->GetItem()), mTotalScore(totalScore)
{
    //todo incompleated
    mScore = std::make_shared<Score>(level, 0, 1400, 10);
}

void PlayingArea::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    for(auto item : mItems)
    {
        item->OnDraw(graphics);
    }
    mScore->OnDraw(graphics);
    mTotalScore->OnDraw(graphics);
}

void PlayingArea::DebugOnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    DebugDraw debugDraw(graphics);
    debugDraw.SetFlags(b2Draw::e_shapeBit | b2Draw::e_centerOfMassBit);
    mPhysics->GetWorld()->SetDebugDraw(&debugDraw);
    mPhysics->GetWorld()->DebugDraw();
}

void PlayingArea::Accept(std::shared_ptr<ItemVisitor> visitor)
{
    for (const auto& item : mItems)
    {
        item->Accept(visitor);
    }
}
