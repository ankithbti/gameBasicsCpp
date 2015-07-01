/* 
 * File:   Ball.hpp
 * Author: ankithbti
 *
 * Created on 30 June, 2015, 12:11 AM
 */

#ifndef BALL_HPP
#define	BALL_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <VisibleGameObject.hpp>

class Ball : public VisibleGameObject{
public:
    Ball();
    virtual ~Ball();
    

    virtual void Update(const sf::Event& e, float elapsedTime);
    

    virtual void Draw(sf::RenderWindow& window);


    std::string getId() {
        return "2";
    }
};

#endif	/* BALL_HPP */

