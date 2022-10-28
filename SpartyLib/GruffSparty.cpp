/**
 * @file GruffSparty.cpp
 * @author Ian Valdovinos Granados
 */

#include "pch.h"
#include "GruffSparty.h"

GruffSparty::GruffSparty(Level *level) : Angry(level)
{

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