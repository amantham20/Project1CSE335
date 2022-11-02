/**
 * @file Background.h
 * @author Aman Dhruva Thamminana
 *
 * Background class for a Level
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

    Background(std::shared_ptr<Level> level);

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void SetLocation(double x, double y) override;

    /**
     * Vistor pattern for Background Class
     * @param visitor
     */
    void Accept(std::shared_ptr<ItemVisitor> visitor) override { visitor->VisitBackground(this); }
};

#endif //ANGRYSPARTY_BACKGROUND_H
