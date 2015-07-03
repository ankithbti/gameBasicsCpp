#include <Enemy.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>

Enemy::Enemy(const std::string& imageFile) : _source(0, Down)
{
    sf::Image i;
    if(!i.loadFromFile(imageFile)){
        std::cout << " Load of Enemy failed..." << std::endl;
    }
    //sf::Texture t;
    _t.loadFromImage(i);
    _sprite.setTexture(_t, true);
}
Enemy::~Enemy()
{

}


