#include <Tank.hpp>
#include <SFML/Graphics/Image.hpp>

namespace gamePlay
{

Tank::Tank(const std::string& imageFile, const sf::IntRect& rect) : GameEntity("Tank")
{
    
    if(!_imageTexture.loadFromFile(imageFile, rect)){
        throw std::runtime_error("Tank::Tank() - Failed to load the texture from image file: " + imageFile);
    }
    _tankSprite.setTexture(_imageTexture);
}

void Tank::update(const sf::Event& event, float elapsedTime)
{

}

void Tank::draw(sf::RenderWindow& window)
{
    window.draw(_tankSprite);
}


}
