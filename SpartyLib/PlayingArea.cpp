/**
 * @file PlayingArea.cpp
 * @author Rajmeet Singh Chandok, zhiqiang ni
 */

#include "pch.h"
#include "PlayingArea.h"

#include <utility>
#include "DebugDraw.h"
#include "Level.h"
#include "FoeTracker.h"
#include <unordered_set>
#include "Foe.h"

/// Number of mPullDirection update iterations per step
const int VelocityIterations = 6;

/// Number of position update iterations per step
const int PositionIterations = 2;

///postion for x for score
const int PositionXScore  = 1400;

///postion for y for score
const int PositionYScore  = 10;

/**
 * constructor
 * @param level
 * @param totalScore
 */
PlayingArea::PlayingArea(const std::shared_ptr<Level>& level, std::shared_ptr<Score> totalScore) : mTotalScore(std::move(totalScore))
{
    //todo incompleated Have to make it left alighted when the values are greater than 1 digit
    mPhysics = std::make_shared<Physics>(level->GetPosition());
    mScore = std::make_shared<Score>(level, 0, level->GetWidth()*Consts::MtoCM-50, 10);
    mTransitionalText = std::make_shared<TransitionalText>(level, PositionXScore, PositionYScore);


//    for(const auto& item : mItems)
//    {
//        item->InstallPhysics(mPhysics);
//    }
}

PlayingArea::~PlayingArea()
{
    mItems.clear();
}

void PlayingArea::InstallPhysics() {
    for(const auto& item : mItems)
    {
        item->InstallPhysics(mPhysics);
    }
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

    if (mControlDisplay)
    {
        mTransitionalText->OnDraw(graphics, mCurrentLevel, mLevelEnd);
    }

    NextLoad();
}

void PlayingArea::NextLoad(){

    if(mFlyingAngry == nullptr){
        mFlyingAngry = mSlingShot->GetLoadedAngrySparty();
    }

    Angry* spartyToKill;
    if(mFlyingAngry != nullptr && mSlingShot->GetLoadedAngrySparty() == nullptr){
        auto velocity = mFlyingAngry->GetBody()->GetLinearVelocity();
        auto speed = velocity.Length();
        if(speed < 0.05){
            ////Sparty is dead
            spartyToKill = mFlyingAngry;

                int idChecker =  spartyToKill->GetId();
                auto deleteItem = mItems.end();
                for(auto itemItter = mItems.begin(); itemItter != mItems.end(); itemItter++ ){
                    if (idChecker == (*itemItter)->GetId()){
                        deleteItem = itemItter;
                        break;

                    }


                }

                if(deleteItem != mItems.end()){
                    mItems.erase(deleteItem);
                }
                mFlyingAngry = nullptr;

                auto Homie = std::make_shared<FoeTracker>();
                Accept(Homie);
                auto Killlist  = Homie->TheseHoesID();

                std::vector<std::vector<std::shared_ptr<Item>>::iterator> KillVec;
                for (auto itemItter = mItems.begin(); itemItter != mItems.end(); itemItter++ ){
                    if(Killlist.find((*itemItter)->GetId()) != Killlist.end() ){
                        KillVec.push_back(itemItter);
                        mScore->AddScore(100);
                    }
                }

                auto KilllistObj = Homie->TheseHoes();
                for(auto itemItter : KilllistObj){
                    if (itemItter->GetBody()!=nullptr){
                        itemItter->DeleteBody(mPhysics);
                    }

                }

                for(auto itter = KillVec.rbegin(); itter != KillVec.rend(); itter++){
                        mItems.erase(*itter);
                }

                if(Homie->GetNumberFoe() - Homie->TheseHoes().size() == 0){


                    leftOverTime = mTimeDuration;

                    mControlDisplay = true;
                    mLevelEnd = true;


                    leftOverSparties = Homie->GetNumberFoe() - Homie->TheseHoes().size();
                }

                spartyToKill->DeleteBody();

                ReloadSlingshot();

                if (Homie->GetNumberAngry() == 0)
                {
                    leftOverTime = mTimeDuration;

                    mControlDisplay = true;
                    mLevelEnd = true;
                }
        }
    }
}

void PlayingArea::Add(std::shared_ptr<Item> item)
{
    mItems.push_back(item);
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
    mTimeDuration += frameDuration;

    if (mTimeDuration > 5+leftOverTime){
        mControlDisplay = false;

        mKill = true;

    }
    if( mLevelEnd == true)
    {
        if(mAddTotal)
        {
            mTotalScore->AddScore(mScore->GetScore());
            mAddTotal = false;
        }

        return;
    }

    if (mTimeDuration > 2)
    {

        mControlDisplay = false;
    }

//    auto velocity = mFlyingAngry->GetBody()->GetLinearVelocity();

//    mFlyingAngry->SetDive(mDive);
//
//    if (mFlyingAngry->GetDive())
//    {
//        mFlyingAngry->Launch(velocity, mDive);
//        mFlyingAngry->SetDive(false);
//    }


//    if (mDive)
//    {
////        wxLogMessage("Success!!");
//    }

    // dont loop here
    // probably put diving here
    // change member variable trhough virtual setter that checks each item (call the function Dive)
}

/**
 * Reload the slingshot with an Angry sparty in this level
 */
void PlayingArea::ReloadSlingshot()
{
    mSpartyTracker = std::make_shared<SpartyTracker>();
    Accept(mSpartyTracker);
    mSpartyTracker->ReloadSlingshot(mSlingShot);
}

/**
 * Checks if an item in the level has been clicked
 * @param x x coordinate to test
 * @param y y coordinate to test
 */
Angry* PlayingArea::HitTest(int x, int y)
{
    return mSpartyTracker->HitTest(x, y);
}

/**
 * Sets the slingshot for this level, this allows fast access to the level's slingshot instead of having to
 * iterate over its mItems.
 * @param slingshot Slingshot to set to this level
 */
void PlayingArea::SetSlingShot(std::shared_ptr<Slingshot> slingshot)
{
    mSlingShot = slingshot;
}

int PlayingArea::GetNumberOfItems()
{
    return mItems.size();
}
