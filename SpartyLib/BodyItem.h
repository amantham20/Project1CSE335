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
    /// box2d Item Body
    b2Body* mBody;

    /// Physics object
    std::shared_ptr<Physics> mPhysics;

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
    bool mStatic = mType == L"static";

    /// mSize
    b2Vec2 mSize = b2Vec2(mWidth, mHeight);

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

    b2Vec2 GetPosition() {return PositionalItem::GetPosition(); }


//    virtual void InstallPhysics(std::shared_ptr<Physics> physics);

    void InstallPhysics(std::shared_ptr<Physics> physics) override;

    void SetBody(b2Body *body){mBody = body;}

    void SetPhysics( std::shared_ptr<Physics> physics){mPhysics = physics;}

//    b2Vec2 GetSize(){return mSize;}
    double GetDAngle(){return mAngle;};

    double GetResolution(){return mRestitution;};

    double GetDensity(){return mDensity;};

    double GetFriction(){return mFriction;};

    bool GetStatic(){return mStatic;}

};

#endif //ANGRYSPARTY_BODYITEM_H
