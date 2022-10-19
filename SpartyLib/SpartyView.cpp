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

using namespace std;

/// Frame duration in seconds
const double FrameDuration = 1.0/60.0;

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
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SpartyView::OnFileSaveAs, this, wxID_SAVEAS);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SpartyView::OnFileOpen, this, wxID_OPEN);
    //todo: not complete code


    // Load Level files
    LoadLevels();
}

/**
 * Parses the Level xml files to populate SpartyGame mItems
 */
void SpartyView::LoadLevels()
{
    // Load Level 0
    wxString levelZeroFilename = L"../levels/level0.xml";
    mSpartyGame.Load(levelZeroFilename);

    // Load Level 1

    // Load Level 2

    // Load Level 3


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

    mScoreDisplay.OnPaint(&dc);
    mScoreDisplay.Update(elapsed, &dc);
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
 * Handle the File>Save As menu option
 * @param event The menu event
 */
void SpartyView::OnFileSaveAs(wxCommandEvent& event)
{
    wxFileDialog saveFileDialog(this, _("Save Level file"), "", "",
                                "Level Files (*.sparty)|*.sparty", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    auto filename = saveFileDialog.GetPath();
    //todo not finished
}

/**
 * File>Open menu handler
 * @param event Menu event
 */
void SpartyView::OnFileOpen(wxCommandEvent& event)
{
    wxFileDialog loadFileDialog(this, _("Load Level file"), "", "",
                                "Level Files (*.sparty)|*.sparty", wxFD_OPEN);
    if (loadFileDialog.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    auto filename = loadFileDialog.GetPath();
    //todo not finished
    Refresh();
}