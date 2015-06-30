#include <GameObjectManager.hpp>

#include "Game.hpp"

GameObjectManager::GameObjectManager()
{

}

GameObjectManager::~GameObjectManager()
{
    std::for_each(_gameObjects.begin(), _gameObjects.end(), GameObjectDeallocator());
}

void GameObjectManager::Add(std::string name, VisibleGameObject* gameObject)
{
    _gameObjects.insert(std::pair<std::string, VisibleGameObject*>(name, gameObject));
}

void GameObjectManager::DrawAll(sf::RenderWindow& renderWindow)
{
    std::map<std::string, VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
    while (itr != _gameObjects.end())
    {
        itr->second->Draw(renderWindow);
        itr++;
    }
}

VisibleGameObject* GameObjectManager::Get(std::string name) const
{
    std::map<std::string, VisibleGameObject*>::const_iterator results = _gameObjects.find(name);
    if (results == _gameObjects.end())
    {
        return NULL;
    }
    return results->second;
}

int GameObjectManager::GetObjectCount() const
{
    return _gameObjects.size();
}

void GameObjectManager::Remove(std::string name)
{
    std::map<std::string, VisibleGameObject*>::iterator results = _gameObjects.find(name);
    if (results != _gameObjects.end())
    {
        delete results->second;
        _gameObjects.erase(results);
    }
}

void GameObjectManager::UpdateAll(const sf::Event& e)
{
    std::map<std::string, VisibleGameObject*>::const_iterator itr =
            _gameObjects.begin();
    float timeDelta = 60.0f; // Frame Rate

    while (itr != _gameObjects.end())
    {
        itr->second->Update(e,timeDelta);
        itr++;
    }
}








