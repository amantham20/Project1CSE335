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
#include "SpartyGame.h"

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
    std::shared_ptr<SpartyGame> mSpartyGame;

    /// All of the items in the level
    std::vector<std::shared_ptr<Item>> mItems;

    /// an pointer for score
    std::shared_ptr<Score> mLevelScore;

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

    std::shared_ptr<Score> GetScore() { return mLevelScore; };

    b2Vec2 GetPlayAreaSize(){return b2Vec2(mWidth, mHeight);}

    void Load(wxXmlNode *node);

    void ReloadSlingshot();

    void Accept(std::shared_ptr<ItemVisitor> visitor);

    std::shared_ptr<Item> HitTest(int x, int y);

    double GetGameScale() {return mSpartyGame->GetScale();}

    double GetGameXOffset() {return mSpartyGame->GetXOffset();}
    double GetGameYOffset() {return mSpartyGame->GetYOffset();}
};

#endif //ANGRYSPARTY_LEVEL_H
