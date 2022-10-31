/**
 * @file SpartyGame.h
 * @author Rajmeet Singh Chandok
 * SpartyGame Class
 */

#ifndef ANGRYSPARTY_SPARTYGAME_H
#define ANGRYSPARTY_SPARTYGAME_H

#include "Item.h"
#include "Score.h"
#include "PictureManager.h"
#include <wx/graphics.h>
#include "ids.h"
#include "ItemVisitor.h"
#include "Physics.h"

class Angry;

/**
 * Base AngrySparty Game Class
 */
class SpartyGame {
private:
    ///An score pointer
    std::shared_ptr<Score> mTotalScore;

    /// scaling factor
    double mScale;

    ///Image Cache
    std::shared_ptr<PictureManager> mPictureCache;

    /// offsets in centimeters
    double mXOffset, mYOffset;

    void LoadXMLItems(wxXmlNode* node, std::shared_ptr<Level> pLevel);

    void LoadXMLSparties(wxXmlNode *node,std::shared_ptr<Level> pLevel);

    std::vector<std::shared_ptr<Level>> mLevels;

    int mCurrentLevel = 1;


    //// TODO: TEMP CODE WILL HAVE TO REMOVE IT
//    b2World mWorld = b2World(b2Vec2(0, -9.8));
    Physics mPhysics;
public:
    SpartyGame();

    void SetLevel(const int &level) { mCurrentLevel = level; } ;

    void Load(const wxString& filename);
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    void Reset();

    void DebugOnDraw(std::shared_ptr<wxGraphicsContext> graphics);

    Angry* HitTest(int x, int y);

    /**
     * Getter for the centimeter pixel scale factor
     * @return
     */
    double GetScale() {return mScale;};

    /**
     * Getter for the x offset
     * @return x offset in centimeters
     */
    double GetXOffset() {return mXOffset;};

    /**
     * Getter for the y offset
     * @return y offset in centimeters
     */
    double GetYOffset() {return mYOffset;};
};

#endif //ANGRYSPARTY_SPARTYGAME_H
