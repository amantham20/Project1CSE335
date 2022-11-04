/**
 * @file Angry.h
 * @author James, Rajmeet Singh Chandok
 *
 */


#ifndef ANGRYSPARTY_ANGRY_H
#define ANGRYSPARTY_ANGRY_H

#include "BodyItem.h"

/**
 * Class for angry sparty
 *
 * (items that get launched from the slingshot)
 */
class Angry : public BodyItem
{
private:
    bool mLoaded = false;
    double mRadius = 0;
    float mVelocityFactor = 0;

public:
    Angry(std::shared_ptr<Level> level);

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void DrawRubberBand(std::shared_ptr<wxGraphicsContext> graphics);

    void InstallPhysics(std::shared_ptr<Physics> physics) override;

    void Launch(b2Vec2 vel);

    void DeleteBody();

    void ResetXY() override {
        PositionalItem::ResetXYtemp();
    };

    /**
     * Setter for Radius
     * @param rad
     */
    void SetRadius(double rad) { mRadius = rad; }

    /**
    * Setter for Velocity Factor
    * @param val
    */
    void SetVelocityFactor(float val) { mVelocityFactor = val; }

    /**
     * Getter for item's id
     * @return int
     */
    int GetId(){ return Item::GetId();}

    /**
     * Getter for is loaded in slingshot
     * @return
     */
    bool IsLoadedInSlingshot() {return mLoaded;};

    /**
     * Setter for is loaded in slingshot
     * @param loaded
     */
    void SetLoadedInSlingshot(bool loaded) {mLoaded = loaded;};

    void Dive();
};

#endif //ANGRYSPARTY_ANGRY_H
