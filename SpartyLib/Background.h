/**
 * @file Background.h
 * @author Aman Dhruva Thamminana
 *
 *
 */

#ifndef ANGRYSPARTY_BACKGROUND_H
#define ANGRYSPARTY_BACKGROUND_H

#include "Picture.h"

class Background : public Item{
private:
public:
    Background(Level *level);
    void XmlLoad(wxXmlNode *node) override;
};

#endif //ANGRYSPARTY_BACKGROUND_H
