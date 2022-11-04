/**
 * @file PlayingArea.h
 * @author Rajmeet Singh Chandok, zhiqiang ni
 *
 *
 */

#ifndef ANGRYSPARTY_PLAYINGAREA_H
#define ANGRYSPARTY_PLAYINGAREA_H

#include "Item.h"
#include "SpartyGame.h"
#include "ItemVisitor.h"
#include "SpartyTracker.h"

/**
 * PlayingArea class
 *
 * A class that displays the playing area all the items for a specific level
 */
class PlayingArea {
private:
    /// Items copied from Level
    std::vector<std::shared_ptr<Item>> mItems;

    ///physic for the level object
    std::shared_ptr<Physics> mPhysics;

    ///level score object
    std::shared_ptr<Score> mScore;

    ///total score object
    std::shared_ptr<Score> mTotalScore;

    ///text object between level
    std::shared_ptr<TransitionalText> mTransitionalText;

    /// Current level we are in
    int mCurrentLevel = 0;

    /// Boolean that keeps track of whether the level finished or not
    bool mLevelEnd = false;

    /// Pointer to the Sparty tracker
    std::shared_ptr<SpartyTracker> mSpartyTracker;

    /// A pointer to the slingshot in the level
    std::shared_ptr<Slingshot> mSlingShot;

    /// Pointer to a pointer that is flying
    Angry * mFlyingAngry = nullptr;

    /// Keeps track if items have been killed
    bool mKill = false;

    /// Time that has to elapse for the game to finish and the text to show
    double leftOverTime = DBL_MAX;
public:
    /// Default Constructor
    PlayingArea() = delete;

    PlayingArea(const std::shared_ptr<Level>& level, std::shared_ptr<Score> totalScore);

    /**
     * Destructor
     */
    ~PlayingArea();

    /// Copy constructor (disabled)
    PlayingArea(const PlayingArea &) = delete;

    void Draw(const std::shared_ptr<wxGraphicsContext>& graphics);

    void DebugOnDraw(std::shared_ptr<wxGraphicsContext> graphics);

    void Accept(const std::shared_ptr<ItemVisitor>& visitor);

    void Update(double frameDuration);

    /**
     * Sets the level Playig Area is currently displaying
     * @param level New level to set Playing area to
     */
    void SetLevel(const int &level) { mCurrentLevel = level; } ;


    void Add(std::shared_ptr<Item> item);

    void InstallPhysics();

    /// Boolean that sets if the total should be added or not
    bool mAddTotal = true;

    /// Controls the text display that shows when a level is done or loads
    bool mControlDisplay = true;

    /// Duration texts should last, initialized to zero.
    double mTimeDuration = 0;

    Angry* HitTest(int x, int y);

    void ReloadSlingshot();

    void SetSlingShot(std::shared_ptr<Slingshot> slingshot);

    void NextLoad();

    /**
     * Returns if the level has been completed successfully
     * @return True if the level has been completed, false otherwise
     */
    bool isDone(){
        return mKill;
    }

    /**
     * Sets a new flying sparty
     * @param angry New angry sparty to set as flying sparty
     */
    void SetFlyingSparty(Angry* angry) {mFlyingAngry = angry;};

    /**
     * Gets the flying sparty
     * @return Pointer to the flying sparty. Return nullptr if no angry sparty exists
     */
    Angry* GetFlyingSparty() {return mFlyingAngry;};

    int GetNumberOfItems();
};

#endif //ANGRYSPARTY_PLAYINGAREA_H
