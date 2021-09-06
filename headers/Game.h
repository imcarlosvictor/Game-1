#pragma once
/*
 * <What the program does>
*/

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window/VideoMode.hpp>

class Game
{
  private:
    // Members
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    // Methods
    void initVariables();
    void initWindow();

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
