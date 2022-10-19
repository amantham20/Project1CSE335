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

    WoodenSlingshot(Level* level, const std::wstring& filename);

    wxXmlNode *XmlSave(wxXmlNode *node) override;

    void XmlLoad(wxXmlNode *node) override;
};

#endif //ANGRYSPARTY_WOODENSLINGSHOT_H
