/**
 * @file PictureManager.h
 * @author Aman Dhruva Thamminana
 *
 *
 */

#ifndef ANGRYSPARTY_PICTUREMANAGER_H
#define ANGRYSPARTY_PICTUREMANAGER_H

#include <map>
#include "Picture.h"

/**
 * Class that manages pictures
 */
class PictureManager {
private:

    std::map<std::wstring, std::shared_ptr<Picture>> mImageCache;
public:
    PictureManager(){};

    void add(const std::wstring& key, const std::wstring& fileName)
    {
        if (mImageCache.find(key) == mImageCache.end()){
            mImageCache.insert({key, std::make_shared<Picture>(fileName)});
        }
    }

    std::shared_ptr<wxBitmap> GetBitmap(const std::wstring & key)
    {
        if (mImageCache.find(key) != mImageCache.end()){
            return mImageCache[key]->GetBitmap();
        }
        else{
            add(key, key);
            return mImageCache[key]->GetBitmap();
        }
    }

    std::shared_ptr<wxImage> GetImage(const std::wstring & key)
    {
        if (mImageCache.find(key) != mImageCache.end()){
            return mImageCache[key]->GetImage();
        }
        else{
            add(key, key);
            return mImageCache[key]->GetImage();
        }
    }
};

#endif //ANGRYSPARTY_PICTUREMANAGER_H
