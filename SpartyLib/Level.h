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
#include "SpartyGame.h"
#include "Slingshot.h"

class PlayingArea;
class Item;
class SpartyTracker;
class Picture;
class Angry;



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

    /// A pointer to the slingshot in the level
    std::shared_ptr<Slingshot> mSlingShot;

    std::shared_ptr<SpartyTracker> mSpartyTracker;

public:
    double getHeight() { return mHeight; };
    double getWidth() { return mWidth; };

    /**
     * Returns the position of the item
     * @return b2Vec2 representing the position of an item.
     */
    b2Vec2 GetPosition() { return b2Vec2(mWidth, mHeight); }

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

    Angry* HitTest(int x, int y);

    double GetGameScale() {return mSpartyGame->GetScale();}

    double GetGameXOffset() {return mSpartyGame->GetXOffset();}
    double GetGameYOffset() {return mSpartyGame->GetYOffset();}

    void DrawRightSlingshotRubberBand(std::shared_ptr<wxGraphicsContext> graphics);

    void DrawSlingshotFront(std::shared_ptr<wxGraphicsContext> graphics);

    b2Vec2 GetSlingshotLoadingPosition();

    int GetRubberBandLength();

    void AddItemDepp(std::shared_ptr<PlayingArea> playingArea);
};

#endif //ANGRYSPARTY_LEVEL_H
