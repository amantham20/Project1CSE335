/**
 * @file Score.h
 * @author Ian Valdovinos Granados
 *
 * Class that keeps track of the current score for the game or a specific level
 */

#ifndef ANGRYSPARTY_SCORE_H
#define ANGRYSPARTY_SCORE_H

/**
 * Class that keeps track of the current score for the game or a specific level
 */
class Score {
private:
    /// Current score
    int mScore = 0;

public:
    Score(int score);
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
};

#endif //ANGRYSPARTY_SCORE_H
