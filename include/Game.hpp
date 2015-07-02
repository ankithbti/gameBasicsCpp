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
#include <PlayerPaddle.hpp>
#include <GameObjectManager.hpp>
#include <Box2D/Box2D.h>
#include <Enemy.hpp>

class Game {
public:

    const static float SCREEN_WIDTH = 800;
    const static float SCREEN_HEIGHT = 600;
    static const float WORLD_SCLAE = 30; // To convert Meters to Pixels ( 1 Mtr = 30 Pxl )
    static const float WORLD_STEP_TIMESTAMP = 1.0f / 60.0f;

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
    static GameObjectManager _gameObjectManager;
    static b2World * _world;
    static bool IsExiting();
    static void GameLoop();
    
    static sf::RectangleShape _box;
    static sf::Sprite _background;
    static float _cameraX;
    static float _cameraY;
    static sf::View _cameraView;
    static Enemy* _enemy;
    static bool _toggle;
    
    
    static void showSplashScreen();
    static void showMenu();
    static sf::Mutex _mutex;

    static sf::Clock _deltaClock; // This will track how much time has past since the last frame
    static sf::Time _timeSinceLastUpdate;
    static sf::Time _timePerFrame;
    static void renderThread(sf::RenderWindow* window, GameObjectManager* gom);
public:

    
    static void start();
    static sf::RenderWindow& GetWindow();

    static b2World* getWorld() {
        return _world;
    }
    
    static sf::Mutex& getMutex() {
        return _mutex;
    }
    //const static sf::Keyboard& GetInput();
};

#endif	/* GAME_HPP */

