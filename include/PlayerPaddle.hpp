/* 
 * File:   PlayerPaddle.hpp
 * Author: ankithbti
 *
 * Created on 29 June, 2015, 11:05 PM
 */

#ifndef PLAYERPADDLE_HPP
#define	PLAYERPADDLE_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <VisibleGameObject.hpp>
#include <Box2D/Box2D.h>

class PlayerPaddle : public VisibleGameObject {
public:
    PlayerPaddle();
    ~PlayerPaddle();

    void Update(const sf::Event& e, float elapsedTime);
    void Draw(sf::RenderWindow& rw);

    float GetVelocity() const;

private:
    float _velocity; // -- left ++ right
    float _maxVelocity;
    float _x,_y;
    sf::Sprite _groundSprite;
    
    void createGround();
};


#endif	/* PLAYERPADDLE_HPP */

