#include <GameScreen.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <boost/thread/detail/thread.hpp>
#include <boost/bind.hpp>
#include <SFML/Window/Event.hpp>
#include <sys/ttycom.h>
#include <SFML/Window/Keyboard.hpp>
#include <Tank.hpp>
#include <SFML/Graphics/Rect.hpp>

namespace gamePlay
{

GameScreen::GameScreen(const std::string& title) :
_window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), title),
_world(new b2World(b2Vec2(GAME_GRAVITY_X, GAME_GRAVITY_Y))),
_isRunning(false),
_currentState(SHOWING_SPLASH_SCREEN),
_logger("GameScreen")

{
    _window.clear(sf::Color::White);

    // Initialise Tank
    GameEntity::SmartPtr tank(new Tank("/Users/ankithbti/Development/gameBasics/bin/tankGameSprite.png", sf::IntRect(0, 30, 30, 30)));
    _gameEntityManager.addGameEntity("Tank1", tank);
}

GameScreen::~GameScreen()
{
    if (_world)
    {
        delete _world;
    }
    _window.close();
}

void GameScreen::start()
{
    if (_isRunning)
    {
        _logger.logMessage(" Already Running....Can not start again...");
    }
    _isRunning = true;
    _rendererThread = new boost::thread(boost::bind(&GameScreen::render, this));
    //boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
    _logger.logMessage(" Starting Game....");
    while (!isExiting())
    {
        gameLoop();
    }
    _rendererThread->join();
    _logger.logMessage(" Stopping Game....");
}

void GameScreen::gameLoop()
{
    switch (_currentState)
    {
    case SHOWING_SPLASH_SCREEN:
    {
        showSplashScreen();
        _currentState = PLAYING;
    }
        break;
    case SHOWING_MENU:
    {
        showMenu();
    }
        break;
    case PLAYING:
    {
        inputHandling();
    }
        break;
    case PAUSED:
        break;
    case EXITING:
        break;
    default:
        break;
    }
}

void GameScreen::showSplashScreen()
{
    sf::Image image;
    std::string imageFile = "/Users/ankithbti/Development/gameBasics/bin/pang.png";
    if (!image.loadFromFile(imageFile))
    {
        return;
    }
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite(texture);

    _window.clear(sf::Color::Green);
    _window.draw(sprite);
    _window.display();

    sf::Event e;
    while (true)
    {
        while (_window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed ||
                    e.type == sf::Event::MouseButtonPressed ||
                    e.type == sf::Event::KeyPressed)
            {
                return;
            }
        }
    }
}

void GameScreen::showMenu()
{

}



// Input Handling

void GameScreen::inputHandling()
{
    sf::Event event;
    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            _currentState = EXITING;
        }
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                _currentState = SHOWING_SPLASH_SCREEN;
            }
        }
        // For All Game entities
        _gameEntityManager.updateAll(event);
    }
}

// Render Handling

void GameScreen::render()
{
    try
    {
        while (!isExiting())
        {
            switch (_currentState)
            {
            case PLAYING:
            {
                _window.clear(sf::Color::Green);

                // Test Draw String
                sf::Font font;
                font.loadFromFile("/Users/ankithbti/Development/Quand_tu_dors_.otf");
                sf::Text text;
                text.setFont(font);
                text.setString("Testing the screen drawing for Game....");
                text.setCharacterSize(2.0f);
                _window.draw(text);

                // For All Game entities
                _gameEntityManager.drawAll(_window);

                _window.display();
            }
                break;
            default:
            {
                boost::this_thread::sleep(boost::posix_time::milliseconds(500));
            }
                break;
            }
        }
    }
    catch (const boost::thread_interrupted& err)
    {
        // Ignore
    }
    catch (...)
    {
        // Ignore
    }
    _logger.logMessage("Ending Render Thread....");
}


}
