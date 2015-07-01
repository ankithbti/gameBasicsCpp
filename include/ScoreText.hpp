/* 
 * File:   ScoreText.hpp
 * Author: ankithbti
 *
 * Created on 1 July, 2015, 1:07 PM
 */


#ifndef SCORETEXT_HPP
#define	SCORETEXT_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <Box2D/Box2D.h>

#include "VisibleGameObject.hpp"
#include <Box.hpp>


class ScoreText : public VisibleGameObject {
    public:
        
        ScoreText(Box* box);
        ~ScoreText();
        

    virtual void Update(const sf::Event& e, float elapsedTime);
    virtual void Draw(sf::RenderWindow& window);

        private:
            sf::Text _text;
            sf::Font _font;
            Box* _box;
};

#endif	/* SCORETEXT_HPP */

