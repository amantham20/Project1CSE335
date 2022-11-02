/**
 * @file PictureManager.cpp
 * @author Aman Dhruva Thamminana
 */


#include "pch.h"
#include "PictureManager.h"
#include <map>
#include "Picture.h"

/**
 * Class that manages pictures cache add if the image is not in the dictionary collection based on the name
 *
 * @param fileName the name of the file
 */
void PictureManager::add(const std::wstring& fileName)
{
    if (mImageCache.find(fileName) == mImageCache.end()){
        mImageCache.insert({fileName, std::make_shared<Picture>(fileName)});
    }
}

/**
 * Get the bitmap from the cache of the image
 * if is not in the cache then add it to the cache
 *
 * @param key
 * @return the bitmap of the image
 */
std::shared_ptr<wxBitmap> PictureManager::GetBitmap(const std::wstring & key)
{
//    if (mImageCache.find(key) != mImageCache.end()){
//        return mImageCache[key]->GetBitmap();
//    }
//    else{
//        add(key);
//        return mImageCache[key]->GetBitmap();
//    }
    if (mImageCache.find(key) == mImageCache.end()){
        add(key);
    }
    return mImageCache[key]->GetBitmap();
}

/**
 * Get the image from the cache of the image
 *
 * if the image is not in the cache then add it to the cache
 * @param key
 * @return
 */
std::shared_ptr<wxImage> PictureManager::GetImage(const std::wstring & key)
{
//    if (mImageCache.find(key) != mImageCache.end()){
//        return mImageCache[key]->GetImage();
//    }
//    else{
//        add(key);
//        return mImageCache[key]->GetImage();
//    }
    if (mImageCache.find(key) == mImageCache.end()){
        add(key);
    }
    return mImageCache[key]->GetImage();
}

