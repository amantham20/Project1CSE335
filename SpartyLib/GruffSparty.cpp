/**
 * @file GruffSparty.cpp
 * @author Ian Valdovinos Granados
 */

#include "pch.h"
#include "GruffSparty.h"

GruffSparty::GruffSparty(std::shared_ptr<Level> level) : Angry(level)
{

}

void GruffSparty::XmlLoad(wxXmlNode *node)
{
    Item::SetImageName(L"images/gruff-sparty.png");

}

void GruffSparty::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{

}