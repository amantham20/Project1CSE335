/**
 * @file Background.cpp
 * @author Aman Dhruva Thamminana
 */

#include "pch.h"
#include "Background.h"
#include "Picture.h"
#include "Consts.h"


//Background::Background(Level *level) : Item(level)
//{
//
//}

void Background::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);
}

void Background::OnDraw(std::shared_ptr<wxGraphicsContext> graphics){
    auto tLevel = Item::GetLevel();
    auto wid = tLevel->GetWidth() * Consts::MtoCM;
    auto hit = tLevel->GetHeight()  * Consts::MtoCM;

    graphics->PushState();
    graphics->Scale(1, -1);
    graphics->DrawBitmap(*Item::GetBitMap(),
            -wid/2,
            -hit,
            wid, hit);

    graphics->PopState();
}

void Background::SetLocation(double x, double y)
{
}
