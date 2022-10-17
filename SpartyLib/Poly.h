/**
 * @file Poly.h
 * @author Rajmeet Singh Chandok, zhiqiang ni
 */

#ifndef ANGRYSPARTY_POLY_H
#define ANGRYSPARTY_POLY_H

#include "Shape.h"
#include "Vertex.h"
#include <box2d.h>

/**
 * Polygon class derived from Shape
 */
class Poly : public Shape {
private:
    /// Vertices
    std::vector<Vertex> mVertices;

    /// x postion for poly
    double mX;
    /// y postion for poly
    double mY;
public:

    wxXmlNode *XmlSave(wxXmlNode *node) override;

    void XmlLoad(wxXmlNode *node) override;
};

#endif //ANGRYSPARTY_POLY_H
