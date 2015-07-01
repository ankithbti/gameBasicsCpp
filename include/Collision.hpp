/* 
 * File:   Collision.hpp
 * Author: ankithbti
 *
 * Created on 1 July, 2015, 1:52 PM
 */

#ifndef COLLISION_HPP
#define	COLLISION_HPP

#include <Box2D/Box2D.h>

class Collision : public b2ContactListener{
    pblic:

    virtual void BeginContact(b2Contact* contact);

    virtual void EndContact(b2Contact* contact);


};

#endif	/* COLLISION_HPP */

