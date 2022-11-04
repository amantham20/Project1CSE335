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
#include <b2_body.h>
#include <b2_math.h>
#include "Physics.h"

/**
 * BodyItem class containing a Box2D body
 */
class BodyItem : public PositionalItem {
private:
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

    /// Boolean for static
    bool mStatic = false;

    /// mSize
    b2Vec2 mSize = b2Vec2(mWidth, mHeight);

protected:
    /// box2d Item Body
    b2Body* mBody;

    /// Physics object
    std::shared_ptr<Physics> mPhysics;
public:

    BodyItem(std::shared_ptr<Level> level);

    void XmlLoad(wxXmlNode *node) override;

    /**
     * Getter for mBody
     * @return mBody
     */
    b2Body* GetBody() {
//        return &(*mBody);
        return mBody;
    }

    /**
     * Getter for size
     * @return b2Vec2
     */
    b2Vec2 GetSize() { return b2Vec2(mWidth, mHeight); }

    /**
     * Getter for mAngle converted to radians
     * @return mAngle
     */
    double GetAngle(){ return mAngle*Consts::DtoR; }

    /**
     * Getter for the position of the body item
     * @return
     */
    b2Vec2 GetPosition() {return PositionalItem::GetPosition(); }

    /**
     * Install physics for the boty item
     * @param physics
     */
    void InstallPhysics(std::shared_ptr<Physics> physics) override;

    /**
     * Sets the body of the Body Item
     * @param body
     */
    void SetBody(b2Body *body){mBody = body;}

    /**
     * Sets the physics attribute of the Body Item
     * @param physics
     */
    void SetPhysics( std::shared_ptr<Physics> physics){mPhysics = physics;}

    /**
     * Getter for the angle of the body
     * @return angle of the body
     */
    double GetDAngle(){return mAngle;};

    /**
     * Getter for the body resolution
     * @return resolution
     */
    double GetResolution(){return mRestitution;};

    /**
     * Getter for the density of the body
     * @return Density of the body
     */
    double GetDensity(){return mDensity;};

    /**
     * Getter for the friction of the body
     * @return Friction of the body
     */
    double GetFriction(){return mFriction;};

    /**
     * Get the boolean value that represents if the body is static or ont
     * @return True if the body is static, false otherwise.
     */
    bool GetStatic(){return mStatic;}

};

#endif //ANGRYSPARTY_BODYITEM_H
