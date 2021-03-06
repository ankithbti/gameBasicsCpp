#include <Ball.hpp>
#include <iostream>
#include "GameObjectManager.hpp"
#include "Game.hpp"
#include <boost/thread.hpp>
#include <boost/algorithm/string.hpp>

Ball::Ball()
{
    Load("/Users/ankithbti/Development/Gamebasics/bin/black.jpg", sf::IntRect(0, 0, 20, 20));
    GetSprite().setPosition(15, 15);
}

Ball::~Ball()
{

}

void Ball::Update(const sf::Event& e, float elapsedTime)
{
    if (e.type == sf::Event::MouseButtonPressed)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            // Left Mouse Button Pressed
            float x = sf::Mouse::getPosition(Game::GetWindow()).x;
            float y = sf::Mouse::getPosition(Game::GetWindow()).y;
            std::cout << " Right Mouse Button Pressed at " << x << "," << y << std::endl;

            // Create new Box at this location
            // Add Dynamic Box
            b2BodyDef BodyDef;
            BodyDef.position = b2Vec2(x / Game::WORLD_SCLAE, y / Game::WORLD_SCLAE);
            BodyDef.type = b2_dynamicBody;
            BodyDef.userData = (void*)this;
            b2Body* Body;
            {
                boost::lock_guard<sf::Mutex> lock(Game::getMutex());
                Body = Game::getWorld()->CreateBody(&BodyDef);
            }
            b2PolygonShape Shape;
            Shape.SetAsBox((20.f / 2) / Game::WORLD_SCLAE, (20.f / 2) / Game::WORLD_SCLAE);
            b2FixtureDef FixtureDef;
            FixtureDef.density = 1.f;
            FixtureDef.friction = 0.7f;
            FixtureDef.shape = &Shape;
            FixtureDef.restitution = 0.4f;
            Body->CreateFixture(&FixtureDef);
        }
    }
}

void Ball::Draw(sf::RenderWindow& window)
{
    //VisibleGameObject::Draw(window);
    if (_isLoaded)
    {

        for (b2Body* BodyIterator = Game::getWorld()->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
        {
            if (BodyIterator->GetType() == b2_dynamicBody && ((VisibleGameObject*)BodyIterator->GetUserData())->getId() == getId() )
            {
                GetSprite().setOrigin(10.f, 10.f);
                GetSprite().setPosition(Game::WORLD_SCLAE * BodyIterator->GetPosition().x, Game::WORLD_SCLAE * BodyIterator->GetPosition().y);
                GetSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);
                window.draw(GetSprite());
            }
            else
            {

            }
        }
    }
    else
    {
        std::cout << " Box not loaded... " << std::endl;
    }
}




