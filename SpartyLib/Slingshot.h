/**
 * @file Slingshot.h
 * @author Milan Mihailovic, zhiqiang ni
 *
 * Base Class for the slingshot items in the game.
 */

#ifndef ANGRYSPARTY_SLINGSHOT_H
#define ANGRYSPARTY_SLINGSHOT_H

#include "PositionalItem.h"
#include "Angry.h"

/**
 * Base class for a slingshot
 *
 * This applies to the wooden slingshots
 * and the goalposts in the game.
 */
class Slingshot : public PositionalItem {
private:

public:

    Slingshot(std::shared_ptr<Level> level);

    void XmlLoad(wxXmlNode *node) override;

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void LoadAngrySparty(Angry* sparty);
};

#endif //ANGRYSPARTY_SLINGSHOT_H
