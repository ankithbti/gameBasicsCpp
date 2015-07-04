
#include <GameScreen.hpp>

int main()
{
    gamePlay::Log _logger("main");
    try{
        gamePlay::GameScreen gs("GameTest");
        gs.start();
    }catch(const std::runtime_error& err){
        _logger.logMessage("Caught exception: " + std::string(err.what()));
    }

    return 0;

//    Game g;
//    g.start();
//    std::cout << " Starting Game... " << std::endl;
//
//    return 0;
}