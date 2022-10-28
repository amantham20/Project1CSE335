/**
 * @file Physics.h
 * @author Ian Valdovinos Granados
 *
 * Physics system for a level
 *
 */

#ifndef ANGRYSPARTY_PHYSICS_H
#define ANGRYSPARTY_PHYSICS_H

//#include <box2d.h>

/**
 * Class that describes the physics system for a level
 */
class Physics {
private:

    /// The box2d world
    b2World mWorld;

    // A ground reference object
    b2Body* mGround;

public:
    /// Default constructor (disabled)
    Physics() = delete;

    Physics(const b2Vec2& size);

    b2World* GetWorld() { return &mWorld; }

};

#endif //ANGRYSPARTY_PHYSICS_H
