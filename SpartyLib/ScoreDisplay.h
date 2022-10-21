/**
 * @file ScoreDisplay.h
 * @author Ian Valdovinos Granados, zhiqiang ni
 *
 * Class display the score
 */

#ifndef ANGRYSPARTY_SCOREDISPLAY_H
#define ANGRYSPARTY_SCOREDISPLAY_H

#include "PositionalItem.h"

class Score;

class ScoreDisplay : public PositionalItem{
private:
    ///an object pointer
    Score *mScore;
public:
    ScoreDisplay(std::shared_ptr<Level> level, Score *score, double x, double y);

    void Update(double elapsed, std::shared_ptr<wxGraphicsContext> graphics);

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics);
};


#endif //ANGRYSPARTY_SCOREDISPLAY_H
