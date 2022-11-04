/**
 * @file WoodenSlingshot.h
 * @author Milan Mihailovic, zhiqiang ni
 *
 * Class for a slingshot of type WoodenSlingshot
 */

#ifndef ANGRYSPARTY_WOODENSLINGSHOT_H
#define ANGRYSPARTY_WOODENSLINGSHOT_H

#include "Slingshot.h"

/**
 * Class for a slingshot of type WoodenSlingshot
 */
class WoodenSlingshot : public Slingshot {
private:
    /// Rubber band length in meters
    int mRubberBandLength = 1;

public:

    WoodenSlingshot(std::shared_ptr<Level> level);

    void XmlLoad(wxXmlNode *node) override;

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Visitor for wooden slingshot
     * @param visitor
     */
    void Accept(std::shared_ptr<ItemVisitor> visitor) override { visitor->VisitWoodenSlingshot(this); }

    void LoadAngrySparty(Angry* sparty) override;

    /**
     * Getter for the Rubber band length
     * @return rubberband length
     */
    int GetRubberBandLength() override {return mRubberBandLength;};
};

#endif //ANGRYSPARTY_WOODENSLINGSHOT_H
