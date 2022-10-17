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

    /// Draw repeatedly
    int mRepeatX;

    /// Type of block
    std::string mType = "dynamic";

public:

};

#endif //ANGRYSPARTY_BLOCK_H
