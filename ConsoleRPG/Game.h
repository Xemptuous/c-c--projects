#pragma once

#include "Character.h"
#include <ctime>

using namespace std;

class Game
{
public:
  Game();
  virtual ~Game();
  //Operators

  //Functions
  void initGame();
  void titleMenu();
  void settingsMenu();
  void helpMenu();

  void mainMenu();
  void travelMenu();
  void shopMenu();
  void characterSheetMenu();
  void levelUpMenu();
  void restMenu();

  //Accessors
  inline bool getPlaying() const { return this->playing; }
  inline bool getInTitle() const { return this->inTitle; }

  //Modifiers

  //Character
  Character character;

private:
  char choice;
  bool playing;
  bool inTitle;
};