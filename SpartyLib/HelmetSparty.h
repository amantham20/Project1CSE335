/**
 * @file HelmetSparty.h
 * @author Ian Valdovinos Granados
 *
 *
 */

#ifndef ANGRYSPARTY_HELMETSPARTY_H
#define ANGRYSPARTY_HELMETSPARTY_H

#include "Angry.h"

class HelmetSparty : public Angry {
private:

public:

    HelmetSparty(std::shared_ptr<Level> level);

    void XmlLoad(wxXmlNode *node) override;

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;

};

#endif //ANGRYSPARTY_HELMETSPARTY_H
