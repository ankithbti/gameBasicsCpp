/* 
 * File:   MyDebugDraw.hpp
 * Author: ankithbti
 *
 * Created on 1 July, 2015, 10:32 PM
 */

#ifndef MYDEBUGDRAW_HPP
#define	MYDEBUGDRAW_HPP

#include <Box2D/Box2D.h>

class MyDebugDraw : public b2Draw {
    public:

    virtual void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

    virtual void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);

    virtual void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);

    virtual void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);

    virtual void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

    virtual void DrawTransform(const b2Transform& xf);





};


#endif	/* MYDEBUGDRAW_HPP */

