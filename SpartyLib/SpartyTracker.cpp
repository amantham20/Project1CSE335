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

/**
 * This function reloads an angry sparty in the given slingshot
 * @param slingshot Slingshot to reload
 */
void SpartyTracker::ReloadSlingshot(std::shared_ptr<Slingshot> slingshot)
{
    slingshot->LoadAngrySparty(mSparties.front());
}

/**
 * Checks if an item in the level has been clicked
 * @param x x coordinate to test
 * @param y y coordinate to test
 */
Angry* SpartyTracker::HitTest(int x, int y)
{
    for (auto i = mSparties.rbegin(); i!=mSparties.rend(); i++) {
        if ((*i)->HitTest(x, y)) {
            return *i;
        }
    }

    return nullptr;
}