#include <Game.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SplashScreen.hpp>
#include <MainMenu.hpp>

sf::RenderWindow Game::_mainWindow;
Game::GameState Game::_state = Uninitialised;

void Game::GameLoop()
{
    sf::Event currentEvent;
    while (_mainWindow.pollEvent(currentEvent))
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
            _mainWindow.clear(sf::Color(255, 0, 0));
            _mainWindow.display();

            if (currentEvent.type == sf::Event::Closed)
            {
                _state = Game::Exiting;
            }
            break;
        }
        }
    }
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

    _mainWindow.create(sf::VideoMode(1024, 768, 32), "Pang!");
    _state = Game::ShowingSplash;

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
    switch(result){
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





