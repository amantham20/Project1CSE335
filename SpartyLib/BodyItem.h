/**
 * @file BodyItem.h
 * @author Milan Mihailovic
 *
 *
 */

#ifndef ANGRYSPARTY_BODYITEM_H
#define ANGRYSPARTY_BODYITEM_H

#include "PositionalItem.h"
#include <box2d.h>

class BodyItem : public PositionalItem {
private:
    /// box2d Item Body
    b2Body* mBody;

public:

    BodyItem(b2World* world);

};

#endif //ANGRYSPARTY_BODYITEM_H
