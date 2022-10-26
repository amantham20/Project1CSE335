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

/**
 * Base AngrySparty Game Class
 */
class SpartyGame {
private:
    /// All of the items to populate our game
    std::vector<std::shared_ptr<Item>> mItems;

    ///An score pointer
    std::shared_ptr<Score> mTotalScore;

    /// scaling factor
    double mScale;

    ///Image Cache
    std::shared_ptr<PictureManager> pictureCache;

    /// offsets
    double mXOffset, mYOffset;

    void LoadXMLItems(wxXmlNode* node, std::shared_ptr<Level> pLevel);

    void LoadXMLSparties(wxXmlNode *node);

    std::vector<std::shared_ptr<Level>> mLevels;

    int mCurrentLevel = 0;

public:

    // todo: This function has to be removed when we store items in each level object instead of the game instance.
    /**
     * Returns the number of element in the game
     * @return
     */
    int GetNumberOfItems() { return mItems.size(); }

    SpartyGame();

    void SetLevel(const int &level) { mCurrentLevel = level; } ;

    void Load(const wxString& filename);
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    void Reset();
};

#endif //ANGRYSPARTY_SPARTYGAME_H
