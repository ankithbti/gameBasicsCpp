#include <MyContactListener.hpp>

#include "VisibleGameObject.hpp"
#include <boost/algorithm/string.hpp>
#include <iostream>

void MyContactListener::BeginContact(b2Contact* contact)
{
    void * bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    void * bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();

    if (contact->IsTouching())
    {
        if (bodyUserDataA && bodyUserDataB)
        {
            if (boost::iequals(static_cast<VisibleGameObject*> (bodyUserDataA)->getId(),
                               static_cast<VisibleGameObject*> (bodyUserDataB)->getId()))
            {
                std::cout << " Box contacted... " << std::endl;
            }
        }
    }
}

void MyContactListener::EndContact(b2Contact* contact)
{

}

void MyContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{

}

void MyContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{

}




