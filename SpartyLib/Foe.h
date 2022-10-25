/**
 * @file Foe.h
 * @author Milan Mihailovic
 *
 *
 */

#ifndef ANGRYSPARTY_FOE_H
#define ANGRYSPARTY_FOE_H

#include "BodyItem.h"

class Foe : public BodyItem {
private:

    /// Foe Down status
    double mDown;

    /// Foe Radius measurement
    double mRadius;

public:
    Foe(std::shared_ptr<Level> level);

    void XmlLoad(wxXmlNode *node) override;

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics);
};

#endif //ANGRYSPARTY_FOE_H
