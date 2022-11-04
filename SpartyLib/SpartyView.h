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
    /// OnPaint event
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

    /// Boolean for Debug mode
    bool mDebug = false;

    /// Used for special feature should make the sparty dive
    bool mDive = false;

    /// Initialize pull direction
    b2Vec2 mPullDirection = b2Vec2(0,0);

    void LoadLevels();



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
