/**
 * @file Goalpost.cpp
 * @author Milan Mihailovic, zhiqiang ni
 */

#include "pch.h"
#include "Goalpost.h"

using namespace std;


Goalpost::Goalpost(Level *level) : Slingshot(level)
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

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* Goalpost::XmlSave(wxXmlNode* node)
{
    auto goalpostNode = new wxXmlNode(wxXML_ELEMENT_NODE, L"goalpost");
    //goalpostNode = XmlSave(goalpostNode);
    node->AddChild(goalpostNode);

    return goalpostNode;
}