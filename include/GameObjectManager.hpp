/* 
 * File:   GameObjectManager.hpp
 * Author: ankithbti
 *
 * Created on 29 June, 2015, 11:24 PM
 */

#ifndef GAMEOBJECTMANAGER_HPP
#define	GAMEOBJECTMANAGER_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include "VisibleGameObject.hpp"

class GameObjectManager {
    
private:
    std::map<std::string, VisibleGameObject*> _gameObjects;
    struct GameObjectDeallocator{
        void operator()(const std::pair<std::string,VisibleGameObject*>& p) const{
            delete p.second;
        }
    };
public:
    GameObjectManager();
    ~GameObjectManager();

    void Add(std::string name, VisibleGameObject* gameObject);
    void Remove(std::string name);
    int GetObjectCount() const;
    VisibleGameObject* Get(std::string name) const;
    void DrawAll(sf::RenderWindow& renderWindow);
    void UpdateAll(const sf::Event& e);
};

#endif	/* GAMEOBJECTMANAGER_HPP */

