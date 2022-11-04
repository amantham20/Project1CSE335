/**
 * @file GruffSparty.cpp
 * @author Ian Valdovinos Granados, Rajmeet Singh Chandok
 */

#include "pch.h"
#include "GruffSparty.h"
#include "Level.h"
#include "Slingshot.h"

/// The radius in meters
const double GruffSpartyRadius = 0.25;

/// The mPullDirection factor for Gruff Sparty
const float GruffSpartyVelocityFactor = 12.0;


/**
 * Constructor for GruffSparty
 * @param level
 */
GruffSparty::GruffSparty(std::shared_ptr<Level> level) : Angry(level)
{

    Angry::SetRadius(GruffSpartyRadius);
    Angry::SetVelocityFactor(GruffSpartyVelocityFactor);
}

/**
 * Loading the item from the XML node
 * @param node
 */
void GruffSparty::XmlLoad(wxXmlNode *node)
{
    Item::SetImageName(L"images/gruff-sparty.png");

}

/**
 * Set location of GruffSparty
 * @param x
 * @param y
 */
void GruffSparty::SetLocation(double x, double y)
{
    PositionalItem::SetLocation(x, y);
}

/**
 * Draws the GruffSparty given the graphics context
 * @param graphics
 */
void GruffSparty::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Angry::OnDraw(graphics);

}