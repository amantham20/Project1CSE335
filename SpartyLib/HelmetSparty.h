/**
 * @file HelmetSparty.h
 * @author Ian Valdovinos Granados
 *
 *
 */

#ifndef ANGRYSPARTY_HELMETSPARTY_H
#define ANGRYSPARTY_HELMETSPARTY_H

#include "Angry.h"

/**
 * Class that inherits from AngrySparty and represents a helmet sparty.
 *
 * an type of angry sparty that gets launched by the slingshot.
 */
class HelmetSparty : public Angry {
private:

public:
    HelmetSparty(std::shared_ptr<Level> level);

    void XmlLoad(wxXmlNode *node) override;

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void SetLocation(double x, double y) override;

    /**
     * Visits the Helmet Sparty object
     * @param visitor
     */
    void Accept(std::shared_ptr<ItemVisitor> visitor) override { visitor->VisitHelmetSparty(this); }

};

#endif //ANGRYSPARTY_HELMETSPARTY_H
