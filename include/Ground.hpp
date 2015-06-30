/* 
 * File:   Ground.hpp
 * Author: ankithbti
 *
 * Created on 30 June, 2015, 11:03 PM
 */

#ifndef GROUND_HPP
#define	GROUND_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "VisibleGameObject.hpp"


class Ground : public VisibleGameObject {
    public:
        Ground();
        ~Ground();
    
    virtual void Draw(sf::RenderWindow& window);

};

#endif	/* GROUND_HPP */

