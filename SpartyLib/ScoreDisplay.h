/**
 * @file ScoreDisplay.h
 * @author Ian Valdovinos Granados, zhiqiang ni
 *
 * Class display the score
 */

#ifndef ANGRYSPARTY_SCOREDISPLAY_H
#define ANGRYSPARTY_SCOREDISPLAY_H

class Score;

class ScoreDisplay {
private:
    ///an object pointer
    Score *mScore;
    ///x posistion for displaying
    double mPositionX;
    ///Y posistion for displaying
    double mPositionY;
public:
    ScoreDisplay(Score *score, double x, double y);

    void OnPaint(wxDC *dc);

    void Update(double elapsed, wxDC *dc);
};


#endif //ANGRYSPARTY_SCOREDISPLAY_H
