/**
 * @file FoeTracker.h
 * @author zhiqaing ni
 *
 * a class track number of foe
 */

#ifndef ANGRYSPARTY_FOETRACKER_H
#define ANGRYSPARTY_FOETRACKER_H


#include "ItemVisitor.h"

/**
 * a Visitor class track number of foe
 */
class FoeTracker : public ItemVisitor{
private:
    int mNumberFoe = 0;
public:
    int GetNumberFoe(){ return mNumberFoe; };
    void VisitFoe(Foe *foe) override;
};


#endif //ANGRYSPARTY_FOETRACKER_H
