//
// Created by James on 10/25/22.
//

#ifndef ANGRYSPARTY_ANGRY_H
#define ANGRYSPARTY_ANGRY_H


#include "BodyItem.h"

class Angry : public BodyItem {
private:
    bool mLoaded = false;

public:

    Angry(std::shared_ptr<Level> level);

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;

    bool IsLoadedInSlingshot() {return mLoaded;};

    void SetLoadedInSlingshot(bool loaded) {mLoaded = loaded;};

};


#endif //ANGRYSPARTY_ANGRY_H
