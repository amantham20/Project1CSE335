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
    Bind(wxEVT_KEY_DOWN, &SpartyView::OnSpaceButton, this);

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
 * Handle the space button down event
 * @param event
 */
void SpartyView::OnSpaceButton(wxKeyEvent& event)
{
    wxChar unicode = event.GetUnicodeKey();

    // Space bar has an ASCII value of 32
    if ( unicode == 32 )
    {
        mGrabbedSparty = mSpartyGame.GetFlyingSparty();
        if (mGrabbedSparty!=nullptr)
        {
            if (mDive)
            {
                mGrabbedSparty->Dive();
                mDive = false;
            }
        }
    }
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

    // Get position of the slingshot loading spot
    auto slingshotLoadingPosition = mSpartyGame.GetSlingshotLoadingPosition();

    // See if an angry sparty is currently being moved by the mouse
    if (mGrabbedSparty!=nullptr) {

        // If the angry sparty is being moved, we only continue to
        // move it while the left button is down.

        // todo: change hard coded value to the projectile direction and velocity

        if (event.LeftIsDown()) {
            auto spartyPosition = mGrabbedSparty->GetPosition();

            mVelocity = b2Vec2((abs(spartyPosition.x)-abs(slingshotLoadingPosition.x)), (abs(slingshotLoadingPosition.y)-abs(spartyPosition.y)));

            //  Calculate angle between x-axis and mouse position vector
            double thetaRad = atan2(metersY-slingshotLoadingPosition.y, metersX-slingshotLoadingPosition.x);
            double thetaDeg = thetaRad * Consts::RtoD;

            // Check if the slingshot is being pulled in the right direction
            if (thetaDeg >= -95 && thetaDeg <= 120)
            {
                // The slingshot is being pulled in the wrong direction
//                auto limitY = tan(thetaRad)*metersX;
//                mGrabbedSparty->SetLocation(metersX, limitY);
            } else
            {
                // The slingshot is being pulled in the correct direction
                // Calculate distance from the mouse to the slingshot loading spot
                double distance = sqrt(pow((metersX - slingshotLoadingPosition.x), 2) + pow((metersY - slingshotLoadingPosition.y), 2));

                // Get the maximum length of the rubber band
                int rubberBandLength = mSpartyGame.GetRubberBandLength();

                // Check if the rubber band is being pulled to its maximum length
                if (distance <= rubberBandLength)
                {
                    mGrabbedSparty->SetLocation(metersX, metersY);
                    auto position = mGrabbedSparty->GetPosition();
//                    std::cout << position.x << ", " << position.y << std::endl;
                } else
                {
                    // The slingshot is being pulled to its maximum length
                    double xMax = slingshotLoadingPosition.x - rubberBandLength*cos(Consts::Pi -abs(thetaRad));
                    double yMax = 0;
                    if (thetaRad > 0 )
                    {
                        yMax = slingshotLoadingPosition.y + rubberBandLength*sin(Consts::Pi -abs(thetaRad));
                    } else
                    {
                        yMax = slingshotLoadingPosition.y - rubberBandLength*sin(Consts::Pi -abs(thetaRad));
                    }
                    mGrabbedSparty->SetLocation(xMax, yMax);
                }
            }
        }
        else {
            // When the left button is released, we release the
            // angry sparty.
            // todo: Angry launch code
//            mGrabbedSparty->SetLocation(slingshotLoadingPosition.x, slingshotLoadingPosition.y);
            if (mGrabbedSparty != NULL)
            {
                mGrabbedSparty->SetLoadedInSlingshot(false);
                mSpartyGame.ClearLoadedSparty();
                mGrabbedSparty->Launch(mVelocity);
                mDive = true;
                mSpartyGame.SetFlyingSparty(mGrabbedSparty);
                mGrabbedSparty = nullptr;
            }
        }

        // Force the screen to redraw
        Refresh();
    } 
}