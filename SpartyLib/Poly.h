/**
 * @file Poly.h
 * @author Rajmeet Singh Chandok, zhiqiang ni
 *
 * Class that describes a Polygon
 */

#ifndef ANGRYSPARTY_POLY_H
#define ANGRYSPARTY_POLY_H

#include "BodyItem.h"
//#include <box2d.h>

/**
 * Polygon class derived from BodyItem
 */
class Poly : public BodyItem {
private:
    /// Vertices
    std::vector<b2Vec2> mVertices;

public:


    Poly(std::shared_ptr<Level> level);

    void XmlLoad(wxXmlNode *node) override;

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;
};

#endif //ANGRYSPARTY_POLY_H
