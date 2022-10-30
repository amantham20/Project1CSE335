/**
 * @file PositionalItem.h
 * @author Rajmeet Singh Chandok, zhiqiang ni, Milan Mihailovic
 *
 * Class describing a special type of item that has a specific x and y positions.
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
    double GetX() {return mX;}

    /**
     * Setter for x position
     * @param x pos
     */
    void SetX(double x) { mX = x; }

    /**
     * Getter of y position
     * @return y position
     */
    double GetY() {return mY;}

    /**
     * Setter for y position
     * @param y pos
     */
    void SetY(double y) { mY = y; }

    void SetLocation(double x, double y)  override;

    void XmlLoad(wxXmlNode *node) override;

    /**
     * Returns the position of the item
     * @return b2Vec2 representing the position of an item.
     */
    b2Vec2 GetPosition() { return b2Vec2(mX, mY); }

    bool HitTest(int x, int y) override;

};

#endif //ANGRYSPARTY_POSITIONALITEM_H
