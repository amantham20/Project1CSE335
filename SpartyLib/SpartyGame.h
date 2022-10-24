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

/**
 * Base AngrySparty Game Class
 */
class SpartyGame {
private:
    /// All of the items to populate our game
    std::vector<std::shared_ptr<Item>> mItems;

    ///An score pointer
    Score *mTotalScore;

    /// scaling factor
    double mScale;

    ///Image Cache
    std::shared_ptr<PictureManager> pictureCache;

    /// offsets
    double mXOffset, mYOffset;

    void LoadXMLItems(wxXmlNode* node, std::shared_ptr<Level> pLevel);

    void LoadXMLSparties(wxXmlNode *node);

    std::vector<std::shared_ptr<Level>> mLevels;

public:

    // todo: This function has to be removed when we store items in each level object instead of the game instance.
    /**
     * Returns the number of element in the game
     * @return
     */
    int GetNumberOfItems() { return mItems.size(); }

    SpartyGame();
    /**
     * get pointer of score
     * @return pointer of score
     */
    Score *getScore(){return mTotalScore;};

    void Load(const wxString& filename);
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
};

#endif //ANGRYSPARTY_SPARTYGAME_H
