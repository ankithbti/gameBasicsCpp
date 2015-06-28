/* 
 * File:   MainMenu.hpp
 * Author: ankithbti
 *
 * Created on 28 June, 2015, 11:40 PM
 */

#ifndef MAINMENU_HPP
#define	MAINMENU_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <list>

class MainMenu{
public:
    enum MenuResult { Nothing, Exit, Play };
    struct MenuItem{
        sf::Rect<int> _rect;
        MenuResult _action;
    };
    MenuResult Show(sf::RenderWindow& window);
private:
    MenuResult GetMenuResponse(sf::RenderWindow& window);
    MenuResult HandleClick(int x, int y);
    std::list<MenuItem> _menuItems;
    
};


#endif	/* MAINMENU_HPP */

