#ifndef Bird_hpp
#define Bird_hpp

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Bird : public sf::Sprite {
    sf::Vector2f vel;
    sf::Sprite sprite;
    sf::Texture texture;
    
    void initTexture();
    void initSprite();
    
    template <typename T>
    void centreObject(T& object);
    
public:
    sf::CircleShape spriteBounds;
    
    Bird() {}
    void initBird();
    void update();
    void jump();
    void render(sf::RenderTarget& target);
};

#endif
