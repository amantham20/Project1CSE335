/**
 * @file HelmetSparty.cpp
 * @author Ian Valdovinos Granados
 */

#include "pch.h"
#include "HelmetSparty.h"


/// The radius in meters
const double HelmetSpartyRadius = 0.25;

/// The velocity factor for Helmet Sparty
const float HelmetSpartyVelocityFactor = 20.0;

HelmetSparty::HelmetSparty(std::shared_ptr<Level> level) : Angry(level)
{
    Angry::SetRadius(HelmetSpartyRadius);
    Angry::SetVelocityFactor(HelmetSpartyVelocityFactor);
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