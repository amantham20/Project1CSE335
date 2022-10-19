/**
 * @file Block.cpp
 * @author Rajmeet Singh Chandok, zhiqiang ni
 */

#include "pch.h"
#include "Block.h"

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
    //todo: uncomplete code
    Item::XmlLoad(node);
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
    blockNode->AddAttribute(L"repeat-x", wxString::FromDouble(mRepeatX, 0));

    return blockNode;
}

Block::Block(Level *level, const std::wstring& filename) : Shape(level, filename)
{

}