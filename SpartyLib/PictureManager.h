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

class PictureManager {
private:

    std::map<std::wstring, Picture *> mImageCache;
public:
    PictureManager(){};

    void add(const std::wstring& key, const std::wstring& fileName)
    {
        if (mImageCache.find(key) == mImageCache.end()){
            mImageCache.insert({key, new Picture(fileName)});
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
};

#endif //ANGRYSPARTY_PICTUREMANAGER_H
