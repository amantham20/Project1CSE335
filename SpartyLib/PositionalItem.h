/**
 * @file PositionalItem.h
 * @author Rajmeet Singh Chandok, zhiqiang ni, Milan Mihailovic
 *
 */

#ifndef ANGRYSPARTY_POSITIONALITEM_H
#define ANGRYSPARTY_POSITIONALITEM_H

#include "Item.h"

/**
 * Positional Item class for items with specific positions.
 */
class PositionalItem : public Item {
private:

    /// x position
    double mX;

    /// y position
    double mY;

public:

    PositionalItem(std::shared_ptr<Level> level);

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

    void SetLocation(double x, double y)  override;

    void XmlLoad(wxXmlNode *node) override;

    b2Vec2 GetPosition() { return b2Vec2(mX, mY); }

};

#endif //ANGRYSPARTY_POSITIONALITEM_H
