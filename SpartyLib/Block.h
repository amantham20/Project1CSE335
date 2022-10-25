/**
 * @file Block.h
 * @author Rajmeet Singh Chandok, zhiqiang ni
 *
 * Block in a given Level
 */

#ifndef ANGRYSPARTY_BLOCK_H
#define ANGRYSPARTY_BLOCK_H

#include "BodyItem.h"

/**
 * Block class derived from BodyItem
 */
class Block : public BodyItem {
private:
    /// Draw repeatedly
    int mRepeatX = 1;

public:
    Block(std::shared_ptr<Level> level);

    void XmlLoad(wxXmlNode *node) override;

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;
};

#endif //ANGRYSPARTY_BLOCK_H
