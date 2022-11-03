/**
 * @file FoeTracker.cpp
 * @author zhiqiang ni
 */

#include "pch.h"
#include "FoeTracker.h"
#include "Foe.h"

void FoeTracker::VisitFoe(Foe* foe)
{
    mNumberFoe++;

    if(foe->GetBody()->GetPosition().y < foe->GetDown()){
//        mFoeKillList.push_back(foe);
//        mFoeKillList.push_back(foe->GetId());
        mFoeKillListId.insert(foe->GetId());
        mFoeKillList.push_back(foe);
    }
}

//void FoeTracker::RemoveFallenFoe(std::shared_ptr<Physics> physics){
//    for(auto foe : mFoeKillList){
//        physics->GetWorld()->DestroyBody(foe->GetBody());
//    }
//
//    mFoeKillList.clear();
//
//}