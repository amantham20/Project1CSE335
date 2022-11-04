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
    /// Height of the level
    double mHeight = 0;

    /// Width of the level
    double mWidth = 0;

    ///an pointer to sparty game
    std::shared_ptr<SpartyGame> mSpartyGame;

    /// All of the items in the level
    std::vector<std::shared_ptr<Item>> mItems;

    /// A pointer to the slingshot in the level
    std::shared_ptr<Slingshot> mSlingShot;

    /// shared pointer Sparty Tracker tracking the Angry Sparties
    std::shared_ptr<SpartyTracker> mSpartyTracker;

public:

    /**
     * Returns the position of the item
     * @return b2Vec2 representing the position of an item.
     */
    b2Vec2 GetPosition() { return b2Vec2(mWidth, mHeight); }

    /// Copy constructor (disabled)
    Level() = delete;

    Level(SpartyGame *spartyGame);

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics);

    void Add(std::shared_ptr<Item> item);

    void SetSlingShot(std::shared_ptr<Slingshot> slingshot);

    /// function for initialization
    void init();

    /**
     * returns the Height of the level
     * @return double representing the height of the level
     */
    double GetHeight(){return mHeight;}

    /**
     * returns the Width of the level
     * @return double representing the width of the levelx
     */
    double GetWidth(){return mWidth;}

    /// function Loading the XML Level
//    void LoadXMLLevel(wxXmlNode *node);

    /**
     * returns the play are size as a b2Vec2 of the current level
     * @return b2Vec2 of the current level
     */
    b2Vec2 GetPlayAreaSize(){return b2Vec2(mWidth, mHeight);}

    void Load(wxXmlNode *node);

    void ReloadSlingshot();

    void Accept(std::shared_ptr<ItemVisitor> visitor);

    /**
     * returns the angry sparty that has been clicked on
     * @param x the x value of the click
     * @param y the y value of the click
     * @return the angrysparty that was clicked
     */
    Angry* HitTest(int x, int y);

    /**
     * Returns the scale of the mSpartyGame
     * @return double of the score
     */
    double GetGameScale() {return mSpartyGame->GetScale();}

    /**
     * Returns the sparty games X offset
     * @return double representing the X offset of the sparty game
     */
    double GetGameXOffset() {return mSpartyGame->GetXOffset();}

    /**
     * Returns the sparty games Y offset
     * @return double representing the Y offset of the sparty game
     */
    double GetGameYOffset() {return mSpartyGame->GetYOffset();}

    void DrawRightSlingshotRubberBand(std::shared_ptr<wxGraphicsContext> graphics);

    void DrawSlingshotFront(std::shared_ptr<wxGraphicsContext> graphics);

    b2Vec2 GetSlingshotLoadingPosition();

    int GetRubberBandLength();

    void AddItemDepp(std::shared_ptr<PlayingArea> playingArea);

    void ClearLoadedSparty();

    std::shared_ptr<Slingshot> GetSlingshot();

    void ResetItemXY();
};

#endif //ANGRYSPARTY_LEVEL_H
