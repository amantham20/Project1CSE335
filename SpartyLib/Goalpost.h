/**
 * @file Goalpost.h
 * @author Milan Mihailovic, zhiqiang ni
 *
 * Class for a slingshot of type Goalpost
 */

#ifndef ANGRYSPARTY_GOALPOST_H
#define ANGRYSPARTY_GOALPOST_H

#include "Slingshot.h"
#include "ItemVisitor.h"

/**
 * Class for a slingshot of type Goalpost
 */
class Goalpost : public Slingshot {
private:

public:
    Goalpost(std::shared_ptr<Level> level);

    void XmlLoad(wxXmlNode *node) override;

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Accept(std::shared_ptr<ItemVisitor> visitor) override { visitor->VisitGoalpost(this); }

    void LoadAngrySparty(Angry* sparty) override;
};

#endif //ANGRYSPARTY_GOALPOST_H
