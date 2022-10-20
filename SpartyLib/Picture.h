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
    Picture(Item *item, const std::wstring &filename);

    std::shared_ptr<wxBitmap> GetBitmap(){return mImageBitmap;}

    /// Destructor
    ~Picture(){}

    /// Default constructor (disabled)
    Picture() = delete;

    /// Copy constructor (disabled)
    Picture(const Picture &) = delete;


    void Draw(wxDC *dc);
};

#endif //ANGRYSPARTY_PICTURE_H
