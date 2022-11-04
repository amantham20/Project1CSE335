/**
 * @file SpartyView.h
 * @author Ian Valdovinos Granados, zhiqiang ni, Milan Mihailovic
 *
 * Window class in which the game is drawn.
 */

#ifndef ANGRYSPARTY_SPARTYVIEW_H
#define ANGRYSPARTY_SPARTYVIEW_H

#include "b2_math.h"
#include "SpartyGame.h"

class Angry;
/**
 * View class used to display game on screen
 */
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

    /// Item that the user is currently grabbing
    Angry* mGrabbedSparty;

    /// Boolean that keeps track of whether we are in debug mode or not
    bool mDebug = false;

    void LoadLevels();

    /// Direction in which the angry sparty is being pulled
    b2Vec2 mPullDirection = b2Vec2(0,0);

    /// True if the angry sparty is on dive, false otherwise.
    bool mDive = false;

public:
    void Initialize(wxFrame* parent);

    void OnTimer(wxTimerEvent &event);

    void OnLevelOpen(wxCommandEvent &event);

    void OnDebugMode(wxCommandEvent& event);
    void OnUpdateDebugMode(wxUpdateUIEvent& event);

    void OnLeftDown(wxMouseEvent& event);
    void OnMouseMove(wxMouseEvent& event);
    void OnLeftUp(wxMouseEvent &event);

    /**
     * Stop the timer so the window can close
     */
    void Stop() {mTimer.Stop();}

    void OnSpaceButton(wxKeyEvent& event);
};

#endif //ANGRYSPARTY_SPARTYVIEW_H
