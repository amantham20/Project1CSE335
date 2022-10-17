/**
 * @file Block.h
 * @author Rajmeet Singh Chandok
 *
 *
 */

#ifndef ANGRYSPARTY_BLOCK_H
#define ANGRYSPARTY_BLOCK_H

#include "Shape.h"

class Block : public Shape {
private:
    /// Block Angle
    double mAngle;

    /// Repeat X Direction
    int mRepeatX;

    /// Type of block
    enum Type { Static, Dynamic };

public:

};

#endif //ANGRYSPARTY_BLOCK_H
