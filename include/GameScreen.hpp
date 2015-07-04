/* 
 * File:   GameScreen.hpp
 * Author: ankithbti
 *
 * Created on 4 July, 2015, 1:52 PM
 */

#ifndef GAMESCREEN_HPP
#define	GAMESCREEN_HPP

#include <Constants.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <Box2D/Box2D.h>
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <Log.hpp>
#include <boost/thread.hpp>
#include <boost/enable_shared_from_this.hpp>

namespace gamePlay {

    class GameScreen : private boost::noncopyable {
    public:
        boost::shared_ptr<GameScreen> SmartPtr;

        enum State {
            SHOWING_SPLASH_SCREEN = 0x000, // 0
            SHOWING_MENU = 0x001, // 1
            PLAYING = 0x010, // 2
            PAUSED = 0x011, // 3
            EXITING = 0x100 // 4
        };

    private:
        sf::RenderWindow _window;
        b2World* _world;
        boost::thread * _rendererThread;
        boost::mutex _worldMutex;
        bool _isRunning;
        State _currentState;
        Log _logger;


        void gameLoop();
        bool isExiting(){
            return _currentState == EXITING;
        }

    protected:
        void render();
        void inputHandling();
        void showSplashScreen();
        void showMenu();
    public:
        GameScreen(const std::string& title);
        ~GameScreen();

        b2World * const getWorld() const {
            return _world;
        }

        const sf::RenderWindow& getWindow() const {
            return _window;
        }
        void start(); // might throw
    };
}


#endif	/* GAMESCREEN_HPP */

