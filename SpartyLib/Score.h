/**
 * @file Score.h
 * @author Ian Valdovinos Granados, zhiqing ni
 *
 * Class that keeps track of the current score for the game or a specific level
 */

#ifndef ANGRYSPARTY_SCORE_H
#define ANGRYSPARTY_SCORE_H

#include "PositionalItem.h"

/**
 * Class that keeps track of the current score for the game or a specific level
 */
class Score : public PositionalItem{
private:
    /// Current score
    int mScore = 0;

public:
    Score(std::shared_ptr<Level> level,double score, double x,double y);
    /**
     * Gets the current score
     * @return Current score
     */
    int GetScore() {return mScore;}

    /**
     * Adds to the current score
     * @param score Score to add to the Score
     */
    void AddScore(int score) {mScore += score; }

    /**
     * set score to 0
     */
    void Reset() { mScore = 0; }

    /**
     * Visitor declaration for Score
     * @param visitor
     */
    void Accept(std::shared_ptr<ItemVisitor> visitor){};
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics);
};

#endif //ANGRYSPARTY_SCORE_H
