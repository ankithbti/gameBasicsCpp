/* 
 * File:   EntityFactory.hpp
 * Author: ankithbti
 *
 * Created on 4 July, 2015, 11:48 PM
 */

#ifndef ENTITYFACTORY_HPP
#define	ENTITYFACTORY_HPP

#include <Constants.hpp>
#include <GameEntity.hpp>

namespace gamePlay {

class GameEntityFactory {
    
public:
    
    GameEntity::SmartPtr createGameEntity(char ch);
    
};

}


#endif	/* ENTITYFACTORY_HPP */

