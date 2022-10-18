/**
 * @file SpartyGame.h
 * @author Rajmeet Singh Chandok
 * SpartyGame Class
 */

#ifndef ANGRYSPARTY_SPARTYGAME_H
#define ANGRYSPARTY_SPARTYGAME_H

#include "Item.h"

/**
 * Base AngrySparty Game Class
 */
class SpartyGame {
private:
    /// All of the items to populate our game
    std::vector<std::shared_ptr<Item>> mItems;

    double mXOffset;
    double mYOffset;
    double mScale;

public:
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    void Save(const wxString &filename);
};

#endif //ANGRYSPARTY_SPARTYGAME_H
