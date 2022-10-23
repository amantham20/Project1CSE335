/**
 * @file Background.h
 * @author Aman Dhruva Thamminana
 *
 *
 */

#ifndef ANGRYSPARTY_BACKGROUND_H
#define ANGRYSPARTY_BACKGROUND_H

#include "Item.h"

class Background : public Item{
private:

public:

    void XmlLoad(wxXmlNode *node) override;
    Background(std::shared_ptr<Level> level) :Item(level){};
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void SetLocation(double x, double y) override;
};

#endif //ANGRYSPARTY_BACKGROUND_H
