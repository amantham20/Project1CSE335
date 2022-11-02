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
    /// The dictionary of the images that caches the images with key as the filename and picture as the value
    std::map<std::wstring, std::shared_ptr<Picture>> mImageCache;
public:
    /// Default constructor
    PictureManager(){};

    void add(const std::wstring& fileName);

    std::shared_ptr<wxBitmap> GetBitmap(const std::wstring & key);

    std::shared_ptr<wxImage> GetImage(const std::wstring & key);
};

#endif //ANGRYSPARTY_PICTUREMANAGER_H
