/**
 * @file BodyItem.h
 * @author Milan Mihailovic
 *
 * BodyItem describes a type of Item that own a Box2D body
 *
 */

#ifndef ANGRYSPARTY_BODYITEM_H
#define ANGRYSPARTY_BODYITEM_H

#include "PositionalItem.h"
#include "Consts.h"
#include "b2_body.h"
#include <b2_math.h>

/**
 * BodyItem class containing a Box2D body
 */
class BodyItem : public PositionalItem {
private:
    /// box2d Item Body
    b2Body* mBody;

    /// Width of the BodyItem
    double mWidth = 0;

    /// Height of the BodyItem
    double mHeight= 0;

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

    BodyItem(Level *level);

    void XmlLoad(wxXmlNode *node) override;

    /**
     * Getter for mBody
     * @return mBody
     */
    b2Body* GetBody() { return mBody; }

    /**
     * Getter for b2Vec2
     * @return b2Vec2
     */
    b2Vec2 Getb2Vec() { return b2Vec2(mWidth, mHeight); }

    /**
 * Getter for mAngle converted to radians
 * @return mAngle
 */
    double GetAngle(){ return mAngle*Consts::DtoR; }

};

#endif //ANGRYSPARTY_BODYITEM_H
