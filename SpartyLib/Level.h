/**
 * @file Level.h
 * @author Aman Dhruva Thamminana
 *
 * Level class representing a level in the game
 *
 */

#ifndef ANGRYSPARTY_LEVEL_H
#define ANGRYSPARTY_LEVEL_H

//#include "Item.h"
#include "Score.h"
#include "ItemVisitor.h"
#include "SpartyTracker.h"

class SpartyGame;
class Item;
class Slingshot;

class Picture;

/**
 * Level class describing a level object in the game
 */
class Level {
private:
    double mHeight = 0;
    double mWidth = 0;

    ///an pointer to sparty game
    SpartyGame *mSpartyGame;

    /// All of the items in the level
    std::vector<std::shared_ptr<Item>> mItems;

    /// A pointer to the slingshot in the level
    std::shared_ptr<Slingshot> mSlingShot;

public:
    double getHeight() { return mHeight; };
    double getWidth() { return mWidth; };
    std::vector<std::shared_ptr<Item>> GetItem() {return mItems; };
    Level() = delete;

    Level(SpartyGame *spartyGame);

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics);

    void Add(std::shared_ptr<Item> item);

    void SetSlingShot(std::shared_ptr<Slingshot> slingshot);

    //Level(double pHeight, double pWidth) : mHeight(pHeight), mWidth(pWidth){};
    void init();

    double GetHeight(){return mHeight;}
    double GetWidth(){return mWidth;}

    void LoadXMLLevel(wxXmlNode *node);

    b2Vec2 GetPlayAreaSize(){return b2Vec2(mWidth, mHeight);}

    void Load(wxXmlNode *node);

    void ReloadSlingshot();

    void Accept(std::shared_ptr<ItemVisitor> visitor);
};

#endif //ANGRYSPARTY_LEVEL_H
