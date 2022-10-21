/**
 * @file Block.cpp
 * @author Rajmeet Singh Chandok, zhiqiang ni
 */

#include "pch.h"
#include "Block.h"
#include "Consts.h"
#include "Shape.h"
#include "Item.h"

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
 */
void Block::XmlLoad(wxXmlNode *node)
{
    node->GetAttribute(L"repeat-x").ToInt(&mRepeatX);
    Shape::XmlLoad(node);
}
/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* Block::XmlSave(wxXmlNode* node)
{
    auto blockNode = new wxXmlNode(wxXML_ELEMENT_NODE, L"block");
    node->AddChild(blockNode);
    blockNode = Shape::XmlSave(blockNode);
    blockNode->AddAttribute(L"repeat-x", wxString::FromDouble(mRepeatX,0));

    return blockNode;
}


Block::Block(std::shared_ptr<Level> level) : Shape(level)
{

}

void Block::OnDraw(std::shared_ptr<wxGraphicsContext> graphics){

    graphics->PushState();
    auto mSize = BodyItem::Getb2Vec();

//    b2Body* body = BodyItem::GetBody();
//    auto position = body->GetPosition();
//    auto angle = body->GetAngle();

    auto position = PositionalItem::GetPosition();
    auto angle = Shape::GetAngle();

    graphics->Translate(position.x * Consts::MtoCM,
            position.y * Consts::MtoCM);
    graphics->Rotate(angle);

    // Make this is left side of the rectangle
    double x = -mSize.x/2 * Consts::MtoCM;

    // And the top
    double y = mSize.y/2 * Consts::MtoCM;

    // The width of each repeated block
    double xw = mSize.x / mRepeatX * Consts::MtoCM;

    std::shared_ptr<wxBitmap> bitmap = Item::GetBitMap();

    graphics->Translate(0, y);
    graphics->Scale(1, -1);
    for(int ix=0; ix<mRepeatX;  ix++)
    {
        graphics->DrawBitmap(*bitmap,
                x,
                0,
                xw, mSize.y * Consts::MtoCM);

        x += xw;
    }

//    graphics->Rotate(angle);

    graphics->PopState();
}