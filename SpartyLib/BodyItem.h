/**
 * @file BodyItem.h
 * @author Milan Mihailovic
 *
 *
 */

#ifndef ANGRYSPARTY_BODYITEM_H
#define ANGRYSPARTY_BODYITEM_H

#include "PositionalItem.h"
#include "b2_body.h"
#include <b2_math.h>

class BodyItem : public PositionalItem {
private:
    /// box2d Item Body
    b2Body* mBody;

    double mWidth = 0;
    double mHeight= 0;

public:

    BodyItem(std::shared_ptr<Level> level);

    void XmlLoad(wxXmlNode *node) override;

    /**
     * Getter for mBody
     * @return mBody
     */
    b2Body* GetBody() { return mBody; }

    b2Vec2 Getb2Vec() { return b2Vec2(mWidth, mHeight); }

};

#endif //ANGRYSPARTY_BODYITEM_H
