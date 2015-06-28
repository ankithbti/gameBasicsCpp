/* 
 * File:   Constants.hpp
 * Author: ankithbti
 *
 * Created on 21 June, 2015, 3:01 PM
 */

#ifndef CONSTANTS_HPP
#define	CONSTANTS_HPP

#include <Box2D/Box2D.h>
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 600;
const float M2P = 1; // Because 100 / 60 = 1.6 ( Box2D counts in Meters and OpenGL in Pixels )
const float P2M = 1/M2P;
static b2World * world;


static b2Body* addRect(int x, int y, int w, int h, bool dyn)
{
    std::cout << " Going to Add Rec at : " << x << "," << y << " Of Size: " << w << "," << h << std::endl;
    b2BodyDef bodyDef;
    bodyDef.position.Set(x*P2M, y*P2M); // OpehGL to Box2D dimension ( Pixel to Meter )
    if (dyn)
    {
        bodyDef.type = b2_dynamicBody;
    }
    if (world)
    {
        b2Body* b = world->CreateBody(&bodyDef);
        b2FixtureDef fixDef;
        b2PolygonShape shape;
        shape.SetAsBox(w*P2M / 2, h*P2M / 2);

        std::cout << " Setting Body at Position: " << x*P2M << "," << y*P2M << std::endl;
        std::cout << " Setting Body with size: " << w*P2M/2 << "," << h*P2M/2 << std::endl;
        fixDef.shape = &shape;
        fixDef.density = 1.0;

        b->CreateFixture(&fixDef);
        std::cout << " Created Body... " << std::endl;
        return b;
    }
    return NULL;
}

namespace gameEngine {
    const int DEFAULT_WINDOW_WIDTH = 800;
    const int DEFAULT_WINDOW_HEIGHT = 600;
    const int MAX_KEYS = 1024;
    const int MAX_BUTTONS = 10;
    
    const std::string DEFAULT_WINDOW_TITLE("DEFAULT_TITLE");
    
}

#endif	/* CONSTANTS_HPP */

