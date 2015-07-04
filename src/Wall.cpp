#include <Wall.hpp>

namespace gamePlay
{

Wall::Wall(const std::string& imageFile, const sf::IntRect& rect) : GameEntity("Wall"), _logger("Wall")
{
    if(!_imageTexture.loadFromFile(imageFile, rect)){
        throw std::runtime_error("Wall::Wall() - Failed to load the texture from image file: " + imageFile);
    }
    _wallSprite.setTexture(_imageTexture);
    _logger.logMessage(" Wall::Wall() - Loaded wall image: " + imageFile);
}

void Wall::update(const sf::Event& event, float elapsedTime)
{

}


void Wall::draw(sf::RenderWindow& window)
{
    window.draw(_wallSprite);
}

void Wall::setPosition(float x, float y)
{
    _wallSprite.setPosition(x, y);
}



}
