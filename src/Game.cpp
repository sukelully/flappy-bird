#include "Game.hpp"

/*
 To do:
 - Randomise wall hole size.
 - Displays top scores ever at end?
 - Clean up / comment.
 - Add sprites, spruce up color scheme.
 - Refactor wall.top and wall.bottom to be one entity.
 */

// Constructor. Initalise variables and start message.
Game::Game() {
    isOver = false;
    wallCounter = 0;
    gameStarted = false;
    wallSpeed = -2.0f;
    initialise();
}

// Deconstructor.
Game::~Game() {
//    delete window;
}

// Initialise game window, load font and set up start message and score text.
void Game::initialise() {
    // Initialise game window and set frame rate.
    window.create(sf::VideoMode(win_width, win_height), "Flappy Bird", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    
    // Handle font loading error.
    if (!font.loadFromFile("media/font.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }
    
    // Initialise start message text.
    startMessage.setFont(font);
    startMessage.setFillColor(sf::Color::White);
    startMessage.setString("Press spacebar to play!");
    startMessage.setCharacterSize(40);
    startMessage.setPosition(win_width/2, win_height/2);
    centreText(startMessage);
    
    // Initialise start message background tile.
    startTile.setPosition(win_width/8, win_height/6);
    startTile.setSize(sf::Vector2f(win_width*0.75, win_height/1.5));
    startTile.setFillColor(sf::Color(66, 135, 245));
    
    // Initialise score text.
    score.setFont(font);
    score.setFillColor(sf::Color::White);
    score.setString("0");
    score.setCharacterSize(50);
    score.setPosition(win_width/2, win_height/15);
    centreText(score);
}

// Listen for and handle events - close window with escape key, control bird with spacebar.
void Game::handleEvents() {
    sf::Event event;
    // While there are pending events...
    while (window.pollEvent(event)) {
        // Check the type of event...
        switch (event.type) {
            // Window closed.
            case sf::Event::Closed:
                window.close();
                break;
            // Key is pressed.
            case sf::Event::KeyPressed:
                // Close window if escape key is pressed.
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                else if (event.key.code == sf::Keyboard::Space) {
                    // Start game on initial spacebar press.
                    if (!gameStarted)
                        startGame();
                    // Subsequent presses control the bird.
                    else
                        bird.jump();
                }
            // Ignore other events.
            default:
                break;
        }
    }
}

// Start game, initialise game objects and remove start message.
void Game::startGame() {
    gameStarted = true;
    bird.initBird();
    this->createWall();
    startTile.setFillColor(sf::Color::Transparent);
    startMessage.setFillColor(sf::Color::Transparent);
}

// Handle events and controls, update and render game objects.
void Game::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

// Update bird and wall positions while the game is playing.
void Game::update() {
    if (!isOver) {
        updateBird();
        updateWalls();
    }
}

// Update bird position. End game if bird falls out of frame.
void Game::updateBird() {
    if (gameStarted) {
        if (bird.getPosition().y > window.getSize().y) {
            gameOver();
        }
        bird.update();
    }
}

// Move and gradually speed up walls, create new walls and delete old ones, and detect collisions with bird.
void Game::updateWalls() {
    for (int i = 0; i < walls.size(); i++) {
        // Create a new wall when previous reaches x = 460.
        if (walls[wallCounter].top.getPosition().x < 390) {
            createWall();
            wallCounter++;
            score.setString(std::to_string(wallCounter));
            centreText(score);
//            score.setPosition(400, 40);
        }
        
        // Detect collisions with bird.
        collision(bird, walls[i].top, walls[i].bottom);
        
        // Move walls right to left.
        walls[i].top.move(wallSpeed, 0.0f);
        walls[i].bottom.move(wallSpeed, 0.0f);
        
        // Delete walls from memory when they leave the frame.
        if (walls[i].top.getPosition().x > window.getSize().x) {
            walls.erase(walls.begin() + i);
        }
    }
    // Gradually increase wall speed.
    wallSpeed -= 0.001;
}

// Render game objects.
void Game::render() {
    window.clear(sf::Color(105, 161, 250));
    window.draw(startTile);
    window.draw(startMessage);
    
    window.draw(bird);
    for (auto &w : walls) {
        window.draw(w.top);
        window.draw(w.bottom);
    }
    
    window.draw(score);
    window.display();
}

// Create a wall section and add it to the walls vector.
void Game::createWall() {
    wall.initWall();
    this->walls.push_back(this->wall);
}

// Centre text position.
void Game::centreText(sf::Text &text) {
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
}

// Detect collisions between bird and walls and end game when collision occurs.
void Game::collision(sf::CircleShape bird, sf::RectangleShape top, sf::RectangleShape bottom) {
    if (bird.getGlobalBounds().intersects(top.getGlobalBounds()) ||
        bird.getGlobalBounds().intersects(bottom.getGlobalBounds())) {
        gameOver();
    }
}

// Set boolean variable to true to stop game from updating.
void Game::gameOver() {
    std::cout << "You're out!" << std::endl;
    isOver = true;
}
