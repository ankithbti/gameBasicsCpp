#include <MyDebugDraw.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <GL/glew.h>

#include "Game.hpp"

void MyDebugDraw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
{
    std::cout << " Drawing Circle " << std::endl;
}

void MyDebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
    std::cout << " Drawing Polgon " << std::endl;
}

void MyDebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
    std::cout << " Drawing Segment " << std::endl;
}

void MyDebugDraw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
{
    std::cout << " Drawing Solid Circle " << std::endl;
}

void MyDebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
    //std::cout << " Drawing Solid Polygon " << std::endl;
    if (vertices)
    {
        sf::ConvexShape polygon;
        polygon.setPointCount(vertexCount);
        for (int32 i = 0; i < vertexCount; i++)
        {
            b2Vec2 vertex = vertices[i];
            sf::Vector2f point(vertex.x * Game::WORLD_SCLAE, vertex.y * Game::WORLD_SCLAE);
            polygon.setPoint(i, point);
            polygon.setFillColor(sf::Color(color.r, color.g, color.b));
            polygon.setOutlineColor(sf::Color(color.r, color.g, color.b, 50));
        }
        polygon.setOutlineThickness(5.0f);
        Game::GetWindow().draw(polygon);
    }
}

void MyDebugDraw::DrawTransform(const b2Transform& xf)
{

}






