/* 
 * File:   Box.hpp
 * Author: ankithbti
 *
 * Created on 30 June, 2015, 11:27 PM
 */

#ifndef BOX_HPP
#define	BOX_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "VisibleGameObject.hpp"

class Box : public VisibleGameObject {
public:
    Box();
    ~Box();

    virtual void Draw(sf::RenderWindow& window);

    virtual void Update(const sf::Event& e, float elapsedTime);

    const int& getBoxCount() const {
        return _boxCount;
    }

    std::string getId() {
        return "1";
    }
private:
    int _boxCount;
};

#endif	/* BOX_HPP */

