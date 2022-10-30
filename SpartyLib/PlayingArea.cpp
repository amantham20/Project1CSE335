/**
 * @file PlayingArea.cpp
 * @author Rajmeet Singh Chandok, zhiqiang ni
 */

#include "PlayingArea.h"
#include "DebugDraw.h"
#include "Level.h"

/// Number of velocity update iterations per step
const int VelocityIterations = 6;

/// Number of position update iterations per step
const int PositionIterations = 2;

PlayingArea::PlayingArea(std::shared_ptr<Level> level, std::shared_ptr<Score> totalScore) : mItems(level->GetItem()), mTotalScore(totalScore)
{
    //todo incompleated
    mPhysics = std::make_shared<Physics>(level->GetPosition());
    mScore = std::make_shared<Score>(level, 0, 1400, 10);
    mTransitionalText = std::make_shared<TransitionalText>(level, 1400, 10);
    for(auto item : mItems)
    {
        item->InstallPhysics(mPhysics);
    }
}

void PlayingArea::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    for(auto item : mItems)
    {
        item->OnDraw(graphics);
    }
    mScore->OnDraw(graphics);
    mTotalScore->OnDraw(graphics);
    mTransitionalText->OnDraw(graphics);
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

void PlayingArea::Update(double frameDuration){
    mPhysics->GetWorld()->Step(frameDuration, VelocityIterations, PositionIterations);
}