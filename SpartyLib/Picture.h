/**
 * @file Picture.h
 * @author Rajmeet Singh Chandok, Milan Mihailovic
 */

#ifndef ANGRYSPARTY_PICTURE_H
#define ANGRYSPARTY_PICTURE_H

/**
 * Placeholder class for all pictures
 */
class Picture {
private:
    /// The underlying image
    std::shared_ptr<wxImage> mImage;

    /// The bitmap we can display for this image
    std::shared_ptr<wxBitmap> mImageBitmap;

public:

    Picture(const std::wstring& filename);

    Picture();

    /**
     *
     * @return the image bitmap
     */
    std::shared_ptr<wxBitmap> GetBitmap(){return mImageBitmap;}

    /**
     * Getter for Image
     * @return mImage
     */
    std::shared_ptr<wxImage> GetImage(){return mImage;}

    void SetPicture(const std::wstring& filename);

    /// Destructor
    ~Picture(){}

    /// Default constructor (disabled)

    /// Copy constructor (disabled)
    Picture(const Picture &) = delete;


};

#endif //ANGRYSPARTY_PICTURE_H
