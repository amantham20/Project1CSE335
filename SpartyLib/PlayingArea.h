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

class PlayingArea {
private:
    /// Current Score
    int mCurrentScore;
    SpartyGame mSpartyGame;
    /// Items copied from Level
    std::vector<std::shared_ptr<Item>> mItems;

    std::shared_ptr<Physics> mPhysics;
    std::shared_ptr<Score> mScore;
    std::shared_ptr<Score> mTotalScore;
public:
    std::vector<std::shared_ptr<Item>> GetItem(){ return mItems; };

    /// Default Constructor
    PlayingArea() = delete;
    PlayingArea(std::shared_ptr<Level> level, std::shared_ptr<Score> totalScore);

    /**
     * Destructor
     */
    ~PlayingArea(){}

    /// Copy constructor (disabled)
    PlayingArea(const PlayingArea &) = delete;

    /**
     * Getter for current score
     */
    int GetCurrentScore() { return mCurrentScore; }
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    void DebugOnDraw(std::shared_ptr<wxGraphicsContext> graphics);

    void Accept(std::shared_ptr<ItemVisitor> visitor);

    void Update(double frameDuration);
};

#endif //ANGRYSPARTY_PLAYINGAREA_H
