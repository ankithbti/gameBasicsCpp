#include <GameEntityFactory.hpp>
#include <Wall.hpp>
#include <Eagle.hpp>
#include <Tank.hpp>


namespace gamePlay
{

GameEntity::SmartPtr GameEntityFactory::createGameEntity(char ch)
{
    GameEntity::SmartPtr gameEntity;
    switch (ch)
    {
    case 'W':
    {
        gameEntity = GameEntity::SmartPtr(new Wall("/Users/ankithbti/Development/gameBasics/resources/tankGameSprite.png", sf::IntRect(0, 64, 32, 32)));
    }
        break;
    case 'E':
    {
        gameEntity = GameEntity::SmartPtr(new Eagle("/Users/ankithbti/Development/gameBasics/resources/tankGameSprite.png", sf::IntRect(160, 64, 32, 32)));
    }
        break;
    case 'T':
    {
        gameEntity = GameEntity::SmartPtr(new Tank("/Users/ankithbti/Development/gameBasics/resources/tankGameSprite.png", sf::IntRect(32, 0, 32, 32)));
    }
    default:
        break;
    }
    return gameEntity;
}


}
