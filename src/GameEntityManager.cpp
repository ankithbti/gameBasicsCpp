#include <GameEntityManager.hpp>

namespace gamePlay
{

void GameEntityManager::addGameEntity(const std::string& id, GameEntity::SmartPtr entity)
{
    _gameEntityCont.insert(std::pair<std::string, GameEntity::SmartPtr>(id, entity));
}

GameEntity::SmartPtr GameEntityManager::getGameEntity(const std::string& id) const
{
    GameEntityContainerConstItr it = _gameEntityCont.find(id);
    if(it == _gameEntityCont.end()){
        throw std::runtime_error( " GameEntityManager::getGameEntity() - No entity for Id: " + id);
    }
    return it->second;
}

void GameEntityManager::removeGameEntity(const std::string& id)
{
    // To Do
}



}
