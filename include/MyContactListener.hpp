/* 
 * File:   MyContactListener.hpp
 * Author: ankithbti
 *
 * Created on 1 July, 2015, 11:30 PM
 */

#ifndef MYCONTACTLISTENER_HPP
#define	MYCONTACTLISTENER_HPP

#include <Box2D/Box2D.h>

class MyContactListener : public b2ContactListener{
    public:

    virtual void BeginContact(b2Contact* contact);
    virtual void EndContact(b2Contact* contact);
    virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
    virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);

};

#endif	/* MYCONTACTLISTENER_HPP */

