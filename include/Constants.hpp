/* 
 * File:   Constants.hpp
 * Author: ankithbti
 *
 * Created on 21 June, 2015, 3:01 PM
 */

#ifndef CONSTANTS_HPP
#define	CONSTANTS_HPP

// Common Headers as well
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <Box2D/Box2D.h>
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>

namespace gamePlay
{

const float GAME_WIDTH = 800;
const float GAME_HEIGHT = 600;
const float M2P = 30; // Because 100 / 60 = 1.6 ( Box2D counts in Meters and OpenGL in Pixels )
const float P2M = 1 / M2P;
const float GAME_TIME_ITERATION = 1.0f / 60.0f; // 60 frames per sec
const float GAME_GRAVITY_X = 0.0f;
const float GAME_GRAVITY_Y = 9.81f;
}

#endif