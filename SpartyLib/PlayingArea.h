/**
 * @file PlayingArea.h
 * @author Rajmeet Singh Chandok
 *
 *
 */

#ifndef ANGRYSPARTY_PLAYINGAREA_H
#define ANGRYSPARTY_PLAYINGAREA_H

#include "Item.h"
#include "SpartyGame.h"

class PlayingArea {
private:
    /// Current Score
    int mCurrentScore;

    SpartyGame mSpartyGame;
    /// Items copied from Level
    std::vector<std::shared_ptr<Item>> mItems;

    std::shared_ptr<Physics> mPhysics;
public:
    /// Default Constructor
    PlayingArea() = delete;
    PlayingArea(std::vector<std::shared_ptr<Item>> items);

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
    /**
     * Setter for current score
     *
     */
    void SetCurrentScore(int score) { mCurrentScore = score; }

    void DebugOnDraw(std::shared_ptr<wxGraphicsContext> graphics);
};

#endif //ANGRYSPARTY_PLAYINGAREA_H
