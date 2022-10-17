/**
 * @file Level.h
 * @author Aman Dhruva Thamminana
 *
 *
 */

#ifndef ANGRYSPARTY_LEVEL_H
#define ANGRYSPARTY_LEVEL_H

#include "Item.h"

class Level {
private:
    double mHeight = 0;
    double mWidth = 0;

    int mLevelScore = 0;

    /// All of the items in the level
    std::vector<std::shared_ptr<Item>> mItems;

public:


};

#endif //ANGRYSPARTY_LEVEL_H
