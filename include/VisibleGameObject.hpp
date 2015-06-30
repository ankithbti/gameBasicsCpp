    /* 
 * File:   VisibleGameObject.hpp
 * Author: ankithbti
 *
 * Created on 29 June, 2015, 12:19 AM
 */

#ifndef VISIBLEGAMEOBJECT_HPP
#define	VISIBLEGAMEOBJECT_HPP


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class VisibleGameObject {
private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Image _image;
    std::string _filename;
protected:
    bool _isLoaded;
protected:
  sf::Sprite& GetSprite();
public:
    VisibleGameObject();
    virtual ~VisibleGameObject();
    virtual void Load(std::string filename, const sf::IntRect& rec = sf::IntRect());
    virtual void Draw(sf::RenderWindow & window);
    virtual void SetPosition(float x, float y);
    virtual void Update(const sf::Event& e, float elapsedTime);
    virtual sf::Vector2f GetPosition() const;
    virtual bool IsLoaded() const;

};

#endif	/* VISIBLEGAMEOBJECT_HPP */

