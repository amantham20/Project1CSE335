/**
 * @file SpartyTracker.cpp
 * @author Ian Valdovinos Granados
 */

#include "pch.h"
#include "SpartyTracker.h"

/**
 * Visit a HelmetSparty object
 * @param helmetSparty Angry Sparty we are visiting
 */
void SpartyTracker::VisitHelmetSparty(HelmetSparty* helmetSparty)
{
    mSparties.push_back(helmetSparty);
    mNumSparty++;
}

/**
 * Visit a GruffSpartu object
 * @param gruffSparty Angry Spartu we are visiting
 */
void SpartyTracker::VisitGruffSparty(GruffSparty* gruffSparty)
{
    mSparties.push_back(gruffSparty);
    mNumSparty++;
}

void SpartyTracker::ReloadSlingshot(Slingshot* slingshot, std::shared_ptr<Level> level)
{
    for (auto angry : mSparties)
    {
        if (angry->GetLevel() == level)
        {
            slingshot->LoadAngrySparty(angry);
            break;
        }
    }
}