/**
 * @file KillFoeVisitor.h
 * @author Aman Dhruva Thamminana
 *
 * Concrete visitor to kill foes
 */

#ifndef ANGRYSPARTY_KILLFOEVISITOR_H
#define ANGRYSPARTY_KILLFOEVISITOR_H

#include "ItemVisitor.h"

/**
 * Concrete visitor to kill foes
 */
class KillFoeVisitor : public ItemVisitor {
private:
    // List of the foes to kill
    std::vector<Foe *> KillListFoe;
public:


};

#endif //ANGRYSPARTY_KILLFOEVISITOR_H
