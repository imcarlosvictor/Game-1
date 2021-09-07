#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window/VideoMode.hpp>

/*
 * <What the program does>
*/

class Game
{
  private:
    // Members
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    // Game objects
    sf::RectangleShape enemy;

    // Methods
    void initVariables();
    void initWindow();
    void initEnemies();

  public:
    // Constructors / Destructors
    Game();
    virtual ~Game();

    // Accessors
    const bool running() const;

    // Methods
    void pollEvents();
    void update();
    void render();
};
