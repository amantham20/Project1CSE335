/**
 * @file Picture.cpp
 * @author Rajmeet Singh Chandok, Milan Mihailovic
 */

#include "pch.h"
#include "Picture.h"
#include "Level.h"

using namespace std;

/**
 * Constructor
 * @param filename Filename of the image Picture class will hold
 */
Picture::Picture(const std::wstring& filename)
{
    mImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mImageBitmap = make_shared<wxBitmap>(*mImage);
}

/*
 * Intantiates to Bob.png
 */
Picture::Picture() {
    //TODO Kinda Rethink this

    // Not MyFinest Choice.
    mImage = make_unique<wxImage>(L"images/bob.png", wxBITMAP_TYPE_ANY);
    mImageBitmap = make_shared<wxBitmap>(*mImage);
}

/**
 * Set picture the Picture class holds
 * @param filename filename of the picture.
 */
void Picture::SetPicture(const std::wstring& filename){
    mImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mImageBitmap = make_shared<wxBitmap>(*mImage);
}



