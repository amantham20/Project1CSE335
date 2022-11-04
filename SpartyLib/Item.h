/**
 * @file Item.h
 * @author Milan Mihailovic, zhiqiang ni
 *
 * Base class for any item in our game.
 */

#ifndef ANGRYSPARTY_ITEM_H
#define ANGRYSPARTY_ITEM_H

#include <memory>
#include "Picture.h"
#include "PictureManager.h"
#include "ItemVisitor.h"
#include "Physics.h"

/**
 * Forward declaration of picture
 */
class Picture;

/**
 * Forward declaration of Level
 */
class Level;

/**
 * Base class for any item in our game
 */
class Item {
private:
    /// Attribute that stores the filename of the item image
    std::wstring mFileName = L"images/bob.png";

    /// Pointer to the picture cache
    std::shared_ptr<PictureManager> mPictureCache;

    /// ID of the item
    int mId = -1;

protected:
    /// The level this item is contained in
    std::shared_ptr<Level> mLevel;

public:

    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item &) = delete;

    /// Delete destructor
    virtual ~Item();

    Item(std::shared_ptr<Level> level);

    /**
     * Setter for location of item
     * @param x x values
     * @param y y values
     */
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
     * @return mLevel The Level the item is currently Present in.
     */
    std::shared_ptr<Level>GetLevel(){ return mLevel;}

    /**
     * Getter for the ImageBitMap
     * @return ImageBitmap for the item
     */
    virtual std::shared_ptr<wxBitmap> GetBitMap(){ return mPictureCache->GetBitmap(mFileName); }

    void SetImageName(const std::wstring & filename);

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    virtual void Accept(std::shared_ptr<ItemVisitor> visitor) = 0;

    /**
     * Hit test that tests if the item has been clicked
     * @param x x location to test
     * @param y y location to test
     * @return True if the item has been clicked. False otherwise
     */
    virtual bool HitTest(int x, int y) { return false; };

    /**
     * reset xy
     */
    virtual void ResetXY(){};

    /**
     * Install physics function that installs physics for each item
     * @param physics
     */
    virtual void InstallPhysics(std::shared_ptr<Physics> physics){};

    /**
     * Setter for assigning the default values for x and y.
     * @param x value
     * @param y value
     */
    virtual void AssignXYInitial(double x, double y){};

    /**
     * Setter for item id
     * @param id
     */
    void SetId(int id) { mId = id; }

    /**
     * Getter for the item id
     * @return
     */
    int GetId(){ return mId; }

    /**
     * Setter for cache
     * @param pictureCache
     */
    void setCache(std::shared_ptr<PictureManager> pictureCache){ mPictureCache = pictureCache; }

    /**
     * Getter for the item's image
     * @return ImageBitmap for the item
     */
    virtual std::shared_ptr<wxImage> GetImage(){ return mPictureCache->GetImage(mFileName); }
};

#endif //ANGRYSPARTY_ITEM_H
