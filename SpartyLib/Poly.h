/**
 * @file Poly.h
 * @author Rajmeet Singh Chandok
 */

#ifndef ANGRYSPARTY_POLY_H
#define ANGRYSPARTY_POLY_H

#include "Shape.h"

/**
 * Polygon class derived from Shape
 */
class Poly : public Shape {
private:
    /// Vertices
    std::vector<b2Vec2> mVertices;
public:

};

#endif //ANGRYSPARTY_POLY_H
