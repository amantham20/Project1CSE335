/**
 * @file Picture.cpp
 * @author Rajmeet Singh Chandok
 */

#include "pch.h"
#include "Picture.h"
#include "SpartyGame.h"

using namespace std;

/**
 * Picture Constructor
 * @param object to SpartyGame
 * @param filename
 */
Picture::Picture(SpartyGame *game, const std::wstring& filename)
{
    mImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mImageBitmap = make_unique<wxBitmap>(*mImage);
}

using namespace std;
