//
// Created by James on 10/25/22.
//

#ifndef ANGRYSPARTY_ANGRY_H
#define ANGRYSPARTY_ANGRY_H


#include "BodyItem.h"

class Angry : public BodyItem {
private:

public:

    Angry(std::shared_ptr<Level> level);

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;
//    std::shared_ptr<Level> GetLevel() {Item::GetLevel(); }

    void InstallPhysics(std::shared_ptr<Physics> physics) override;

};


#endif //ANGRYSPARTY_ANGRY_H
