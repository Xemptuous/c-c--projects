#include <iostream>
#include <string>
using namespace std;

int calculatorMath(int a, char op, int b) 
{
  int result{};
  if (op == '+')
  {
    return a + b;
  }
  else if (op == '-')
  {
    return a - b;
  }
  else if (op == '*')
  {
    return a * b;
  }
  else 
  {
    return a / b;
  }
}


void runCalculator() 
{
  calculator_start:
    int a{},b{},result{};
    char op{};
    cout << "Enter the first number: ";
    try 
    {
      cin >> a;
    } catch (exception) {
      cout << "Invalid number. Try again.\n";
      goto calculator_start;
    }

    cout << "Enter the operator: ";
    try 
    {
      cin >> op;
    } catch (exception) {
      cout << "Invalid operator. Try again.\n";
      goto calculator_start;
    }

    cout << "Enter the second number: ";
    try 
    {
      cin >> b;
    } catch (exception) {
      cout << "Invalid number. Try again.\n";
      goto calculator_start;
    }

    if (op == '+' || op == '-' || op == '*' || op == '/') 
    {
      result = calculatorMath(a, op, b);
    }
    else 
    {
      cout << "Invalid operators. Try again.\n";
      goto calculator_start;
    }
    
    cout << result;
}


void mainMenu() 
{
  menu_start:
    system("clear");
    cout << "Welcome to the Main Menu!\n\nFrom here, you can select any of the optons below to go to the specified program.\n";
    cout << "To navigate through the different apps, type the name in the (parenthesis).\nTo return to the main menu, type \"menu\" at any time.\ntype help for more info." << endl;
    cout << "->Calculator (calc)\n->Tic-Tac-Toe (tictac)\n->Other Options (TODO)\n\n";
    while (true) 
    {
      string selection{};
      cin >> selection;
      if (selection == "help") 
      {
        //run help
      }
      else if (selection == "calc") 
      {
        runCalculator();
        goto menu_start;
      }
      else if (selection == "tictac") 
      {
        //run tic-tac-toe
      }
      else 
      {
        "Invalid Selection. Type \"help\" for more info.\n\n";
      }
    }
}
