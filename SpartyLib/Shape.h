/**
 * @file Shape.h
 * @author Rajmeet Singh Chandok, zhiqiang ni, Milan Mihailovic
 */

#ifndef ANGRYSPARTY_SHAPE_H
#define ANGRYSPARTY_SHAPE_H

#include "BodyItem.h"
#include "Consts.h"

/**
 * Base class for all shapes in AngrySparty
 */
class Shape : public BodyItem {
private:
    /// Shape's friction
    double mFriction = 0.5;

    /// Shape's restitution
    double mRestitution = 0.5;

    /// Shape's density
    double mDensity = 1.0;

    /// Shape Angle
    double mAngle = 0;

    /// Type of shape
    std::wstring mType = L"dynamic";

public:
    Shape(std::shared_ptr<Level> level);

    void XmlLoad(wxXmlNode *node) override;

    /**
     * Getter for mAngle converted to radians
     * @return mAngle
     */
    double GetAngle(){ return mAngle*Consts::DtoR; }

};

#endif //ANGRYSPARTY_SHAPE_H
