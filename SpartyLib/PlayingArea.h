/**
 * @file PlayingArea.h
 * @author Rajmeet Singh Chandok
 *
 *
 */

#ifndef ANGRYSPARTY_PLAYINGAREA_H
#define ANGRYSPARTY_PLAYINGAREA_H

#include "Item.h"

class PlayingArea {
private:
    /// Current Score
    int mCurrentScore;

    /// Items copied from Level
    std::vector<std::shared_ptr<Item>> mItems;
public:
    /// Default Constructor
    PlayingArea();

    /// Destructor
    ~PlayingArea(){}

    /// Copy constructor (disabled)
    PlayingArea(const PlayingArea &) = delete;

    /**
     * Getter for current score
     */
    int GetCurrentScore() { return mCurrentScore; }

    /**
     * Setter for current score
     *
     */
    void SetCurrentScore(int score) { mCurrentScore = score; }

};

#endif //ANGRYSPARTY_PLAYINGAREA_H
