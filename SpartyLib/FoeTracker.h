/**
 * @file FoeTracker.h
 * @author zhiqaing ni
 *
 * a class track number of foe
 */

#ifndef ANGRYSPARTY_FOETRACKER_H
#define ANGRYSPARTY_FOETRACKER_H


#include "ItemVisitor.h"
#include "Physics.h"
#include <unordered_set>
/**
 * a Visitor class track number of foe
 */
class FoeTracker : public ItemVisitor{
private:
    /// Number of foes
    int mNumberFoe = 0;

    /// Number of Angry Spartes
    int nNumberAngry = 0;

    /// List of the foes to be killed
    std::vector<Foe *> mFoeKillList;

    /// List of the id of the foes to kill
    std::unordered_set<int> mFoeKillListId;
public:
    /**
     * Return the number of foes
     * @return
     */
    int GetNumberFoe(){ return mNumberFoe; };

    void VisitFoe(Foe *foe) override;

    /**
     * Returns a list of the ids of the foes to kill
     * @return
     */
    std::unordered_set<int> TheseHoesID(){return mFoeKillListId;};

    /**
     * Returns hoes
     * @return
     */
    std::vector<Foe *>  TheseHoes(){return mFoeKillList;};

    void VisitGruffSparty(GruffSparty* gruffSparty) override { nNumberAngry++;}

    void VisitHelmetSparty(HelmetSparty* helmetSparty) override { nNumberAngry++;}

    int GetNumberAngry(){return nNumberAngry;}
};


#endif //ANGRYSPARTY_FOETRACKER_H
