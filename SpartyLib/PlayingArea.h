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

    int mCurrentLevel = 0;

    bool mLevelEnd = false;

    std::shared_ptr<SpartyTracker> mSpartyTracker;

    /// A pointer to the slingshot in the level
    std::shared_ptr<Slingshot> mSlingShot;

    Angry * mFlyingAngry = nullptr;

    bool mKill = false;

    int leftOverSparties = -1;

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

    void SetLevel(const int &level) { mCurrentLevel = level; } ;


    void Add(std::shared_ptr<Item> item);

    void InstallPhysics();

    void SetEnd(const bool &end) { mLevelEnd = end; } ;

    bool mAddTotal = true;

    bool mControlDisplay = true;

    double mTimeDuration = 0;

    Angry* HitTest(int x, int y);

    void ReloadSlingshot();

    void SetSlingShot(std::shared_ptr<Slingshot> slingshot);

    void NextLoad();

    bool isDone(){
        return mKill;
    }

    void SetFlyingSparty(Angry* angry) {mFlyingAngry = angry;};

    Angry* GetFlyingSparty() {return mFlyingAngry;};
};

#endif //ANGRYSPARTY_PLAYINGAREA_H
