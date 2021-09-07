#include <SFML/Window/Keyboard.hpp>
#include "headers/Game.h"

///////////////////////////////////////////
// Private Methods
///////////////////////////////////////////
void Game::initVariables()
{
  this->window = nullptr;
}

void Game::initWindow()
{
  this->videoMode.height = 600;
  this->videoMode.width = 800;
  this->window = new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close);
  
  // Set frame rate
  this->window->setFramerateLimit(60);
}

void Game::initEnemies()
{
  this->enemy.setPosition(10.f, 10.f);
  this->enemy.setSize(sf::Vector2f(100.f, 100.f));
  this->enemy.setFillColor(sf::Color::Cyan);
  this->enemy.setOutlineColor(sf::Color::Green);
  this->enemy.setOutlineThickness(1.f);
}

///////////////////////////////////////////
// Constructors /Destructors
///////////////////////////////////////////
Game::Game()
{
  this->initVariables();
  this->initWindow();
  this->initEnemies();
}

Game::~Game()
{
  delete this->window;
}

///////////////////////////////////////////
// Accessors
///////////////////////////////////////////
const bool Game::running() const
{
  // Access window object and check if the window is open
  return this->window->isOpen();
}

///////////////////////////////////////////
// Methods
///////////////////////////////////////////
void Game::pollEvents()
{
  // Event polling
  while (this->window->pollEvent(this->ev))
  {
    switch (this->ev.type)
    {
      case sf::Event::Closed:
        {
          this->window->close();
          break;
        }
      case sf::Event::KeyPressed:
        {
          if (this->ev.key.code == sf::Keyboard::Escape)
            this->window->close();
          break;
        }
    }
  }
}
void Game::update()
{
  this->pollEvents();
}

void Game::render()
{
  /*
   *  Renders the game objects.
   *  - clear old frame
   *  - render objects
   *  - display frame in window
   *
   *  @return void
   */
  this->window->clear();

  // Draw game objects
  this->window->draw(this->enemy);
  this->window->display();
}
