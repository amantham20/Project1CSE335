/**
 * @file GruffSparty.h
 * @author Ian Valdovinos Granados
 *
 *
 */

#ifndef ANGRYSPARTY_GRUFFSPARTY_H
#define ANGRYSPARTY_GRUFFSPARTY_H

#include "Angry.h"

/**
 * Class that inherits from AngrySparty and represents a gruff sparty.
 *
 * an type of angry sparty that gets launched by the slingshot.
 */
class GruffSparty : public Angry {
private:

public:
    GruffSparty(std::shared_ptr<Level> level);

    void XmlLoad(wxXmlNode *node) override;

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void SetLocation(double x, double y) override;
    /**
     * Visits the gruff sparty object
     * @param visitor
     */
    void Accept(std::shared_ptr<ItemVisitor> visitor) override { visitor->VisitGruffSparty(this); }

};

#endif //ANGRYSPARTY_GRUFFSPARTY_H
