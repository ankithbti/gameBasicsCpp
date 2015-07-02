#include <Enemy.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>

Enemy::Enemy(const std::string& imageFile)
{
    sf::Image i;
    if(!i.loadFromFile(imageFile)){
        std::cout << " Load of Enemy failed..." << std::endl;
    }
    sf::Texture t;
    t.loadFromImage(i);
    _sprite.setTexture(t, true);
}
Enemy::~Enemy()
{

}


