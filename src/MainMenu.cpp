#include <MainMenu.hpp>
#include <SFML/Window/Event.hpp>

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{
    sf::Image image;
    std::string imageFile = "/Users/ankithbti/Development/gameBasics/bin/menu.png";
    if (!image.loadFromFile(imageFile))
    {
        //
    }

    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite(texture);


    //Setup clickable regions

    //Play menu item coordinates
    MenuItem playButton;
    playButton._rect.top = 145;
    playButton._rect.height = 380;
    playButton._rect.left = 0;
    playButton._rect.width = 1023;
    playButton._action = Play;

    //Exit menu item coordinates
    MenuItem exitButton;
    exitButton._rect.left = 0;
    exitButton._rect.width = 1023;
    exitButton._rect.top = 383;
    exitButton._rect.height = 560;
    exitButton._action = Exit;

    _menuItems.push_back(playButton);
    _menuItems.push_back(exitButton);

    window.draw(sprite);
    window.display();

    return GetMenuResponse(window);

}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
    sf::Event menuEvent;
    
    while(true){
        while(window.pollEvent(menuEvent)){
            if(menuEvent.type == sf::Event::MouseButtonPressed){
                return HandleClick(menuEvent.mouseButton.x,menuEvent.mouseButton.y);
            }
            if(menuEvent.type == sf::Event::Closed){
                return Exit;
            }
        }
    }
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
    std::list<MenuItem>::iterator it;

    for (it = _menuItems.begin(); it != _menuItems.end(); it++)

    {
        sf::Rect<int> menuItemRect = (*it)._rect;
        if (menuItemRect.height > y
                && menuItemRect.top < y
                && menuItemRect.left < x
                && menuItemRect.width > x)

        {
            return (*it)._action;
        }
    }

    return Nothing;
}

