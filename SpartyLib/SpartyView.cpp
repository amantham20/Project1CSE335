/**
 * @file SpartyView.cpp
 * @author Ian Valdovinos Granados, Zhiqiang ni, Milan Mihailovic
 */
#include "pch.h"

#include <wx/dcbuffer.h>

#include "SpartyView.h"
#include "Consts.h"
#include "stdio.h"
#include "SpartyGame.h"
#include "ids.h"
#include "Level.h"
#include "HelmetSparty.h"
#include "GruffSparty.h"
#include "SpartyTracker.h"
#include "stdio.h"
#include "sstream"

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

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SpartyView::OnLevelOpen, this, IDM_LEVEL0);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SpartyView::OnLevelOpen, this, IDM_LEVEL1);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SpartyView::OnLevelOpen, this, IDM_LEVEL2);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SpartyView::OnLevelOpen, this, IDM_LEVEL3);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SpartyView::OnDebugMode, this, IDM_DEBUG);
    parent->Bind(wxEVT_UPDATE_UI, &SpartyView::OnUpdateDebugMode, this, IDM_DEBUG);
    //todo: not complete code

    // Bind mouse event handlers
    Bind(wxEVT_LEFT_DOWN, &SpartyView::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &SpartyView::OnLeftUp, this);
    Bind(wxEVT_MOTION, &SpartyView::OnMouseMove, this);

    // Load Level files
    LoadLevels();

    Refresh();
}

/**
 * load all the level into a vector
 */

//TODO: remove next line
//This function is complete
void SpartyView::LoadLevels()
{
    wxString levelZeroFilename = L"levels/level0.xml";
    mSpartyGame.Load(levelZeroFilename);

    wxString levelOneFilename = L"levels/level1.xml";
    mSpartyGame.Load(levelOneFilename);

    wxString levelTwoFilename = L"levels/level2.xml";
    mSpartyGame.Load(levelTwoFilename);

    wxString levelThreeFilename = L"levels/level3.xml";
    mSpartyGame.Load(levelThreeFilename);
}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void SpartyView::OnPaint(wxPaintEvent& event)
{

    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time()*Consts::MillisecToSec;
    auto elapsed = (double) (newTime-mTime)*Consts::MillisecToSec;

    while (mTime<newTime) {
        mTime += FrameDuration;
        mSpartyGame.Update(FrameDuration);
    }

    mTime = newTime;

    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();
    auto size = GetClientSize();

    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));
    graphics->SetInterpolationQuality(wxINTERPOLATION_BEST);

    mSpartyGame.OnDraw(graphics, size.GetWidth(), size.GetHeight());

    if (mDebug) {
        // Draw outlines around each of the on-screen item
        //todo:: need visitor? Nope should be fine
        //todo:: thing broken inverted debug draw
//        graphics->PushState();
//        graphics->Scale(1,-1);
//        mSpartyGame.DebugOnDraw(graphics);
//        graphics->PopState();

    }
}

/**
 * Handles the timer event
 * @param event
 */
void SpartyView::OnTimer(wxTimerEvent& event)
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
    switch (event.GetId()) {
    case IDM_LEVEL0: {
        mSpartyGame.SetLevel(0);
        break;
    }
    case IDM_LEVEL1: {
        mSpartyGame.SetLevel(1);
        break;
    }
    case IDM_LEVEL2: {
        mSpartyGame.SetLevel(2);
        break;
    }
    case IDM_LEVEL3: {
        mSpartyGame.SetLevel(3);
        break;
    }
    default: {
        mSpartyGame.SetLevel(0);
        break;
    }
    }
    mSpartyGame.Reset();
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

void SpartyView::OnDebugMode(wxCommandEvent& event)
{
    mDebug = !mDebug;
    mSpartyGame.SetDebug(mDebug);
}

/**
 * Update handler for View>Outlines menu option
 * @param event Update event
 */
void SpartyView::OnUpdateDebugMode(wxUpdateUIEvent& event)
{
    event.Check(mDebug);
}

/**
 * Handle the left mouse button down event
 * @param event
 */
void SpartyView::OnLeftDown(wxMouseEvent& event)
{
    mGrabbedSparty = mSpartyGame.HitTest(event.GetX(), event.GetY());
}

/**
* Handle the left mouse button down event
* @param event
*/
void SpartyView::OnLeftUp(wxMouseEvent& event)
{
    OnMouseMove(event);
}

/**
* Handle the left mouse button down event
* @param event
*/
void SpartyView::OnMouseMove(wxMouseEvent& event)
{
    // Get the scale, x offset and y offset of the game.
    double scale = mSpartyGame.GetScale();
    double xOffset = mSpartyGame.GetXOffset();
    double yOffset = mSpartyGame.GetYOffset();

    // Convert the event x and y coordinates from pixel unites to centimeters.
    double metersX = (event.m_x/scale-xOffset)/Consts::MtoCM;
    double metersY = (event.m_y/-scale-yOffset)/Consts::MtoCM;

    // See if an angry sparty is currently being moved by the mouse
    if (mGrabbedSparty!=nullptr) {
        // Get position of the slingshot loading spot
        auto slingshotLoadingPosition = mSpartyGame.GetSlingshotLoadingPosition();

        // If the angry sparty is being moved, we only continue to
        // move it while the left button is down.
        if (event.LeftIsDown()) {

            // Get the position of the angry sparty and the loading position of the slingshot. Calculate angle between vectors.
            auto spartyPosition = mGrabbedSparty->GetPosition();
            double thetaRad = atan2(metersY-slingshotLoadingPosition.y, metersX-slingshotLoadingPosition.x);
            double thetaDeg = thetaRad * Consts::RtoD;

            //
            if (thetaDeg >= -95 && thetaDeg <= 120)
            {
//                auto limitY = tan(thetaRad)*metersX;
//                mGrabbedSparty->SetLocation(metersX, limitY);
            } else
            {
                mGrabbedSparty->SetLocation(metersX, metersY);
            }
        }
        else {
            // When the left button is released, we release the
            // angry sparty.
            // todo: Angry launch code
            mGrabbedSparty->SetLocation(slingshotLoadingPosition.x, slingshotLoadingPosition.y);
            mGrabbedSparty = nullptr;
        }

        // Force the screen to redraw
        Refresh();
    }
}