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





//Item::Item(std::shared_ptr<wxGraphicsContext> graphics, const std::wstring& filename){
//
//    auto wid = mLevel->GetHeight() * Consts::MtoCM;
//    auto hit = mLevel->GetWidth()  * Consts::MtoCM;
//
//    auto picture = Picture(nullptr, filename);
//    std::shared_ptr<wxBitmap> bitmap = picture.GetBitmap();
//
//    graphics->PushState();
//    graphics->Scale(1, -1);
//    graphics->DrawBitmap(*bitmap,
//            -wid/2,
//            -hit,
//            wid, hit);
//    graphics->PopState();
//
//}

/**
 * Constructor
 * @param world The world the item is in.
 */
Item::Item(std::shared_ptr<Level> level)
{
    mLevel = level;
}

/// TODO Remove this
//Item::Item(const std::wstring& filename){
////    Picture pictureTemp(filename);
////    mPicture = &pictureTemp;
//
//    mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
//    mItemBitmap = make_shared<wxBitmap>(*mItemImage);
//}

//Item::Item(std::shared_ptr<Level> level, const std::wstring& filename){
//    mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
//    mItemBitmap = make_shared<wxBitmap>(*mItemImage);
//    mLevel = level;
//}

//Item::Item(std::shared_ptr<wxGraphicsContext> graphics, const std::wstring& filename){
//
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
//}

//void Item::OnDraw(std::shared_ptr<wxGraphicsContext> graphics){
//}

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
    if (!node->GetAttribute(L"image").IsEmpty())
    {
        std::wstring filename = L"images/" + node->GetAttribute(L"image").ToStdWstring();
//    mPicture = new Picture(this, filename);
        mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
        mItemBitmap = make_shared<wxBitmap>(*mItemImage);
    }

}

void Item::SetImageName(wxString filename)
{
    mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_shared<wxBitmap>(*mItemImage);
}

//void Item::Draw(wxDC *dc)
//{
//    mPicture->Draw(dc);
//}

