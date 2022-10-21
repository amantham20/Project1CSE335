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
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* Shape::XmlSave(wxXmlNode* node)
{
    auto shapeNode = PositionalItem::XmlSave(node);
    shapeNode->AddAttribute(L"type", mType);
    shapeNode->AddAttribute(L"angle", wxString::FromDouble(mAngle));
    shapeNode->AddAttribute(L"density", wxString::FromDouble(mDensity));
    shapeNode->AddAttribute(L"friction", wxString::FromDouble(mFriction));
    shapeNode->AddAttribute(L"restitution", wxString::FromDouble(mRestitution));
    //todo: image?

    return shapeNode;
}

/**
 * Constructor
 * @param level
 */
Shape::Shape(std::shared_ptr<Level> level) : BodyItem(level)
{

}
