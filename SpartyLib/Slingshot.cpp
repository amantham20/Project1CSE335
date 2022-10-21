/**
 * @file Slingshot.cpp
 * @author Milan Mihailovic
 */

#include "pch.h"
#include "Slingshot.h"

using namespace std;

/**
 * PositionalItem constructor
 * @param world
 */
Slingshot::Slingshot(std::shared_ptr<Level> level) : PositionalItem(level)
{
}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
 */
void Slingshot::XmlLoad(wxXmlNode *node)
{
    //todo: uncomplete code
    PositionalItem::XmlLoad(node);
}
