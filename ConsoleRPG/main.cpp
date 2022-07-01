#include "Game.h"

int main()
{
  system("clear");

  Game game;
  game.initGame();

  Inventory inv;
  
  while (game.getPlaying())
  {
    while (game.getInTitle())
    {
      game.titleMenu();
      if (!(game.getPlaying()))
        goto end;
    }
    game.mainMenu();
  }
  end:
  return 0;
}
