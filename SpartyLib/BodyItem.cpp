/**
 * @file BodyItem.cpp
 * @author Milan Mihailovic
 */

#include "pch.h"
#include "BodyItem.h"

/**
 * BodyItem constructor
 * @param level Level the body item is part of
 */
BodyItem::BodyItem(std::shared_ptr<Level> level) : PositionalItem(level)
{

}

/**
 * Loads XML data to BodyItem
 * @param node Xml note containing data for BodyItem
 */
void BodyItem::XmlLoad(wxXmlNode *node)
{
    node->GetAttribute(L"width").ToDouble(&mWidth);
    node->GetAttribute(L"height").ToDouble(&mHeight);
    mType = node->GetAttribute(L"type").ToStdWstring();
    mStatic = mType == L"static";
    node->GetAttribute(L"angle").ToDouble(&mAngle);
    node->GetAttribute(L"density").ToDouble(&mDensity);
    node->GetAttribute(L"friction").ToDouble(&mFriction);
    node->GetAttribute(L"restitution").ToDouble(&mRestitution);

    PositionalItem::XmlLoad(node);

    mSize = b2Vec2(mWidth, mHeight);


}

void BodyItem::InstallPhysics(std::shared_ptr<Physics> physics)
{
}