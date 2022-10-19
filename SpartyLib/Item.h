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


class Picture;
class Level;

class Item {
private:
    /// The level this item is contained in
    Level *mLevel;

    //an pointer to picture
    Picture *mPicture;
protected:
    Item(Level* level, const std::wstring& filename);
public:
    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item &) = delete;

    virtual ~Item();

    void Draw(wxDC *dc);
    Item(std::shared_ptr<wxGraphicsContext> graphics, const std::wstring& filename);


    virtual wxXmlNode *XmlSave(wxXmlNode *node);

    virtual void XmlLoad(wxXmlNode *node);
};

#endif //ANGRYSPARTY_ITEM_H
