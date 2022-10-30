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

    /// offsets
    double mXOffset, mYOffset;

    void LoadXMLItems(wxXmlNode* node, std::shared_ptr<Level> pLevel);

    void LoadXMLSparties(wxXmlNode *node,std::shared_ptr<Level> pLevel);

    std::vector<std::shared_ptr<Level>> mLevels;

    int mCurrentLevel = 0;


    //// TODO: TEMP CODE WILL HAVE TO REMOVE IT
//    b2World mWorld = b2World(b2Vec2(0, -9.8));

//Physics mPhysics;


    bool mDebug = true;
    
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
};

#endif //ANGRYSPARTY_SPARTYGAME_H
