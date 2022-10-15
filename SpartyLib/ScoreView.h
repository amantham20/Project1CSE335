/**
 * @file ScoreView.h
 * @author Ian Valdovinos Granados,
 *
 * Class that keeps track of the current score for the game or a specific level
 */

#ifndef ANGRYSPARTY_SCOREVIEW_H
#define ANGRYSPARTY_SCOREVIEW_H

/**
 * Class that keeps track of the current score for the game or a specific level
 */
class ScoreView {
private:
    /// Current score
    int mScore = 0;

public:
    /**
     * Gets the current score
     * @return Current score
     */
    int GetScore() {return mScore;}

    /**
     * Sets the score to a specified value
     * @param newScore New score to set the ScoreView to
     */
    void SetScore(int newScore) {mScore = newScore; }

    /**
     * Adds to the current score
     * @param score Score to add to the ScoreView
     */
    void AddScore(int score) {mScore += score; }
};

#endif //ANGRYSPARTY_SCOREVIEW_H
