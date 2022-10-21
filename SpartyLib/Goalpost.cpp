/**
 * @file Goalpost.cpp
 * @author Milan Mihailovic, zhiqiang ni
 */

#include "pch.h"
#include "Goalpost.h"

using namespace std;


Goalpost::Goalpost(std::shared_ptr<Level> level) : Slingshot(level)
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
void Goalpost::XmlLoad(wxXmlNode *node)
{
    //todo: uncomplete code
    Slingshot::XmlLoad(node);
}
