/* 
 * File:   GameMapLoader.hpp
 * Author: ankithbti
 *
 * Created on 4 July, 2015, 11:33 PM
 */

#ifndef GAMEMAPLOADER_HPP
#define	GAMEMAPLOADER_HPP

#include <Constants.hpp>
#include <fstream>
#include <GameEntityFactory.hpp>

#include "GameEntityManager.hpp"
#include <Log.hpp>

namespace gamePlay {
class GameMapLoader {
public:
    typedef boost::shared_ptr<GameMapLoader> SmartPtr;
private:
    GameEntityManager& _gameEntityManager;
    GameEntityFactory _factory;
    Log _logger;
    
    void initialiseGameMap(std::ifstream& fileStream);
public:
    
    GameMapLoader(GameEntityManager& gameEntityManager, const std::string& file);
    
    
};
}

#endif	/* GAMEMAPLOADER_HPP */

