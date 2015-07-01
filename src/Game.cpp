#include <Game.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SplashScreen.hpp>
#include <MainMenu.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <Ball.hpp>
#include <boost/thread.hpp>

#include "Ground.hpp"
#include "Box.hpp"
#include "ScoreText.hpp"

sf::RenderWindow Game::_mainWindow;
Game::GameState Game::_state = Uninitialised;
GameObjectManager Game::_gameObjectManager;
b2World * Game::_world;
sf::Clock Game::_deltaClock;
sf::Time Game::_timeSinceLastUpdate = sf::Time::Zero;
sf::Time Game::_timePerFrame = sf::seconds(1.0f / 60.0f);
sf::Mutex Game::_mutex;

void Game::GameLoop()
{


    switch (_state)
    {
    case Game::ShowingMenu:
    {
        showMenu();
        break;
    }
    case Game::ShowingSplash:
    {
        showSplashScreen();
        break;
    }
    case Game::Playing:
    {

        sf::Time deltaTime = _deltaClock.restart(); // Restart returns the time since the last restart call
        _timeSinceLastUpdate += deltaTime;

        //_mainWindow.clear(sf::Color(255, 255, 255));

        //        while (_timeSinceLastUpdate >= _timePerFrame)
        //        {
        _timeSinceLastUpdate -= _timePerFrame;


        sf::Event currentEvent;

        while (_mainWindow.pollEvent(currentEvent))
        {
            if (currentEvent.type == sf::Event::Closed)
            {
                _state = Game::Exiting;
            }
            if (currentEvent.type == sf::Event::KeyPressed)
            {
                if (currentEvent.key.code == sf::Keyboard::Escape)
                {
                    showMenu();
                }
            }
            _gameObjectManager.UpdateAll(currentEvent);
        }// end of while for events handling

        //}

        //_gameObjectManager.DrawAll(_mainWindow);

        //_world->Step(WORLD_STEP_TIMESTAMP, 8, 3);
        //_mainWindow.display();

        break;
    }
    default:
        break;
    }// end of switch

}

bool Game::IsExiting()
{
    if (_state == Game::Exiting)
        return true;
    else
        return false;
}

void Game::start()
{
    if (_state != Uninitialised)
        return;


    // Create World
    b2Vec2 gravity(0, 9.81f);
    _world = new b2World(gravity);
    //_world->SetAllowSleeping(true);
    //_world->SetContinuousPhysics(true);
    //_world->SetAutoClearForces(false);

    _mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Pang!");
    _mainWindow.setFramerateLimit(60);



    PlayerPaddle *player1 = new PlayerPaddle();
    Ball *b = new Ball();
    Ground * g = new Ground();
    Box *box = new Box();
    ScoreText * st = new ScoreText(box);
    _gameObjectManager.Add("Paddle1", player1);
    _gameObjectManager.Add("Ball", b);
    _gameObjectManager.Add("Ground", g);
    _gameObjectManager.Add("Box", box);
    _gameObjectManager.Add("ScoreText", st);
    _state = Game::ShowingSplash;

    boost::thread t(renderThread, &_mainWindow, &_gameObjectManager);

    sf::sleep(sf::seconds(1));
    while (!IsExiting())
    {
        GameLoop();
    }

    _mainWindow.close();
}

void Game::showMenu()
{
    MainMenu mm;
    MainMenu::MenuResult result = mm.Show(_mainWindow);
    switch (result)
    {
    case MainMenu::Play:
    {
        _state = Playing;
        break;
    }
    case MainMenu::Exit:
    {
        _state = Exiting;
        break;
    }
    }
}

void Game::showSplashScreen()
{
    SplashScreen splashScreen;
    splashScreen.show(_mainWindow);
    _state = ShowingMenu;
}

//const sf::Keyboard& Game::GetInput()
//{
//}

sf::RenderWindow& Game::GetWindow()
{
    return _mainWindow;
}

void Game::renderThread(sf::RenderWindow*window, GameObjectManager* gom)
{
    while (!IsExiting())
    {
        switch (_state)
        {
        case Game::Playing:
        {
            window->clear(sf::Color(255, 0, 0));
            gom->DrawAll(*window);
            {
                boost::lock_guard<sf::Mutex> lock(_mutex);
                getWorld()->Step(WORLD_STEP_TIMESTAMP, 8, 3);
            }
            window->display();
            break;
        }
        default:
            sf::sleep(sf::seconds(1.0f/60.0f));
            break;
        }

    }
}






