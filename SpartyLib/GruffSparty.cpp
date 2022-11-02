/**
 * @file GruffSparty.cpp
 * @author Ian Valdovinos Granados
 */

#include "pch.h"
#include "GruffSparty.h"
#include "Level.h"
#include "stdio.h"
#include "Slingshot.h"

/// The radius in meters
const double GruffSpartyRadius = 0.25;

/// The velocity factor for Gruff Sparty
const float GruffSpartyVelocityFactor = 12.0;


GruffSparty::GruffSparty(std::shared_ptr<Level> level) : Angry(level)
{
    Angry::SetRadius(GruffSpartyRadius);
    Angry::SetVelocityFactor(GruffSpartyVelocityFactor);
}

void GruffSparty::XmlLoad(wxXmlNode *node)
{
    Item::SetImageName(L"images/gruff-sparty.png");

}

void GruffSparty::SetLocation(double x, double y)
{
    PositionalItem::SetLocation(x, y);
}

void GruffSparty::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Angry::OnDraw(graphics);

}