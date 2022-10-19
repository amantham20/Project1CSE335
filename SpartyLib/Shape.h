/**
 * @file Shape.h
 * @author Rajmeet Singh Chandok, zhiqiang ni
 */

#ifndef ANGRYSPARTY_SHAPE_H
#define ANGRYSPARTY_SHAPE_H

#include "PositionalItem.h"

/**
 * Base class for all shapes in AngrySparty
 */
class Shape : public PositionalItem{
private:
    /// Shape's friction
    double mFriction = 0.5;

    /// Shape's restitution
    double mRestitution = 0.5;

    /// Shape's density
    double mDensity = 1.0;

    /// Shape Angle
    double mAngle;

    /// Type of shape
    std::wstring mType = L"dynamic";

public:
    Shape(Level *level);

    wxXmlNode *XmlSave(wxXmlNode *node) override;

    void XmlLoad(wxXmlNode *node) override;

};

#endif //ANGRYSPARTY_SHAPE_H
