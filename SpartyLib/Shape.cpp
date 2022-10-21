/**
 * @file Shape.cpp
 * @author Rajmeet Singh Chandok, zhiqiang ni
 */

#include "pch.h"
#include "Shape.h"


/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
 */
void Shape::XmlLoad(wxXmlNode *node)
{
    mType = node->GetAttribute(L"type").ToStdWstring();
    node->GetAttribute(L"angle").ToDouble(&mAngle);
    node->GetAttribute(L"density").ToDouble(&mDensity);
    node->GetAttribute(L"friction").ToDouble(&mFriction);
    node->GetAttribute(L"restitution").ToDouble(&mRestitution);
    BodyItem::XmlLoad(node);
}


/**
 * Constructor
 * @param level
 */
Shape::Shape(std::shared_ptr<Level> level) : BodyItem(level)
{

}
