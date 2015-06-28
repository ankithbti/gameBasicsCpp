#include <SplashScreen.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Color.hpp>

void SplashScreen::show(sf::RenderWindow& window)
{
    sf::Image image;
    std::string imageFile = "/Users/ankithbti/Development/gameBasics/bin/pang.png";
    if (!image.loadFromFile(imageFile))
    {
        return;
    }
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite(texture);
    
    window.clear(sf::Color::Green);
    window.draw(sprite);
    window.display();

    sf::Event e;
    while (true)
    {
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed ||
                    e.type == sf::Event::MouseButtonPressed ||
                    e.type == sf::Event::KeyPressed)
            {
                return;
            }
        }
    }
}

