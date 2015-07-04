#include <Eagle.hpp>

namespace gamePlay
{

Eagle::Eagle(const std::string& imageFile, const sf::IntRect& rect) : GameEntity("Eagle"), _logger("Eagle")
{
    if (!_imageTexture.loadFromFile(imageFile, rect))
    {
        throw std::runtime_error("Eagle::Eagle() - Failed to load the texture from image file: " + imageFile);
    }
    _sprite.setTexture(_imageTexture);
    _logger.logMessage(" Eagle::Eagle() - Loaded Eagle image: " + imageFile);
}

void Eagle::update(const sf::Event& event, float elapsedTime)
{

}

void Eagle::draw(sf::RenderWindow& window)
{
    window.draw(_sprite);
}

void Eagle::setPosition(float x, float y)
{
    _sprite.setPosition(x,y);
}




}
