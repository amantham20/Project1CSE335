/**
 * @file SpartyView.h
 * @author Ian Valdovinos Granados, zhiqiang ni, Milan Mihailovic
 *
 * Window class in which the game is drawn.
 */

#ifndef ANGRYSPARTY_SPARTYVIEW_H
#define ANGRYSPARTY_SPARTYVIEW_H

#include "ScoreDisplay.h"
#include "b2_math.h"
#include "SpartyGame.h"

class SpartyView : public wxWindow {
private:
    void OnPaint(wxPaintEvent& event);

    /// The timer that allows for animation
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    double mTime = 0;

    ///an object describe the sparty game
    SpartyGame mSpartyGame;



    void LoadLevels();
public:
    void Initialize(wxFrame* parent);

    void onNewLevel(wxCommandEvent &event);

    void OnTimer(wxTimerEvent &event);

    void OnFileSaveAs(wxCommandEvent &event);

    void OnFileOpen(wxCommandEvent &event);

//    void OnDraw(wxDC *dc);
};

#endif //ANGRYSPARTY_SPARTYVIEW_H
