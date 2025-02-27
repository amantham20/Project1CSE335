/**
 * @file TransitionalText.cpp
 * @author Milan Mihailovic
 */

#include "pch.h"
#include "TransitionalText.h"
#include "Level.h"

/**
 * Transitional Text Constructor
 * @param level level shared pointer
 * @param x double x
 * @param y double y
 */
TransitionalText::TransitionalText(std::shared_ptr<Level> level, double x,double y) : PositionalItem(level)
{
    PositionalItem::SetX(x);
    PositionalItem::SetY(y);
}

/**
 * Draws the Transitional Text
 * @param graphics object
 * @param level integer value
 * @param end boolean value
 */
void TransitionalText::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, const int &level, const bool &end)
{
    auto tLevel = Item::GetLevel();
    auto wid = tLevel->GetWidth() * Consts::MtoCM;
    auto hit = tLevel->GetHeight()  * Consts::MtoCM;

    graphics->PushState();
    graphics->Scale(1, -1);
    wxFont font(wxSize(0, 80),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);
    graphics->SetFont(font, wxColour(0,0,255));
//    graphics->DrawText("Level X Begin", PositionalItem::getX() - wid - 245, PositionalItem::getY() - hit + 345);
    double textWidth = 0;
    double textHeight = 0;
    graphics->GetTextExtent(L"Level 1 Begin", &textWidth, &textHeight);

    if (!end)
    {
        graphics->DrawText("Level " + wxString::FromDouble(level, 0) + " Begin", 0-textWidth/2, -hit/2-textHeight/2);
        graphics->GetTextExtent(L"Use the spacebar for special ablity", &textWidth, &textHeight);
        graphics->DrawText("Use the spacebar for special ablity", 0-textWidth/2, -hit/2-textHeight/2-200);

    }
    else
    {
        graphics->GetTextExtent(L"Level End!", &textWidth, &textHeight);
        graphics->DrawText(L"Level End!", 0-textWidth/2, -hit/2-textHeight/2);
    }

    graphics->PopState();
}
