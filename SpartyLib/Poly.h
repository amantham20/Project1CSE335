/**
 * @file Poly.h
 * @author Rajmeet Singh Chandok, zhiqiang ni
 */

#ifndef ANGRYSPARTY_POLY_H
#define ANGRYSPARTY_POLY_H

#include "Shape.h"
#include <box2d.h>

/**
 * Polygon class derived from Shape
 */
class Poly : public Shape {
private:
    /// Vertices
    std::vector<b2Vec2> mVertices;

public:

    wxXmlNode *XmlSave(wxXmlNode *node) override;

    void XmlLoad(wxXmlNode *node) override;
};

#endif //ANGRYSPARTY_POLY_H
