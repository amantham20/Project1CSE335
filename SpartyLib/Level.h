/**
 * @file Level.h
 * @author Aman Dhruva Thamminana
 *
 * Level class representing a level in the game
 *
 */

#ifndef ANGRYSPARTY_LEVEL_H
#define ANGRYSPARTY_LEVEL_H

//#include "Item.h"
#include "Score.h"
#include "PictureManager.h"

class SpartyGame;
class Item;
class Slingshot;

/**
 * Level class describing a level object in the game
 */
class Level {
private:
    double mHeight = 0;
    double mWidth = 0;

    ///an pointer to sparty game
    SpartyGame *mSpartyGame;

    /// All of the items in the level
    std::vector<std::shared_ptr<Item>> mItems;

    /// an pointer for score
    std::shared_ptr<Score> mLevelScore;

    /// A pointer to the slingshot in the level
    std::shared_ptr<Slingshot> mSlingShot;

    std::shared_ptr<PictureManager> mPictureCache;
public:
    Level() = delete;
    Level(SpartyGame *spartyGame, std::shared_ptr<PictureManager> pictureCache);
    void Draw(wxDC *dc);
    void Add(std::shared_ptr<Item> item);

    void SetSlingShot(std::shared_ptr<Slingshot> slingshot);

//    std::vector<std::shared_ptr<Item>> mItems;
    /// an pointer for score

    //Level(double pHeight, double pWidth) : mHeight(pHeight), mWidth(pWidth){};
    void init();
//    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    double GetHeight(){return mHeight;}
    double GetWidth(){return mWidth;}

    void LoadXMLLevel(wxXmlNode *node);
    void LoadXMLSparties(wxXmlNode *node);

    void LoadXMLItems(wxXmlNode *node);
    std::shared_ptr<Score> GetScore() { return mLevelScore; };

//    void Load(const wxString &filename);

    b2Vec2 GetPlayAreaSize(){return b2Vec2(mWidth, mHeight);}

    void Load(wxXmlNode *node);
};

#endif //ANGRYSPARTY_LEVEL_H
