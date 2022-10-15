/**
 * @file SpartyView.cpp
 * @author Ian Valdovinos Granados, Zhiqiang ni, Milan Mihailovic
 */
#include "pch.h"
#include "SpartyView.h"
#include <wx/dcbuffer.h>

/// Frame duration in milliseconds
const int FrameDuration = 30;

/**
 * Initialize the Sparty view class.
 * @param parent The parent window for this class
 */
void SpartyView::Initialize(wxFrame* parent)
{
    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);

    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &SpartyView::OnPaint, this);
    Bind(wxEVT_TIMER, &SpartyView::OnTimer, this);

    //todo: not complete code
}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void SpartyView::OnPaint(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;

    mScoreDisplay.OnPaint(&dc);
    mScoreDisplay.Update(elapsed, &dc);
}
/**
 * todo: can someone add comments here
 * @param event
 */
void SpartyView::OnTimer(wxTimerEvent &event)
{
    Refresh();
}