/**
 * @file Picture.h
 * @author Rajmeet Singh Chandok, Milan Mihailovic
 */

#ifndef ANGRYSPARTY_PICTURE_H
#define ANGRYSPARTY_PICTURE_H

#include "Level.h"

/**
 * Placeholder class for all pictures
 */
class Picture {
private:
    /// The underlying image
    std::unique_ptr<wxImage> mImage;

    /// The bitmap we can display for this image
    std::shared_ptr<wxBitmap> mImageBitmap;

public:
//    Picture(Level *level, const std::wstring& filename);

    Picture(const std::wstring& filename);

    Picture();

    std::shared_ptr<wxBitmap> GetBitmap(){return mImageBitmap;}

    void SetPicture(const std::wstring& filename);

    /// Destructor
    ~Picture(){}

    /// Default constructor (disabled)
//    Picture() = delete;

    /// Copy constructor (disabled)
    Picture(const Picture &) = delete;

//    std::shared_ptr<wxBitmap> GetPictureBitmap(){return mImageBitmap;}

};

#endif //ANGRYSPARTY_PICTURE_H
