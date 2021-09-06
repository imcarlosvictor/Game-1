#include <iostream>
#include "headers/Game.h"


int main()
{
  // Window
  Game game;

  // Game Loop
  while (game.running())
  {
    // Update
    game.update();  
  
    // Render
    game.render();
  }


  return 0;
}
