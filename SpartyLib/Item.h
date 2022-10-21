/**
 * @file Item.h
 * @author Milan Mihailovic, zhiqiang ni
 *
 * Base class for any item in our game.
 */

#ifndef ANGRYSPARTY_ITEM_H
#define ANGRYSPARTY_ITEM_H

#include <memory>
#include <box2d.h>
#include "Picture.h"


class Picture;
class Level;

class Item {
private:
/// The level this item is contained in
    std::shared_ptr<Level> mLevel;

    //an pointer to picture
    Picture *mPicture;
//    Picture *mPicture;

    std::unique_ptr<wxImage> mItemImage;

    std::shared_ptr<wxBitmap> mItemBitmap;

public:



    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item &) = delete;

    virtual ~Item();

    Item(std::shared_ptr<Level> Level);

    // use virtual function for this or visitors?
    virtual void SetLocation(double x, double y) = 0;

    virtual void OnDraw(std::shared_ptr<wxGraphicsContext> graphics){};

    virtual wxXmlNode *XmlSave(wxXmlNode *node);

    virtual void XmlLoad(wxXmlNode *node);

    std::shared_ptr<Level> GetLevel(){return mLevel;}

    virtual std::shared_ptr<wxBitmap> GetBitMap(){return mItemBitmap;}

    void SetImageName(wxString filename);


    
};

#endif //ANGRYSPARTY_ITEM_H
