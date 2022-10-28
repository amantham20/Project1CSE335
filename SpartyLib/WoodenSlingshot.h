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

public:

    WoodenSlingshot(Level *level);

    void XmlLoad(wxXmlNode *node) override;

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Accept(ItemVisitor* visitor) override { visitor->VisitWoodenSlingshot(this); }
};

#endif //ANGRYSPARTY_WOODENSLINGSHOT_H
