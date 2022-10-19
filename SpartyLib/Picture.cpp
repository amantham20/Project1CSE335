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
Picture::Picture(const std::wstring& filename)
{
    mImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mImageBitmap = make_shared<wxBitmap>(*mImage);
}
