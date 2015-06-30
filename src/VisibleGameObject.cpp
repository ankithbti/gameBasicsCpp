#include <VisibleGameObject.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>

VisibleGameObject::VisibleGameObject() : _isLoaded(false)
{

}

VisibleGameObject::~VisibleGameObject()
{

}

void VisibleGameObject::Draw(sf::RenderWindow& window)
{
    if (_isLoaded)
    {
        window.draw(_sprite);
    }
}

void VisibleGameObject::Load(std::string filename, const sf::IntRect& rec)
{
    if (_image.loadFromFile(filename) == false)
    {
        _filename = "";
        _isLoaded = false;
    }
    else
    {
        //std::cout << " Loading Player ...  " << std::endl;
        _filename = filename;
        _texture.loadFromImage(_image, rec);
        _sprite.setTexture(_texture, true);
        _isLoaded = true;
    }
}

void VisibleGameObject::SetPosition(float x, float y)
{
    if (_isLoaded)
    {
        _sprite.setPosition(x, y);
    }
}

bool VisibleGameObject::IsLoaded() const
{
    return _isLoaded;
}

void VisibleGameObject::Update(const sf::Event& e, float elapsedTime)
{

}

sf::Vector2f VisibleGameObject::GetPosition() const
{
    if (_isLoaded)
    {
        return _sprite.getPosition();
    }
    return sf::Vector2f();
}

sf::Sprite& VisibleGameObject::GetSprite()
{
    return _sprite;
}








