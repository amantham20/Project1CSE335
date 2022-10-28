/**
 * @file Item.h
 * @author Milan Mihailovic, zhiqiang ni
 *
 * Base class for any item in our game.
 */

#ifndef ANGRYSPARTY_ITEM_H
#define ANGRYSPARTY_ITEM_H

#include <memory>
//#include <box2d.h>
#include "Picture.h"
#include "PictureManager.h"
#include "ItemVisitor.h"

class Picture;
class Level;

class Item {
private:
    /// The level this item is contained in
    Level *mLevel;

    ///a pointer to picture
    //Picture *mPicture;

//    /// TEMP wxImage of the Item image
//    std::unique_ptr<wxImage> mItemImage;
//
//    /// TEMP wxBitmap of the Item image
//    std::shared_ptr<wxBitmap> mItemBitmap;
    /// TODO remove Image/ Combine them into a class (aka use mPicture)

//    images/bob.png
    std::wstring mFileName = L"images/bob.png";

    std::shared_ptr<PictureManager> mPictureCache;


public:

    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item &) = delete;

    virtual ~Item();

    Item(Level *level);

    /// TODO ! use virtual function for this or visitors?
    virtual void SetLocation(double x, double y) = 0;

    /**
     * Draws the Item
     *
     * @param graphics Graphics that is used to draw the image.
     */
    virtual void OnDraw(std::shared_ptr<wxGraphicsContext> graphics){};

    virtual void XmlLoad(wxXmlNode *node);

    /**
     * Getter for Level for this Item
     *
     *
     * @return mLevel The Level the item is currently Present in.
     *
     * @TODO Move this to Protected?? (although may not be required as it is a getter.)
     *
     * @personToBlame Aman Dhruva Thamminana
     */
    Level* GetLevel(){return mLevel;}

    /**
     * Getter for the ImageBitMap
     *
     * @return ImageBitmap for the item
     */
    virtual std::shared_ptr<wxBitmap> GetBitMap(){
//        return mItemBitmap;
//        return mPicture->GetBitmap();
        return mPictureCache->GetBitmap(mFileName);
    }
    //virtual void Update(double elapsed){};

    //virtual void Update(std::shared_ptr<wxGraphicsContext> graphics);

    void SetImageName(const std::wstring & filename);


    void setCache(std::shared_ptr<PictureManager> pictureCache){
        mPictureCache = pictureCache;
    }

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    virtual void Accept(ItemVisitor* visitor) = 0;
    
};

#endif //ANGRYSPARTY_ITEM_H
