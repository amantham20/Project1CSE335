/**
 * @file Level.h
 * @author Aman Dhruva Thamminana
 *
 *
 */

#ifndef ANGRYSPARTY_LEVEL_H
#define ANGRYSPARTY_LEVEL_H

#include "Item.h"
#include "Score.h"

class SpartyGame;
class Item;

class Level {
private:
    double mHeight = 0;
    double mWidth = 0;

    ///an pointer to sparty game
    SpartyGame *mSpartyGame;

    /// All of the items in the level
    std::vector<std::shared_ptr<Item>> mItems;

    /// an pointer for score
    Score *mLevelScore;
public:
    Level(SpartyGame *spartyGame);
    void Draw(wxDC *dc);

    void Add(std::shared_ptr<Item> item);

//    std::vector<std::shared_ptr<Item>> mItems;
    /// an pointer for score

    Level(double pHeight, double pWidth) : mHeight(pHeight), mWidth(pWidth){};
    Level(){};
    void init();
//    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    double GetHeight(){return mHeight;}
    double GetWidth(){return mWidth;}

    void LoadXMLLevel(wxXmlNode *node);

//    void Load(const wxString &filename);

    void Load(wxXmlNode *node);
};

#endif //ANGRYSPARTY_LEVEL_H
