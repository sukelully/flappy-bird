#include "Bird.hpp"

// Initialise and centre sprite, set scale and position.
void Bird::initBird() {
    // Set up sprite.
    initSprite();
    this->setPosition(400, 100);
    this->setScale(sf::Vector2f(0.07f, 0.07f));
    sf::FloatRect birdRect = this->getLocalBounds();
    this->setOrigin(birdRect.left + birdRect.width/2.0f,
                    birdRect.top + birdRect.height/2.0f);
    
    // Set up sprite bounds.
//    spriteBounds.setFillColor(sf::Color::White);
    spriteBounds.setRadius(16);
    spriteBounds.setPosition(400, 100);
    sf::FloatRect boundsRect = spriteBounds.getLocalBounds();
    spriteBounds.setOrigin(boundsRect.left + boundsRect.width/2.0f,
                           boundsRect.top + boundsRect.height/2.0f);

}

// Update bird position. Move bird down to simulate gravity.
void Bird::update() {
    this->move(vel);
    spriteBounds.move(vel);
    
    // Set rotation to correlate with position y-axis.
    float rotation = 0.2 * this->getPosition().y - 70;
    this->setRotation(rotation);
    
    // Constant downward acceleration to simulate gravity.
    vel.y += 1;
    
    // Caps gravity at 10.
    if (vel.y >= 10) {
        vel.y = 10;
    }
}

// Bird jumps a small distance vertically up when spacebar is pressed.
void Bird::jump() {
    vel.y = -13;
}

// Load texture file and assign to sprite.
void Bird::initSprite() {
    if (!texture.loadFromFile("media/bird.png")) {
        std::cerr << "ERROR: Bird::initTexture() - Could not load texture file." << std::endl;
    }
    
    this->setTexture(texture);
}

// Helpful render function I may need another time.
void Bird::render(sf::RenderTarget& target) {
    target.draw(sprite);
}


