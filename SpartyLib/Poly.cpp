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
    //todo: this may be wong place but it got be some where in the code


    //todo: this may be not the best way
    mVertices.clear();
    //load vertex
    auto child = node->GetChildren();
    for( ; child; child=child->GetNext())
    {
        auto name = child->GetName();
        if(name == L"v")
        {
            double x, y;
            child->GetAttribute(L"x", L"0").ToDouble(&x);
            node->GetAttribute(L"y", L"0").ToDouble(&y);
            auto vertex = Vertex(x,y);
            mVertices.push_back(vertex);
        }
    }
}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* Poly::XmlSave(wxXmlNode* node)
{
    auto polyNode = new wxXmlNode(wxXML_ELEMENT_NODE, L"poly");
    polyNode = PositionalItem::XmlSave(polyNode);
    node->AddChild(polyNode);
    //todo need add image?

    //save vertex
    for(auto vertex : mVertices)
    {
        auto vNode = new wxXmlNode(wxXML_ELEMENT_NODE, L"v");
        vNode->AddAttribute(L"x", wxString::FromDouble(vertex.getX()));
        vNode->AddAttribute(L"y", wxString::FromDouble(vertex.getY()));
        polyNode->AddChild(vNode);
    }

    return polyNode;
}