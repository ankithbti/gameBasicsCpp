#include <Game.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SplashScreen.hpp>
#include <MainMenu.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <Ball.hpp>
#include <boost/thread.hpp>
#include <SFML/Graphics/Color.hpp>

#include "Ground.hpp"
#include "Box.hpp"
#include "ScoreText.hpp"
#include "MyDebugDraw.hpp"
#include "MyContactListener.hpp"

sf::RenderWindow Game::_mainWindow;
Game::GameState Game::_state = Uninitialised;
GameObjectManager Game::_gameObjectManager;
b2World * Game::_world;
sf::Clock Game::_deltaClock;
sf::Time Game::_timeSinceLastUpdate = sf::Time::Zero;
sf::Time Game::_timePerFrame = sf::seconds(1.0f / 60.0f);
sf::Mutex Game::_mutex;
sf::Sprite Game::_background;
float Game::_cameraX = 0.0f;
float Game::_cameraY = 0.0f;
sf::View Game::_cameraView;
sf::RectangleShape Game::_box;
Enemy* Game::_enemy;
bool Game::_toggle = true;

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

        
        //_enemy->_sprite.move(1.0f, 0.0f);

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
                if (currentEvent.key.code == sf::Keyboard::D)
                {
                    _box.setPosition(_box.getPosition().x + 10, _box.getPosition().y);
                    
                    
                    //if(_cameraX >= 0)
                    //  _box.setPosition(_box.getPosition().x - 10, _box.getPosition().y);


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
    MyDebugDraw myDebugDraw;
    _world->SetDebugDraw(&myDebugDraw);
    myDebugDraw.SetFlags(b2Draw::e_shapeBit);

    MyContactListener myContactListener;
    _world->SetContactListener(&myContactListener);

    _mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Pang!");
    _mainWindow.setFramerateLimit(60);

    _enemy = new Enemy("/Users/ankithbti/Development/gameBasics/bin/enemy1.png");
    _enemy->_sprite.setColor(sf::Color::Yellow);
    _enemy->getSprite().setPosition(300,400);

    sf::Image bg;
    if (!bg.loadFromFile("/Users/ankithbti/Development/gameBasics/bin/gamebg1.png"))
    {
        std::cout << " Failed to load BG " << std::endl;
    }
    sf::Texture bgTexture;
    bgTexture.loadFromImage(bg);



    _box.setFillColor(sf::Color::Black);
    //_box.setOrigin(0,0);
    _box.setPosition(50.0f, 10.0f);
    _box.setSize(sf::Vector2f(40, 40));

    _background.setTexture(bgTexture);
    //_cameraX = _box.getPosition().x - SCREEN_WIDTH / 2.0f;
    //_cameraY = SCREEN_HEIGHT / 2.0f;


    //_cameraView.setCenter(_cameraX, _cameraY);
    _cameraView.reset(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
    _cameraView.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));



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
            
            _cameraX = _box.getPosition().x + 10 - SCREEN_WIDTH / 2 ;
            _cameraY = _box.getPosition().y - 10 - SCREEN_HEIGHT / 2 ;

            if (_cameraX < 0)
                _cameraX = 0;
            if (_cameraY < 0)
                _cameraY = 0;
            
            _cameraView.reset(sf::FloatRect(_cameraX, _cameraY, SCREEN_WIDTH, SCREEN_HEIGHT));
            window->setView(_cameraView);
            GetWindow().draw(_background);
            //std::cout << " Box: " << _box.getPosition().x << "," << _box.getPosition().y << std::endl;
            window->setView(window->getDefaultView());

            window->draw(_box);
            if(_enemy->_sprite.getPosition().x > 400){
                _toggle = !_toggle;
            }
            if(_enemy->_sprite.getPosition().x < 300){
                _toggle = !_toggle;
            }
            if(_toggle){
                _enemy->_sprite.move(0.5f,0.f);
            }else{
                _enemy->_sprite.move(-0.5f,0.f);
            }
                        
            window->draw(_enemy->_sprite);      
            gom->DrawAll(*window);
            {
                boost::lock_guard<sf::Mutex> lock(_mutex);
                getWorld()->DrawDebugData();
                getWorld()->Step(WORLD_STEP_TIMESTAMP, 8, 3);
            }
            window->display();
            break;
        }
        default:
            sf::sleep(sf::seconds(1.0f / 60.0f));
            break;
        }

    }
}






