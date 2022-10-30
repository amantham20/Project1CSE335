//
// Created by James on 10/30/22.
//

#ifndef ANGRYSPARTY_FOETRACKER_H
#define ANGRYSPARTY_FOETRACKER_H


#include "ItemVisitor.h"

class FoeTracker : public ItemVisitor{
private:
    int mNumberFoe = 0;
public:
    int GetNumberFoe(){ return mNumberFoe; };
    void VisitFoe(Foe *foe) override;
};


#endif //ANGRYSPARTY_FOETRACKER_H
