/* 
 * File:   Eagle.hpp
 * Author: ankithbti
 *
 * Created on 5 July, 2015, 12:59 AM
 */

#ifndef EAGLE_HPP
#define	EAGLE_HPP

#include <GameEntity.hpp>
#include <Log.hpp>

namespace gamePlay
{

class Eagle : public GameEntity
{
private:

    sf::Texture _imageTexture;
    sf::Sprite _sprite;
    Log _logger;

public:

    Eagle(const std::string& imageFile, const sf::IntRect& rect = sf::IntRect());

    virtual void draw(sf::RenderWindow& window);
    virtual void update(const sf::Event& event, float elapsedTime);

    virtual void setPosition(float x, float y);

};

}



#endif	/* EAGLE_HPP */

