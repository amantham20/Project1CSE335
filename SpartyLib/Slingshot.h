/**
 * @file Slingshot.h
 * @author Milan Mihailovic, zhiqiang ni
 *
 * Base Class for the slingshot items in the game.
 */

#ifndef ANGRYSPARTY_SLINGSHOT_H
#define ANGRYSPARTY_SLINGSHOT_H

#include "PositionalItem.h"

/**
 * Base class for a slingshot
 * This applies to the wooden slingshots
 * and the goalposts in the game.
 */
class Slingshot : public PositionalItem {
private:

public:

    Slingshot(Level *level);
    Slingshot(std::shared_ptr<Level> level);

    wxXmlNode *XmlSave(wxXmlNode *node) override;

    void XmlLoad(wxXmlNode *node) override;
};

#endif //ANGRYSPARTY_SLINGSHOT_H
