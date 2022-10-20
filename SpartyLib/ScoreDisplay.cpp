/**
 * @file ScoreDisplay.cpp
 * @author Ian Valdovinos Granados, zhiqiang ni
 */

#include "pch.h"
#include "ScoreDisplay.h"
#include "Score.h"

ScoreDisplay::ScoreDisplay(Score *score, double x, double y)
{
    mScore = score;
    mPositionY = y;
    mPositionX = x;
}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void ScoreDisplay::OnPaint(wxDC *dc)
{
    //score view
    wxFont font(wxSize(0, 20),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    dc->SetFont(font);
    //todo: adjust the color and font
    dc->SetTextForeground(wxColour(0, 64, 0));
    dc->DrawText(wxString::FromDouble(mScore->GetScore(), 0), mPositionX,mPositionY);
}

void ScoreDisplay::Update(double elapsed, wxDC *dc)
{
    OnPaint(dc);
    //todo: delete this lane this is just for testing
    mScore->AddScore(1);
}