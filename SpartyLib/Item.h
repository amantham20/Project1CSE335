/**
 * @file Item.h
 * @author Milan Mihailovic
 *
 * Base class for any item in our game.
 */

#ifndef ANGRYSPARTY_ITEM_H
#define ANGRYSPARTY_ITEM_H
#include <memory>
#include "b2_world.h"

//class Level;

class Item {
private:
    /// The level this item is contained in
    //Level *mLevel

public:
    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item &) = delete;

    virtual ~Item();

    Item(b2World* world);

};

#endif //ANGRYSPARTY_ITEM_H
