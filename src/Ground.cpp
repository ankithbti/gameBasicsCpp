#include <Ground.hpp>
#include <iostream>
#include "Game.hpp"

Ground::Ground()
{
    Load("/Users/ankithbti/Development/Gamebasics/bin/ground1.jpg");
    //GetSprite().setPosition(0, 500);
    GetSprite().setTextureRect(sf::IntRect(0, 0, static_cast<int> (Game::SCREEN_WIDTH), 50));

    // Create Ground
    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(static_cast<float> ((Game::SCREEN_WIDTH / 2) / Game::WORLD_SCLAE), static_cast<float> ((Game::SCREEN_HEIGHT - 50) / Game::WORLD_SCLAE));
    BodyDef.type = b2_staticBody;
    b2Body* Body = Game::getWorld()->CreateBody(&BodyDef);
    b2PolygonShape Shape;
    // Divide your desired width and height by 2.
    Shape.SetAsBox(static_cast<float> ((Game::SCREEN_WIDTH / 2) / Game::WORLD_SCLAE), static_cast<float> ((50.f / 2) / Game::WORLD_SCLAE)); // Creates a box shape. 
    b2FixtureDef FixtureDef;
    FixtureDef.density = 0.f; // Sets the density of the body
    FixtureDef.shape = &Shape; // Sets the shape
    Body->CreateFixture(&FixtureDef); // Apply the fixture definition

    for (b2Body* BodyIterator = Game::getWorld()->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
    {
        std::cout << " Got Body...  " << std::endl;
    }
}

Ground::~Ground()
{

}

void Ground::Draw(sf::RenderWindow& window)
{
    if (_isLoaded)
    {

        for (b2Body* BodyIterator = Game::getWorld()->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
        {
            if (BodyIterator->GetType() == b2_dynamicBody)
            {

            }
            else
            {
                
                GetSprite().setOrigin(Game::SCREEN_WIDTH/2, 25.0f);
                GetSprite().setPosition(BodyIterator->GetPosition().x * Game::WORLD_SCLAE, BodyIterator->GetPosition().y * Game::WORLD_SCLAE);
                window.draw(GetSprite());
                
            }
        }
    }
    else
    {
        std::cout << " Ground not loaded... " << std::endl;
    }
}





