/**
 * @file Level.h
 * @author Aman Dhruva Thamminana
 *
 *
 */

#ifndef ANGRYSPARTY_LEVEL_H
#define ANGRYSPARTY_LEVEL_H

#include "Item.h"
#include "Score.h"

class Level {
private:
    double mHeight = 0;
    double mWidth = 0;

    /// All of the items in the level
//    std::vector<std::shared_ptr<Item>> mItems;
    /// an pointer for score
    Score *mLevelScore;
public:
    Level(double pHeight, double pWidth) : mHeight(pHeight), mWidth(pWidth){};
    void init();
//    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    double GetHeight(){return mHeight;}
    double GetWidth(){return mWidth;}
};

#endif //ANGRYSPARTY_LEVEL_H
