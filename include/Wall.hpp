/* 
 * File:   Wall.hpp
 * Author: ankithbti
 *
 * Created on 4 July, 2015, 11:53 PM
 */

#ifndef WALL_HPP
#define	WALL_HPP

#include <Constants.hpp>

#include "GameEntity.hpp"
#include "Log.hpp"

namespace gamePlay
{

class Wall : public GameEntity
{
private:

    sf::Texture _imageTexture;
    sf::Sprite _wallSprite;
    Log _logger;

public:

    Wall(const std::string& imageFile, const sf::IntRect& rect = sf::IntRect());

    virtual void draw(sf::RenderWindow& window);
    virtual void update(const sf::Event& event, float elapsedTime);

    virtual void setPosition(float x, float y);

};

}

#endif	/* WALL_HPP */

