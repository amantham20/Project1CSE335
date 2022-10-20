/**
 * @file SpartyGame.h
 * @author Rajmeet Singh Chandok
 * SpartyGame Class
 */

#ifndef ANGRYSPARTY_SPARTYGAME_H
#define ANGRYSPARTY_SPARTYGAME_H

#include "Item.h"
#include "Score.h"
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

    /// offsets
    double mXOffset, mYOffset;

    void LoadXMLItems(wxXmlNode* node);

    void LoadXMLSparties(wxXmlNode *node);
    std::vector<std::shared_ptr<Level>> mLevels;



public:



    SpartyGame();
    /**
     * get pointer of score
     * @return pointer of score
     */
    Score *getScore(){return mTotalScore;};

    void Save(const wxString &filename);

    void Load(const wxString& filename);
    void OnDraw(wxDC *dc);
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
};

#endif //ANGRYSPARTY_SPARTYGAME_H
