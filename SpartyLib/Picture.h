/**
 * @file Picture.h
 * @author Rajmeet Singh Chandok
 */

#ifndef ANGRYSPARTY_PICTURE_H
#define ANGRYSPARTY_PICTURE_H

#include "SpartyGame.h"

/**
 * Placeholder class for all pictures
 */
class Picture {
private:
    /// The underlying image
    std::unique_ptr<wxImage> mImage;

    /// The bitmap we can display for this image
    std::unique_ptr<wxBitmap> mImageBitmap;

public:
    Picture(SpartyGame *game, const std::wstring& filename);

    /// Destructor
    virtual ~Picture();

    /// Default constructor (disabled)
    Picture() = delete;

    /// Copy constructor (disabled)
    Picture(const Picture &) = delete;


};

#endif //ANGRYSPARTY_PICTURE_H
