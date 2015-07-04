/* 
 * File:   GameEntityManager.hpp
 * Author: ankithbti
 *
 * Created on 4 July, 2015, 5:20 PM
 */

#ifndef GAMEENTITYMANAGER_HPP
#define	GAMEENTITYMANAGER_HPP

#include <Constants.hpp>
#include <GameEntity.hpp>
#include <map>
#include <boost/foreach.hpp>

namespace gamePlay {

class GameEntityManager : private boost::noncopyable {
public:
    
    typedef boost::shared_ptr<GameEntityManager> SmartPtr;
    typedef boost::shared_ptr<const GameEntityManager> ConstSmartPtr;
    typedef std::map<std::string, GameEntity::SmartPtr> GameEntityContainer;
    typedef GameEntityContainer::iterator GameEntityContainerItr;
    typedef GameEntityContainer::const_iterator GameEntityContainerConstItr;
    
private:
    GameEntityContainer _gameEntityCont;
    
public:
    
    void addGameEntity(const std::string& id, GameEntity::SmartPtr entity);
    GameEntity::SmartPtr getGameEntity(const std::string& id) const ;
    void removeGameEntity(const std::string& id);
    
    void updateAll(const sf::Event& event, float elapsedTime = 1.0f/60.0f){
        BOOST_FOREACH(GameEntityContainer::value_type& val , _gameEntityCont){
            val.second->update(event, elapsedTime);
        }
    }
    
    void drawAll(sf::RenderWindow& window){
        BOOST_FOREACH(GameEntityContainer::value_type& val , _gameEntityCont){
            val.second->draw(window);
        }
    }
    
};

}

#endif	/* GAMEENTITYMANAGER_HPP */

