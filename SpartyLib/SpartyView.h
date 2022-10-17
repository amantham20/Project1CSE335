/**
 * @file SpartyView.h
 * @author Ian Valdovinos Granados, zhiqiang ni, Milan Mihailovic
 *
 * Window class in which the game is drawn.
 */

#ifndef ANGRYSPARTY_SPARTYVIEW_H
#define ANGRYSPARTY_SPARTYVIEW_H

#include "ScoreDisplay.h"

class SpartyView : public wxWindow {
private:
    void OnPaint(wxPaintEvent& event);

    ///an object describe scoredisplay
    ScoreDisplay mScoreDisplay;

    /// The timer that allows for animation
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    long mTime = 0;
public:
    void Initialize(wxFrame* parent);

    void onNewLevel(wxCommandEvent &event);

    void OnTimer(wxTimerEvent &event);

    void OnFileSaveAs(wxCommandEvent &event);

    void OnFileOpen(wxCommandEvent &event);
};

#endif //ANGRYSPARTY_SPARTYVIEW_H
