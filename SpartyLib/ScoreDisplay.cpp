/**
 * @file ScoreDisplay.cpp
 * @author Ian Valdovinos Granados, zhiqiang ni
 */

#include "pch.h"
#include "ScoreDisplay.h"


///the x location for score display
const int positionX = 10;
///the Y location for score display
const int positionY = 10;

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
    dc->DrawText(wxString::FromDouble(mScore.GetScore(), 0), positionX,positionY);
}

void ScoreDisplay::Update(double elapsed, wxDC *dc)
{
    OnPaint(dc);
    //todo: delete this lane this is just for testing
    mScore.AddScore(1);
}