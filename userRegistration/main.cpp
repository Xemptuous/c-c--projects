#include "headers.h"
#include <iostream>
#include <string>

int main() 
{
  system("clear");
  std::cout << "Hello and welcome to the program!\nIf you are new here, please type \"register\" to create an account.\nOtherwise, type \"login\" to continue with your existing account.\n" << std::endl;

  while (true) 
  {
    std::string welcomeInput{};
    std::cin >> welcomeInput;

    if (welcomeInput == "login") 
    {
      userLogin();
      break;
    }
    else if (welcomeInput == "register") 
    {
      std::cout << "\n";
      userRegister();
      userLogin();
      break;
    }
    else 
    {
      std::cout << welcomeInput + " is not an available command.\nPlease try\"login\" if you have an existing account, or \"register\" to create a new account" << std::endl;
    }
  }
  mainMenu();
  
  std::cout << "Program finished!\n";
  return 0;
}
