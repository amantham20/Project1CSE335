/**
 * @file Score.cpp
 * @author Ian Valdovinos Granados, zhiqiang ni, Milan Mihailovic
 *
 */

#include "pch.h"
#include "Score.h"
#include "Level.h"
/**
 * constructor
 * @param score
 */
Score::Score(std::shared_ptr<Level> level, double score, double x,double y) : PositionalItem(level)
{
    mScore = score;
    PositionalItem::setX(x);
    PositionalItem::setY(y);
}

void Score::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
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
    graphics->DrawText(wxString::FromDouble(mScore, 0),
            PositionalItem::getX() - wid/2 , PositionalItem::getY() - hit);
    graphics->PopState();
}