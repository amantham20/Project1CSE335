/**
 * @file Shape.h
 * @author Rajmeet Singh Chandok
 *
 * Base class for all shapes in AngrySparty
 */

#ifndef ANGRYSPARTY_SHAPE_H
#define ANGRYSPARTY_SHAPE_H

/**
 * Base class for shape
 */
class Shape {
private:
    /// Shape's friction
    double mFriction = 0.5;

    /// Shape's resistance
    double mResistance = 0.5;

    /// Shape's density
    double mDensity = 1.0;

public:
};

#endif //ANGRYSPARTY_SHAPE_H
