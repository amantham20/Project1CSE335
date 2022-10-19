/**
 * @file PositionalItem.h
 * @author Rajmeet Singh Chandok, zhiqiang ni
 *
 */

#ifndef ANGRYSPARTY_POSITIONALITEM_H
#define ANGRYSPARTY_POSITIONALITEM_H

#include "Item.h"
#include <box2d.h>

/**
 * Positional Item class for items with specific positions.
 */
class PositionalItem : public Item {
private:

/// x position
    double mX;

    /// y position
    double mY;

    /// box2d Item Body
    b2Body* mBody;

public:

    PositionalItem(Level *level, const std::wstring& filename);

    /**
     * Getter of x position
     * @return x position
     */
    double getX() {return mX;}

    /**
     * Setter for x position
     * @param x pos
     */
    void setX(double x) { mX = x; }

    /**
     * Getter of y position
     * @return y position
     */
    double getY() {return mY;}

    /**
     * Setter for y position
     * @param y pos
     */
    void setY(double y) { mY = y; }

    wxXmlNode *XmlSave(wxXmlNode *node) override;

    void XmlLoad(wxXmlNode *node) override;

};

#endif //ANGRYSPARTY_POSITIONALITEM_H
