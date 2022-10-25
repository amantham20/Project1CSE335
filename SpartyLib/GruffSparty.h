/**
 * @file GruffSparty.h
 * @author Ian Valdovinos Granados
 *
 *
 */

#ifndef ANGRYSPARTY_GRUFFSPARTY_H
#define ANGRYSPARTY_GRUFFSPARTY_H

#include "Angry.h"

class GruffSparty : public Angry {
private:

public:
    GruffSparty(std::shared_ptr<Level> level);

    void XmlLoad(wxXmlNode *node) override;

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;

};

#endif //ANGRYSPARTY_GRUFFSPARTY_H
