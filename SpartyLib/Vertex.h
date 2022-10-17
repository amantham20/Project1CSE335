/**
 * @file Vertex.h
 * @author Rajmeet Singh Chandok, zhiqiang ni
 *
 *
 */

#ifndef ANGRYSPARTY_VERTEX_H
#define ANGRYSPARTY_VERTEX_H

#include "Poly.h"

/**
 * Vertex class derived from Polygon Class
 */
class Vertex : public Poly {
private:
    /// X position
    double mX;

    /// Y position
    double mY;

public:
    /**
     * Getter for X position
     * @return X position
     */
    double getX(){ return mX; }

    /**
     * Getter for Y position
     * @return Y position
     */
    double getY(){ return mY; }

    /**
     * Setter for X position
     * @param x
     */
    void setX(double x) { mX = x; }

    /**
     * Setter for Y position
     * @param y
     */
    void setY(double y) { mY = y; }

    wxXmlNode *XmlSave(wxXmlNode *node);

    void XmlLoad(wxXmlNode *node);
};

#endif //ANGRYSPARTY_VERTEX_H
