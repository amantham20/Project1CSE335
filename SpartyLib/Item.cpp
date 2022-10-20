/**
 * @file Item.cpp
 * @author Milan Mihailovic
 */

#include "pch.h"
#include "Item.h"
#include <box2d.h>
#include <wx/graphics.h>
#include "Level.h"
#include "Consts.h"
#include "Picture.h"
#include <wx/graphics.h>




using namespace std;

/**
 * Destructor
 */
Item::~Item()
{

}

/**
 * Constructor
 * @param world The world the item is in.
 */
Item::Item(b2World *world)
{

}

/// TODO Remove this
Item::Item(const std::wstring& filename){
//    Picture pictureTemp(filename);
//    mPicture = &pictureTemp;

    mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}

Item::Item(Level *level, const std::wstring& filename){
//    Picture pictureTemp(filename);
//    mPicture = &pictureTemp;

    mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
    mLevel = level;
}

Item::Item(std::shared_ptr<wxGraphicsContext> graphics, const std::wstring& filename){

//    auto wid = mLevel->GetHeight() * Consts::MtoCM;
//    auto hit = mLevel->GetWidth()  * Consts::MtoCM;
//
//    auto picture = Picture(mLevel, filename);
//    std::shared_ptr<wxBitmap> bitmap = picture.GetBitmap();
//
//    graphics->PushState();
//    graphics->Scale(1, -1);
//    graphics->DrawBitmap(*bitmap,
//            -wid/2,
//            -hit,
//            wid, hit);
//    graphics->PopState();
}

void Item::OnDraw(std::shared_ptr<wxGraphicsContext> graphics){
    auto wid = mLevel->GetWidth() * Consts::MtoCM;
    auto hit = mLevel->GetHeight()  * Consts::MtoCM;

//    std::shared_ptr<wxBitmap> bitmap = mPicture->GetBitmap();

//    wid = 7000;
//    hit = 3000;

    graphics->PushState();
    graphics->Scale(1, -1);
    graphics->DrawBitmap(*mItemBitmap,
            -wid/2,
            -hit,
            wid, hit);
    graphics->PopState();
}



/**
 * Save this item to an XML node
 * @param node The parent node we are going to be a child of
 * @return wxXmlNode that we saved the item into
 */
wxXmlNode *Item::XmlSave(wxXmlNode *node)
{
    auto itemNode = new wxXmlNode(wxXML_ELEMENT_NODE, L"item");
    node->AddChild(itemNode);

    return itemNode;
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
void Item::XmlLoad(wxXmlNode *node)
{
    //todo: uncompleted code
}