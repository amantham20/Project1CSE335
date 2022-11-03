/**
 * @file SpartyGame.h
 * @author Rajmeet Singh Chandok, zhiqiang ni
 * SpartyGame Class
 */

#ifndef ANGRYSPARTY_SPARTYGAME_H
#define ANGRYSPARTY_SPARTYGAME_H

#include "Item.h"
#include "Score.h"
#include "TransitionalText.h"
#include "PictureManager.h"
#include <wx/graphics.h>
#include "ids.h"
#include "ItemVisitor.h"
#include "Physics.h"
class PlayingArea;

class Angry;

/**
 * Base AngrySparty Game Class
 */
class SpartyGame {
private:
    ///An score pointer
    std::shared_ptr<Score> mTotalScore;

    /// scaling factor
    double mScale = 0;

    ///Image Cache
    std::shared_ptr<PictureManager> mPictureCache;

    /// offsets
    double mXOffset = 0, mYOffset= 0;

    void LoadXMLItems(wxXmlNode* node, std::shared_ptr<Level> pLevel);

    void LoadXMLSparties(wxXmlNode *node,std::shared_ptr<Level> pLevel);

    std::vector<std::shared_ptr<Level>> mLevels;

    int mCurrentLevel = 0;

    bool mLevelEnd = false;


    //// TODO: TEMP CODE WILL HAVE TO REMOVE IT
//    b2World mWorld = b2World(b2Vec2(0, -9.8));

//Physics mPhysics;


    bool mDebug = false;

    std::shared_ptr<PlayingArea> mPlayingArea;

public:
    SpartyGame();
    void SetLevel(const int &level) { mCurrentLevel = level; } ;

    void Load(const wxString& filename);
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    void Reset();

    void DebugOnDraw(std::shared_ptr<wxGraphicsContext> graphics);

    void Update(double val);

    void SetDebug(bool debug){mDebug = debug;};

    void Update();

    void Update(std::shared_ptr<wxGraphicsContext> graphics, double frameDuration);

    void Update(std::shared_ptr<wxGraphicsContext> graphics);

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

    b2Vec2 GetSlingshotLoadingPosition();

    int GetRubberBandLength();

    void ClearLoadedSparty();
};

#endif //ANGRYSPARTY_SPARTYGAME_H
