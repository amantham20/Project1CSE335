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
}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* Poly::XmlSave(wxXmlNode* node)
{
    auto polyNode = new wxXmlNode(wxXML_ELEMENT_NODE, L"poly");
    node->AddChild(polyNode);

    polyNode->AddAttribute(L"x", wxString::FromDouble(mX));
    polyNode->AddAttribute(L"y", wxString::FromDouble(mY));
    //todo need add image?



    //save vertex
    for(auto vertex : mVertices)
    {
        auto vNode = new wxXmlNode(wxXML_ELEMENT_NODE, L"v");
        polyNode->AddChild(vNode);

        vNode->AddAttribute(L"x", wxString::FromDouble(vertex.getX()));
        vNode->AddAttribute(L"y", wxString::FromDouble(vertex.getY()));
    }

    return polyNode;
}