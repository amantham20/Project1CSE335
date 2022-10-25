/**
 * @file HelmetSparty.cpp
 * @author Ian Valdovinos Granados
 */

#include "pch.h"
#include "HelmetSparty.h"

HelmetSparty::HelmetSparty(std::shared_ptr<Level> level) : Angry(level)
{

}

void HelmetSparty::XmlLoad(wxXmlNode *node)
{
    Item::SetImageName(L"images/helmet-sparty.png");

}

void HelmetSparty::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{

}