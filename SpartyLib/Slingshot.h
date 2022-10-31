/**
 * @file Slingshot.h
 * @author Milan Mihailovic, zhiqiang ni
 *
 * Base Class for the slingshot items in the game.
 */

#ifndef ANGRYSPARTY_SLINGSHOT_H
#define ANGRYSPARTY_SLINGSHOT_H

#include "PositionalItem.h"
#include "Angry.h"

/**
 * Base class for a slingshot
 *
 * This applies to the wooden slingshots
 * and the goalposts in the game.
 */
class Slingshot : public PositionalItem {
private:
    double mXLoadSpot = 0;
    double mYLoadSpot = 0;

public:

    Slingshot(std::shared_ptr<Level> level);

    void XmlLoad(wxXmlNode *node) override;

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;

    virtual void LoadAngrySparty(Angry* sparty) = 0;

    /**
     * Get the x position of the loading spot
     * @return x position of the loading spot
     */
    double GetXLoadSpot() {return mXLoadSpot;};

    /**
     * Get the y position of the loading spot
     * @return y position of the loading spot
     */
    double GetYLoadSpot() {return mYLoadSpot;};

    /**
    * Sets the x position of the loading spot
    */
    void SetXLoadSpot(double x) {mXLoadSpot = x;};

    /**
    * Sets the y position of the loading spot
    */
    void SetYLoadSpot(double y) {mYLoadSpot = y;};
};

#endif //ANGRYSPARTY_SLINGSHOT_H
