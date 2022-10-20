/**
 * @file Picture.cpp
 * @author Rajmeet Singh Chandok, Milan Mihailovic
 */

#include "pch.h"
#include "Picture.h"
#include "Level.h"

using namespace std;

/**
 * Picture Constructor
 * @param object to SpartyGame
 * @param filename
 */
//Picture::Picture(Level *level, const std::wstring& filename)
//{
//    mImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
//    mImageBitmap = make_shared<wxBitmap>(*mImage);
//}

Picture::Picture(const std::wstring& filename)
{
    mImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mImageBitmap = make_shared<wxBitmap>(*mImage);
}

void Picture::Draw(wxDC *dc)
{
    double wid = mImageBitmap->GetWidth();
    double hit = mImageBitmap->GetHeight();
    dc->DrawBitmap(*mImageBitmap,
                   int(50 - wid / 2),
                   int(50 - hit / 2));
}

void Picture::SetPicture(const std::wstring& filename){
    mImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mImageBitmap = make_shared<wxBitmap>(*mImage);
}
