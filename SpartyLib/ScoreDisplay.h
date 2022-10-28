/**
 * @file ScoreDisplay.h
 * @author Ian Valdovinos Granados, zhiqiang ni
 *
 * Class display the score
 */

#ifndef ANGRYSPARTY_SCOREDISPLAY_H
#define ANGRYSPARTY_SCOREDISPLAY_H

#include "PositionalItem.h"
#include "ItemVisitor.h"

class Score;

/**
 * Class in charge of displaying a score counter
 */
class ScoreDisplay : public PositionalItem{
private:
    ///an object pointer
    std::shared_ptr<Score> mScore;
public:
    ScoreDisplay(std::shared_ptr<Level> level, std::shared_ptr<Score>, double x, double y);

    void Update(std::shared_ptr<wxGraphicsContext> graphics);

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Accept(std::shared_ptr<ItemVisitor> visitor) override { visitor->VisitScoreDisplay(this); }
};


#endif //ANGRYSPARTY_SCOREDISPLAY_H
