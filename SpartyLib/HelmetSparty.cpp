/**
 * @file HelmetSparty.cpp
 * @author Ian Valdovinos Granados
 */

#include "pch.h"
#include "HelmetSparty.h"

HelmetSparty::HelmetSparty(Level *level) : Angry(level)
{

}

void HelmetSparty::XmlLoad(wxXmlNode *node)
{
    Item::SetImageName(L"images/helmet-sparty.png");

}

void HelmetSparty::SetLocation(double x, double y)
{
    PositionalItem::SetLocation(x, y);
}

void HelmetSparty::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Angry::OnDraw(graphics);
}