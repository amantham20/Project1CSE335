/**
 * @file ScoreDisplay.h
 * @author Ian Valdovinos Granados, zhiqiang ni
 *
 * Class display the score
 */

#ifndef ANGRYSPARTY_SCOREDISPLAY_H
#define ANGRYSPARTY_SCOREDISPLAY_H

#include "Score.h"

class ScoreDisplay {
private:
    ///an object that describes score
    Score mScore;
public:
    void OnPaint(wxDC *dc);

    void Update(double elapsed, wxDC *dc);
};


#endif //ANGRYSPARTY_SCOREDISPLAY_H
