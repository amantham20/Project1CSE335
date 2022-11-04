/**
 * @file HelmetSparty.cpp
 * @author Ian Valdovinos Granados
 */

#include "pch.h"
#include "HelmetSparty.h"


/// The radius in meters
const double HelmetSpartyRadius = 0.25;

/// The mPullDirection factor for Helmet Sparty
const float HelmetSpartyVelocityFactor = 20.0;

/**
 * Constructor for HelmetSparty
 * @param level
 */
HelmetSparty::HelmetSparty(std::shared_ptr<Level> level) : Angry(level)
{
    Angry::SetRadius(HelmetSpartyRadius);
    Angry::SetVelocityFactor(HelmetSpartyVelocityFactor);
}

/**
 * Loading the item from the XML node
 * @param node
 */
void HelmetSparty::XmlLoad(wxXmlNode *node)
{
    Item::SetImageName(L"images/helmet-sparty.png");

}

/**
 * Set location of GruffSparty
 * @param x
 * @param y
 */
void HelmetSparty::SetLocation(double x, double y)
{
    PositionalItem::SetLocation(x, y);
}

/**
 * Draws the GruffSparty given the graphics context
 * @param graphics
 */
void HelmetSparty::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Angry::OnDraw(graphics);
}