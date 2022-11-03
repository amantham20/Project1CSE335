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
    int mNumberFoe = 0;

    std::vector<Foe *> mFoeKillList;
    std::unordered_set<int> mFoeKillListId;
public:
    int GetNumberFoe(){ return mNumberFoe; };
    void VisitFoe(Foe *foe) override;

//    void RemoveFallenFoe(std::shared_ptr<Physics> physics);
//    std::vector<Foe *> TheseHoes(){return mFoeKillList;};
    std::unordered_set<int> TheseHoesID(){return mFoeKillListId;};

    std::vector<Foe *>  TheseHoes(){return mFoeKillList;};
};


#endif //ANGRYSPARTY_FOETRACKER_H
