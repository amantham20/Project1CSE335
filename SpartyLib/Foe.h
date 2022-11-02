/**
 * @file Foe.h
 * @author Milan Mihailovic
 *
 *
 */

#ifndef ANGRYSPARTY_FOE_H
#define ANGRYSPARTY_FOE_H

#include "BodyItem.h"

/**
 * Foe class
 *
 * (class for all enemies)
 */
class Foe : public BodyItem {
private:

    /// Foe Down status
    double mDown;

    /// Foe Radius measurement
    double mRadius;

public:
    Foe(std::shared_ptr<Level> level);

    void XmlLoad(wxXmlNode *node) override;

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Accept(std::shared_ptr<ItemVisitor> visitor) override { visitor->VisitFoe(this); }

    void InstallPhysics(std::shared_ptr<Physics> physics) override;
};

#endif //ANGRYSPARTY_FOE_H
