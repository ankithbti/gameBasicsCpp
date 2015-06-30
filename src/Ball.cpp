#include <Ball.hpp>

Ball::Ball()
{
    Load("/Users/ankithbti/Development/Gamebasics/bin/ground1.jpg", sf::IntRect(0,0,10,10));
    GetSprite().setPosition(15, 15);
}

Ball::~Ball()
{

}


