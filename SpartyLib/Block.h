/**
 * @file Block.h
 * @author Rajmeet Singh Chandok, zhiqiang ni
 */

#ifndef ANGRYSPARTY_BLOCK_H
#define ANGRYSPARTY_BLOCK_H

#include "Shape.h"

/**
 * Block class derived from Shape
 */
class Block : public Shape {
private:
    /// Draw repeatedly
    int mRepeatX = 1;

public:
    Block(std::shared_ptr<Level> level);

    wxXmlNode *XmlSave(wxXmlNode *node) override;

    void XmlLoad(wxXmlNode *node) override;

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;
};

#endif //ANGRYSPARTY_BLOCK_H
