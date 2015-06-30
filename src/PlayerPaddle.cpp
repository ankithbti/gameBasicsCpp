#include <PlayerPaddle.hpp>
#include <Game.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

PlayerPaddle::PlayerPaddle() :
_velocity(0),
_maxVelocity(600.0f),
_x(10),
_y(300)
{
    Load("/Users/ankithbti/Development/gameBasics/bin/paddle.png"); // 90x30
    //assert(IsLoaded());
    //GetSprite().setCenter(GetSprite().getSize().x / 2, GetSprite().getSize().y / 2);
    GetSprite().setPosition(_x, _y);

    // Load Ground Sprite
    std::string groundImageFile = "/Users/ankithbti/Development/gameBasics/bin/ground1.jpg";
    sf::Image groundImage;
    if (!groundImage.loadFromFile(groundImageFile))
    {
        //std::cout << " Can not load image " << std::endl;
    }
    //groundImage.createMaskFromColor(sf::Color::Yellow, 255);
    sf::Texture groundTexture;
    groundTexture.loadFromImage(groundImage);
    _groundSprite.setTexture(groundTexture);
}

PlayerPaddle::~PlayerPaddle()
{

}

void PlayerPaddle::Draw(sf::RenderWindow& rw)
{
    VisibleGameObject::Draw(rw);
    //_groundSprite.setOrigin(400.0f, 10.f);
    //_groundSprite.setPosition(BodyIterator->GetPosition().x * Game::WORLD_SCLAE, BodyIterator->GetPosition().y * Game::WORLD_SCLAE);
    _groundSprite.setPosition(0, 500);
    //_groundSprite.setTextureRect(sf::IntRect(0, 0, static_cast<int> (Game::SCREEN_WIDTH), 50));
    //rw.draw(_groundSprite);
    return;

    // Draw the ground
    for (b2Body* BodyIterator = Game::getWorld()->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
    {
        if (BodyIterator->GetType() == b2_dynamicBody)
        {

        }
        else
        {
            //std::cout << " Got a Ground... " << std::endl;
            // Static Ground like Body
            _groundSprite.setOrigin(400.0f, 10.f);
            _groundSprite.setPosition(BodyIterator->GetPosition().x * Game::WORLD_SCLAE, BodyIterator->GetPosition().y * Game::WORLD_SCLAE);
            _groundSprite.setTextureRect(sf::IntRect(0, 0, static_cast<int> (Game::SCREEN_WIDTH), 20));
            //GroundSprite.setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);
            //GroundSprite.SetRotation(180 / b2_pi * BodyIterator->GetAngle());            
            //rw.draw(_groundSprite);
        }
    } // end of world body drawing
}

float PlayerPaddle::GetVelocity() const
{
    return _velocity;
}

void PlayerPaddle::Update(const sf::Event& e, float elapsedTime)
{
    if (e.type == sf::Event::KeyReleased)
    {
        if (e.key.code == sf::Keyboard::D)
            _x += 1.0f;
        if (e.key.code == sf::Keyboard::A)
            _x -= 1.0f;
    }

    if (_velocity > _maxVelocity)
        _velocity = _maxVelocity;

    if (_velocity < -_maxVelocity)
        _velocity = -_maxVelocity;


    sf::Vector2f pos = this->GetPosition();

    GetSprite().setPosition(_x, _y);
}

void PlayerPaddle::createGround()
{
    
}




