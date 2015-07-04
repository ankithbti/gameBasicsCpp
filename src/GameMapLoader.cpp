#include <GameMapLoader.hpp>
#include <string>
#include <boost/lexical_cast.hpp>

#include "Log.hpp"
#include <sstream>

namespace gamePlay
{

GameMapLoader::GameMapLoader(GameEntityManager& gameEntityManager, const std::string& file) :
_gameEntityManager(gameEntityManager),
_logger("GameMapLoader")
{
    std::ifstream mapFileStream(file.c_str());
    if (!mapFileStream.good())
    {
        throw std::runtime_error("GameMapLoader::GameMapLoader() - No such readable file: " + file);
    }
    initialiseGameMap(mapFileStream);
}

void GameMapLoader::initialiseGameMap(std::ifstream& fileStream)
{
    std::string line;
    int row = 0;
    while (std::getline(fileStream, line))
    {
        for (int i = 0; i < line.length(); ++i)
        {
            GameEntity::SmartPtr gameEntity = _factory.createGameEntity(line[i]);
            gameEntity->setPosition(row * 32.0f, i * 32.0f);
            std::stringstream msg;
            msg << " At " << row * 32.0f << "," << i * 32.0f;
            _logger.logMessage(msg.str() + " Loaded Entity: " + gameEntity->getId());
            std::stringstream entityId;
            entityId << row << "," << i ;
            _gameEntityManager.addGameEntity(entityId.str(), gameEntity);
              
        }
        ++row;
    }
//    GameEntity::SmartPtr gameEntity = _factory.createGameEntity('W');
//    gameEntity->setPosition(100,400);
//    _gameEntityManager.addGameEntity("W", gameEntity);
}

}
