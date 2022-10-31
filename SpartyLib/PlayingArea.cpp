/**
 * @file PlayingArea.cpp
 * @author Rajmeet Singh Chandok, zhiqiang ni
 */

#include "PlayingArea.h"

#include <utility>
#include "DebugDraw.h"
#include "Level.h"

/// Number of velocity update iterations per step
const int VelocityIterations = 6;

/// Number of position update iterations per step
const int PositionIterations = 2;

/**
 * constructor
 * @param level
 * @param totalScore
 */
PlayingArea::PlayingArea(const std::shared_ptr<Level>& level, std::shared_ptr<Score> totalScore) : mItems(level->GetItem()), mTotalScore(std::move(totalScore))
{
    //todo incompleated
    mPhysics = std::make_shared<Physics>(level->GetPosition());
    mScore = std::make_shared<Score>(level, 0, 1400, 10);
    mTransitionalText = std::make_shared<TransitionalText>(level, 1400, 10);
    for(const auto& item : mItems)
    {
        item->InstallPhysics(mPhysics);
    }
}

PlayingArea::~PlayingArea()
{
    mItems.clear();
}

/**
 * draws the item
 * @param graphics
 */
void PlayingArea::Draw(const std::shared_ptr<wxGraphicsContext>& graphics)
{
    for(const auto& item : mItems)
    {
        item->OnDraw(graphics);
    }
    mScore->OnDraw(graphics);
    mTotalScore->OnDraw(graphics);
    mTransitionalText->OnDraw(graphics);
}

/**
 * draw the outline of items body
 * @param graphics
 */
void PlayingArea::DebugOnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    DebugDraw debugDraw(std::move(graphics));
    debugDraw.SetFlags(b2Draw::e_shapeBit | b2Draw::e_centerOfMassBit);
    mPhysics->GetWorld()->SetDebugDraw(&debugDraw);
    mPhysics->GetWorld()->DebugDraw();
}

/**
 * Accept a visitor for the collection
 * @param visitor The visitor for the collection
 */
void PlayingArea::Accept(const std::shared_ptr<ItemVisitor>& visitor)
{
    for (const auto& item : mItems)
    {
        item->Accept(visitor);
    }
}

/**
 * Update the physics
 * @param frameDuration Elapsed time in seconds
 */
void PlayingArea::Update(double frameDuration){
    mPhysics->GetWorld()->Step(frameDuration, VelocityIterations, PositionIterations);
}