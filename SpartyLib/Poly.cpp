/**
 * @file Poly.cpp
 * @author Rajmeet Singh Chandok, zhiqiang ni
 */

#include "pch.h"
#include "Poly.h"


/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
 */
void Poly::XmlLoad(wxXmlNode *node)
{
    //todo: uncomplete code
    Item::XmlLoad(node);
}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* Poly::XmlSave(wxXmlNode* node)
{
    auto itemNode = Item::XmlSave(node);
    //todo: uncomplete code

    return itemNode;
}