/**
 * @file Background.h
 * @author Aman Dhruva Thamminana
 *
 *
 */

#ifndef ANGRYSPARTY_BACKGROUND_H
#define ANGRYSPARTY_BACKGROUND_H

#include "Item.h"


/**
 * Background Class
 *
 * @author Aman Dhruva Thamminana
 */
class Background : public Item{
private:

public:

    void XmlLoad(wxXmlNode *node) override;

    /**
     * Constructor for the Background image
     *
     * Calls Item and passes in Level
     *
     * @param level The current Level the Object is in.
     *
     * @author Aman Dhruva Thamminana
     */
    Background(std::shared_ptr<Level> level) :Item(level){};

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void SetLocation(double x, double y) override;
};

#endif //ANGRYSPARTY_BACKGROUND_H
