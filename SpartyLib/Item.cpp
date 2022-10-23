/**
 * @file Item.cpp
 * @author Milan Mihailovic
 */

#include "pch.h"
#include "Item.h"
//#include <box2d.h>
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
 *
 * @param level The current Level the Object is in
 *
 * @author Aman Dhruva Thamminana
 */
Item::Item(std::shared_ptr<Level> level)
{
    mLevel = level;
    mPicture = new Picture();
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

    if (!node->GetAttribute(L"image").IsEmpty())
    {
        std::wstring filename = L"images/" + node->GetAttribute(L"image").ToStdWstring();

//    mPicture = new Picture(this, filename);
        mPicture = new Picture(filename);
        mFileName = filename;

//        mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
//        mItemBitmap = make_shared<wxBitmap>(*mItemImage);
    }


}

/**
 * Setter for image
 *
 * sets image bit map
 *
 * @param filename Relative Directory of the image.
 */
void Item::SetImageName(const std::wstring & filename)
{
//    mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
//    mItemBitmap = make_shared<wxBitmap>(*mItemImage);

    mPicture->SetPicture(filename);
    mFileName = filename;
}


