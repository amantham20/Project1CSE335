/**
 * @file KillFoeVisitor.h
 * @author Aman Dhruva Thamminana
 *
 *
 */

#ifndef ANGRYSPARTY_KILLFOEVISITOR_H
#define ANGRYSPARTY_KILLFOEVISITOR_H

#include "ItemVisitor.h"

class KillFoeVisitor : public ItemVisitor {
private:
    std::vector<Foe *> KillListFoe;
public:


};

#endif //ANGRYSPARTY_KILLFOEVISITOR_H
