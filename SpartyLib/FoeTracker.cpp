/**
 * @file FoeTracker.cpp
 * @author zhiqiang ni
 */

#include "pch.h"
#include "FoeTracker.h"
#include "Foe.h"

/**
 * Visitor pattern for Foe
 * Counts the number of foes
 * adds foes to kill in a list
 *
 * @param foe
 */
void FoeTracker::VisitFoe(Foe* foe)
{
    mNumberFoe++;

    if(foe->GetBody()->GetPosition().y < foe->GetDown()){

        mFoeKillListId.insert(foe->GetId());
        mFoeKillList.push_back(foe);
    }
}
