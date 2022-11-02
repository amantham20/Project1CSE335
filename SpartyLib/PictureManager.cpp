/**
 * @file PictureManager.cpp
 * @author Aman Dhruva Thamminana
 */


#include "pch.h"
#include "PictureManager.h"
#include <map>
#include "Picture.h"

void PictureManager::add(const std::wstring& fileName)
{
    if (mImageCache.find(fileName) == mImageCache.end()){
        mImageCache.insert({fileName, std::make_shared<Picture>(fileName)});
    }
}

std::shared_ptr<wxBitmap> PictureManager::GetBitmap(const std::wstring & key)
{
    if (mImageCache.find(key) != mImageCache.end()){
        return mImageCache[key]->GetBitmap();
    }
    else{
        add(key);
        return mImageCache[key]->GetBitmap();
    }
}

std::shared_ptr<wxImage> PictureManager::GetImage(const std::wstring & key)
{
    if (mImageCache.find(key) != mImageCache.end()){
        return mImageCache[key]->GetImage();
    }
    else{
        add(key);
        return mImageCache[key]->GetImage();
    }
}

