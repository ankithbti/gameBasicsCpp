#include <SFML/Window.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <Game.hpp>

#include <GameScreen.hpp>

int main()
{
    {
        gamePlay::GameScreen gs("GameTest");
        gs.start();
    }

    return 0;

    Game g;
    g.start();
    std::cout << " Starting Game... " << std::endl;

    return 0;
}