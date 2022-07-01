// #include <iostream>
#include "Game.h"
using namespace std;


Game::Game()
{
  choice = 'a';
  playing = true;
  inTitle = true;
}

Game::~Game()
{

}

//Functions
void Game::initGame()
{
  string name;
  cout << "Enter Character name: ";
  getline(cin, name);

  character.initialize(name);
}


void Game::titleMenu()
{
  //removed for debugging purposes; add in later.
  // system("clear");
  cout << "This is the main title screen.\n";
  cout << "This is where you make your initial choices\n\n";
  cout << "[N] Start a New Game" << endl;
  cout << "[C] Continue Saved Game" << endl;
  cout << "[S] Game Settings" << endl;
  cout << "[H] Help Guide" << endl;
  cout << "[Q] Quit Game" << endl;
  cin.get(choice);
  cin.ignore(1000, '\n');

  switch (choice)
  {
    case 'N':
      inTitle = false;
      system("clear");
      break;
    case 'C':
      system("clear");
      cout << "This would continue game" << endl;
      break;
    case 'S':
      settingsMenu();
      break;
    case 'H':
      helpMenu();
      break;
    case 'Q':
      playing = false;
      inTitle = false;
      system("clear");
      break;
    default:
      break;
  }
}


void Game::settingsMenu()
{
  system("clear");
  cout << "This is the Settings Menu!\n" << endl;
  cout << "From here, you can edit different aspects of the game\n"; 
  cin.ignore(1000, '\n');
  system("clear");
}


void Game::helpMenu()
{
  system("clear");
  cout << "This is where you can get the help you need" << endl;
  cout << "That is, if there was help to get!\n";
  cin.ignore(1000, '\n');
  system("clear");
}


void Game::mainMenu()
{
  cout << "You are in the Lanlior City Main Square." << endl;
  cout << "You are curious as to what to do next.\n" << endl;
  cout << "[T] Travel" << endl;
  cout << "[S] Shop" << endl;
  cout << "[L] Level Up" << endl;
  cout << "[C] Character Sheet" << endl;
  cout << "[R] Rest" << endl;
  cout << "[Q] Quit to Main Menu" << endl;
  cout << endl;
  cin.get(choice);
  cin.ignore(1000, '\n');

  switch (choice)
  {
    case 'Q':
      inTitle = true;
      system("clear");
      break;
    case 'T':
      travelMenu();
      break;
    case 'S':
      shopMenu();
      break;
    case 'L':
      levelUpMenu();
      break;
    case 'R':
      restMenu();
      break;
    case 'C':
      characterSheetMenu();
      break;
    default:
      break;
  }
}

void Game::travelMenu()
{
  system("clear");
  cout << "This is the Travel Menu!\n" << endl;
  cout << "Please choose a location to travel to:" << endl;
  cout << "[O] Outside Town\t[W] Woods\t[D] Desert\t[M] Mountain\n\n";

  cin.ignore(1000, '\n');
  system("clear");
}

void Game::shopMenu()
{
  system("clear");
  cout << "This is the Shop!\n" << endl;
  cout << "Choose an item:" << endl;
  cout << "[W] Wooden Stick\t[B] Bronze Sword\t[M]Mail Armor\t[S] Steel Helmet\n";
  cin.ignore(1000, '\n');
  system("clear");
}


void Game::characterSheetMenu()
{
  character.printCharacterStats();
  cout << "Press any key to return." << endl;
  cin.ignore(1000, '\n');
  system("clear");
}


void Game::levelUpMenu()
{
  system("clear");
  cout << "This is the Level Up Menu!\n" << endl;
  cout << "Choose a stat to level:";
  cout << "[S]Strength\t[D]Dexterity\t[C]Constitution\n";
  cin.ignore(1000, '\n');
  system("clear");
}

void Game::restMenu()
{
  system("clear");
  cout << "This is the Rest Menu!\n" << endl;
  cout << "Are you sure you want to rest? [Y] [N]\n";
  cin.ignore(1000, '\n');
  system("clear");
}