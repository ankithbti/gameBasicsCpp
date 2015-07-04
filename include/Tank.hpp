/* 
 * File:   Tank.hpp
 * Author: ankithbti
 *
 * Created on 4 July, 2015, 5:31 PM
 */

#ifndef TANK_HPP
#define	TANK_HPP

#include <Constants.hpp>
#include <GameEntity.hpp>

namespace gamePlay
{

class Tank : public GameEntity
{
private:

    sf::Texture _imageTexture;
    sf::Sprite _tankSprite;

public:

    Tank(const std::string& imageFile, const sf::IntRect& rect = sf::IntRect());

    virtual void draw(sf::RenderWindow& window);
    virtual void update(const sf::Event& event, float elapsedTime);

};
}


#endif	/* TANK_HPP */

