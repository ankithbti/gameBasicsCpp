/* 
 * File:   GameEntity.hpp
 * Author: ankithbti
 *
 * Created on 4 July, 2015, 4:55 PM
 */

#ifndef GAMEENTITY_HPP
#define	GAMEENTITY_HPP

#include <Constants.hpp>

namespace gamePlay
{

class GameEntity
{
public:
    typedef boost::shared_ptr<GameEntity> SmartPtr;
    typedef boost::shared_ptr<const GameEntity> ConstSmartPtr;

private:
    std::string _id;
    
public:

    GameEntity(const std::string& id) : _id(id){
        
    }
    
    virtual ~GameEntity(){
        
    }
    
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void update(const sf::Event& event, float elapsedTime) = 0;
    const std::string& getId() const
    {
        return _id;
    }

};
}

#endif	/* GAMEENTITY_HPP */

