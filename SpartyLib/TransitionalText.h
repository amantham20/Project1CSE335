/**
 * @file TransitionalText.h
 * @author Milan Mihailovic
 *
 *
 */

#ifndef ANGRYSPARTY_TRANSITIONALTEXT_H
#define ANGRYSPARTY_TRANSITIONALTEXT_H

#include "PositionalItem.h"

class TransitionalText : public PositionalItem {
private:

public:
    TransitionalText(std::shared_ptr<Level> level, double x,double y);

    void Accept(std::shared_ptr<ItemVisitor> visitor){};
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, const int &level);

};

#endif //ANGRYSPARTY_TRANSITIONALTEXT_H
