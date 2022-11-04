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

    /// X offset
    double mXOffset = 0;

    /// Y offset
    double mYOffset= 0;

    void LoadXMLItems(wxXmlNode* node, std::shared_ptr<Level> pLevel);

    void LoadXMLSparties(wxXmlNode *node,std::shared_ptr<Level> pLevel);

    /// Vector of levels
    std::vector<std::shared_ptr<Level>> mLevels;

    /// Index of the current level
    int mCurrentLevel = 0;

    /// Boolean that keeps track of whether we are in debug mode or not
    bool mDebug = false;

    /// Pointer to tha playing area
    std::shared_ptr<PlayingArea> mPlayingArea;

    /// ID for loading ids into objects
    int mId = 0;

public:
    SpartyGame();

    /**
     * Sets the current level to another level
     * @param level new level to set current level to
     */
    void SetLevel(const int &level) { mCurrentLevel = level; } ;

    void Load(const wxString& filename);

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    void Reset();

    void DebugOnDraw(std::shared_ptr<wxGraphicsContext> graphics);

    void UpdateItems(double val);

    /**
     * Sets the debug to the mode denoted by the debug paraameter
     * @param debug Boolean to set the debug mode to
     */
    void SetDebug(bool debug){mDebug = debug;};

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

    Angry* GetFlyingSparty();

    void SetFlyingSparty(Angry* angry);

    int GetNumberOfItems();
};

#endif //ANGRYSPARTY_SPARTYGAME_H
