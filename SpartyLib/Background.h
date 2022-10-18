/**
 * @file Background.h
 * @author Aman Dhruva Thamminana
 *
 *
 */

#ifndef ANGRYSPARTY_BACKGROUND_H
#define ANGRYSPARTY_BACKGROUND_H

#include "Item.h"

class Background : public Item {
private:

public:
    Background(std::shared_ptr<wxGraphicsContext> graphics);

};

#endif //ANGRYSPARTY_BACKGROUND_H
