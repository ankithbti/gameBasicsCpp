#include <ScoreText.hpp>
#include <iostream>
#include <sstream>

#include "Game.hpp"

ScoreText::ScoreText(Box* box) : _box(box)
{
    if(!_font.loadFromFile("/Users/ankithbti/Development/Quand_tu_dors_.otf")){
        std::cout << " Failed to load Font.  " << std::endl;
    }
    _text.setFont(_font);
    _text.setCharacterSize(25);
    _text.setStyle(sf::Text::Bold);
    _text.setColor(sf::Color::White);
    _text.setPosition(Game::SCREEN_WIDTH - 100, 10);
}

ScoreText::~ScoreText()
{

}

void ScoreText::Update(const sf::Event& e, float elapsedTime)
{
    std::stringstream t;
    t << "Score: " << _box->getBoxCount();
    _text.setString(t.str());
}

void ScoreText::Draw(sf::RenderWindow& window)
{
    window.draw(_text);
}


