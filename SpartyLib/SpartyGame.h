/**
 * @file SpartyGame.h
 * @author Rajmeet Singh Chandok
 * SpartyGame Class
 */

#ifndef ANGRYSPARTY_SPARTYGAME_H
#define ANGRYSPARTY_SPARTYGAME_H

#include "Item.h"
#include "Score.h"

/**
 * Base AngrySparty Game Class
 */
class SpartyGame {
private:

    ///An score pointer
    Score *mTotalScore;

    Level *testlevel;





    void LoadXMLItems(wxXmlNode *node);

    void LoadXMLSparties(wxXmlNode *node);
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
};

#endif //ANGRYSPARTY_SPARTYGAME_H
