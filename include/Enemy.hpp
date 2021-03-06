/* 
 * File:   Enemy.hpp
 * Author: ankithbti
 *
 * Created on 2 July, 2015, 11:54 PM
 */

#ifndef ENEMY_HPP
#define	ENEMY_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Enemy {
public:
    sf::Texture _t;
    sf::Sprite _sprite;

    enum Direction {
        Down, Left, Right, Up
    };
    
     sf::Vector2i _source ;
    

public:

    Enemy(const std::string& imageFile);
    ~Enemy();

    sf::Sprite & getSprite() {
        return _sprite;
    }


};


#endif	/* ENEMY_HPP */

