/**
 * @file SpartyView.cpp
 * @author Ian Valdovinos Granados, Zhiqiang ni, Milan Mihailovic
 */
#include "pch.h"
#include "SpartyView.h"
#include <wx/dcbuffer.h>
#include "Consts.h"
#include "stdio.h"
#include "SpartyGame.h"
#include "ids.h"
#include "Level.h"
#include "HelmetSparty.h"
#include "GruffSparty.h"

using namespace std;

//todo move to conns class
/// Frame duration in seconds
const double FrameDuration = 1.0/60.0;

///the x location for score display
const int positionX = 10;

///the Y location for score display
const int positionY = 10;



/**
 * Initialize the Sparty view class.
 * @param parent The parent window for this class
 */
void SpartyView::Initialize(wxFrame* parent)
{
    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration*Consts::SecToMillisec);

    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &SpartyView::OnPaint, this);
    Bind(wxEVT_TIMER, &SpartyView::OnTimer, this);


    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SpartyView::OnLevelOpen, this,IDM_LEVEL0);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SpartyView::OnLevelOpen, this,IDM_LEVEL1);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SpartyView::OnLevelOpen, this,IDM_LEVEL2);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SpartyView::OnLevelOpen, this,IDM_LEVEL3);
    //todo: not complete code

    // Load Level files
    wxString levelZeroFilename = L"levels/level1.xml";
    mSpartyGame.Load(levelZeroFilename);
    Refresh();
}


/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void SpartyView::OnPaint(wxPaintEvent& event)
{

    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time() * Consts::MillisecToSec;
    auto elapsed = (double)(newTime - mTime) * Consts::MillisecToSec;


    while(mTime < newTime)
    {
        mTime += FrameDuration;
//        mSpartyGame.Update(FrameDuration);
    }

    mTime = newTime;

    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();
    auto size = GetClientSize();

    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create( dc ));
    graphics->SetInterpolationQuality(wxINTERPOLATION_BEST);

    mSpartyGame.OnDraw(graphics, size.GetWidth(), size.GetHeight());


}
/**
 * Handles the timer event
 * @param event
 */
void SpartyView::OnTimer(wxTimerEvent &event)
{
    Refresh();
}

/**
 * Level>Open level handler
 * @param event Menu event
 */
void SpartyView::OnLevelOpen(wxCommandEvent& event)
{
    //todo: this is not the right code to use
    switch (event.GetId())
    {
        case IDM_LEVEL0:
        {
            mSpartyGame.SetLevel(0);
            break;
        }
        case IDM_LEVEL1:
        {
            mSpartyGame.SetLevel(1);
            break;
        }
        case IDM_LEVEL2:
        {
            mSpartyGame.SetLevel(2);
            break;
        }
        case IDM_LEVEL3:
        {
            mSpartyGame.SetLevel(3);
            break;
        }
    }
    Refresh();
}

/**
 * Draw the sparty
 * @param dc The device context to draw on
 */
//void SpartyView::OnDraw(wxDC *dc)
//{
//
//}
