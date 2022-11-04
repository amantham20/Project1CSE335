/**
 * @file TransitionalText.h
 * @author Milan Mihailovic
 *
 * Class that represent transition text
 */

#ifndef ANGRYSPARTY_TRANSITIONALTEXT_H
#define ANGRYSPARTY_TRANSITIONALTEXT_H

#include "PositionalItem.h"

/**
 * Represents the transition text between levels
 */
class TransitionalText : public PositionalItem {
private:

public:
    TransitionalText(std::shared_ptr<Level> level, double x,double y);

    /**
     * Accept function that accepts an Item visitor
     * @param visitor
     */
    void Accept(std::shared_ptr<ItemVisitor> visitor){};

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, const int &level, const bool &end);

};

#endif //ANGRYSPARTY_TRANSITIONALTEXT_H
