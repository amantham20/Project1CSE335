/**
 * @file Background.cpp
 * @author Aman Dhruva Thamminana
 */

#include "pch.h"
#include "Background.h"
#include "Picture.h"
#include "Consts.h"
#include "Level.h"

Background::Background(std::shared_ptr<Level> level) : Item(level)
{

}

/**
 * Load function for Background
 *
 * Upcalls Item XmlLoad function
 *
 * @param node XMLnode to get attributes from.
 *
 * @author Aman Dhruva Thamminana
 */
void Background::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);
}

/**
 * Draws the background image
 *
 * gets Level using an upcall getter from `Item`.
 * gets the bitmap using an upcall from `Item`.
 *
 * @param graphics Graphics that is used to draw the image.
 *
 * @author Aman Dhruva Thamminana
 */
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


/**
 *
 * @param x
 * @param y
 *
 * @author (John Doe)
 */
void Background::SetLocation(double x, double y)
{
}
