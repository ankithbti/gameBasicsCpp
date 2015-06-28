/* 
 * File:   Game.hpp
 * Author: ankithbti
 *
 * Created on 28 June, 2015, 11:18 PM
 */

#ifndef GAME_HPP
#define	GAME_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Game {
private:

    enum GameState {
        Uninitialised,
        ShowingSplash,
        Paused,
        ShowingMenu,
        Playing,
        Exiting
    };
    static GameState _state;
    static sf::RenderWindow _mainWindow;

    static bool IsExiting();
    static void GameLoop();
    
    static void showSplashScreen();
    static void showMenu();

public:

    static void start();

};

#endif	/* GAME_HPP */

