/**
 * @file Angry.h
 * @author James
 *
 */

//
// Created by James on 10/25/22.
//

#ifndef ANGRYSPARTY_ANGRY_H
#define ANGRYSPARTY_ANGRY_H


#include "BodyItem.h"

/**
 * Class for angry sparty
 *
 * (items that get launched from the slingshot)
 */
class Angry : public BodyItem {
private:
    bool mLoaded = false;

public:

    Angry(std::shared_ptr<Level> level);

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void DrawRubberBand(std::shared_ptr<wxGraphicsContext> graphics);

    bool IsLoadedInSlingshot() {return mLoaded;};

    void SetLoadedInSlingshot(bool loaded) {mLoaded = loaded;};

    void InstallPhysics(std::shared_ptr<Physics> physics) override;

};


#endif //ANGRYSPARTY_ANGRY_H
