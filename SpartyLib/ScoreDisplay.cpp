/**
 * @file ScoreDisplay.cpp
 * @author Ian Valdovinos Granados, zhiqiang ni
 */

#include "pch.h"
#include "ScoreDisplay.h"
#include "Score.h"
#include "Consts.h"

/**
 * Constructor
 * @param level Level the score dusplay is in
 * @param score Score to display
 * @param x x-coordinate of the score display
 * @param y y-coordinate of the score display
 */
ScoreDisplay::ScoreDisplay(Level *level, std::shared_ptr<Score> score, double x, double y) : PositionalItem(level)
{
    mScore = score;
    PositionalItem::setX(x);
    PositionalItem::setY(y);
}

/**
 * Draws the display on screen.
 * @param graphics Graphics context to use to draw the score display.
 */
void ScoreDisplay::OnDraw(std::shared_ptr<wxGraphicsContext> graphics){
    auto tLevel = Item::GetLevel();
    auto wid = tLevel->GetWidth() * Consts::MtoCM;
    auto hit = tLevel->GetHeight()  * Consts::MtoCM;
    graphics->PushState();
    graphics->Scale(1, -1);
    wxFont font(wxSize(0, 30),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    graphics->SetFont(font, wxColour(255,0,0));
    graphics->DrawText(wxString::FromDouble(mScore->GetScore(), 0),
                       PositionalItem::getX() - wid/2 , PositionalItem::getY() - hit);
    graphics->PopState();
}

/**
 * Function called to update the ScoreDisplay on screen
 * @param elapsed Time elapsed since the last call to Update
 * @param graphics Graphics context used to draw this score display.
 */
void ScoreDisplay::Update(std::shared_ptr<wxGraphicsContext> graphics)
{
    OnDraw(graphics);
    //todo: delete this lane this is just for testing
    mScore->AddScore(1);
}