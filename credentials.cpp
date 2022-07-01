#include <iostream>
#include <fstream>
#include <filesystem>
// #include <conio.h>
#include <termios.h>
#include <unistd.h>
#include <string>
#include <regex>
using namespace std;

// Windows implementation; currently not needed.
// string takePasswordFromUser() {
  // string iptt = "";
  // chat ipt_ch;
  // while (true) {
    // ipt_ch = getch();
    // if (ipt_ch < 32) {
      // cout << endl;
      // return ipt;
    // }
    // ipt.push_back(ipt_ch)
  // }
// }


void userRegister() 
{
  cout << "Welcome to the Registration process!\n\n";
  string uname{}, upass{};
  cout << "Please enter your desired username.\n";
  username_start:
    uname = "";
    while (true) 
    {
      cout << "Your username should be between between 4 and 32 characters and \ncannot contain any special characters (aside from \"_\"): \n\n";
      cout << "username: ";
      cin >> uname;
      system("clear");
      
      if (uname.length() > 3 && uname.length() < 33 && regex_match(uname,regex("[A-Za-z0-9_]+"))) 
      {
        ifstream usernameCredCheck;
        usernameCredCheck.open ("user_credentials.txt");
        if (usernameCredCheck.is_open()) 
        {
          map<string, string> readUserCreds;
          for (string name; getline(usernameCredCheck, name, ':'); usernameCredCheck.get()) 
          {
            string pass;
            usernameCredCheck >> pass;
            readUserCreds[name] = pass;
            for (const auto& [name, value] : readUserCreds) {
              if (name == uname) 
              {
                cout << "Username already taken. Please choose another username.\n\n";
                usernameCredCheck.close();
                goto username_start;
              }
            }
          }
        }
        usernameCredCheck.close();

        username_check:
          char confirm{};
          cout << "You entered: " + uname << endl;
          cout << "Are you sure you would like this username? (type [Y] to confirm or [N] to choose another username.):\n";

          while (true) 
          {
            cin >> confirm;
            if (confirm == 'Y' || confirm == 'y') 
            {
              goto username_end;
            }
            else if (confirm == 'N' || confirm == 'n') 
            {
              cout << "\n";
              goto username_start;
            }
            else 
            {
              cout << "Invalid Input. (type [Y] to confirm or [N] to choose another username.):\n";
            } 
          }
      }
      else 
      {
        cout << "Invalid username." << endl << endl;
      }
    }
  username_end:
  system("clear");

  cout << "Hello " + uname + "!\n\nStep 1 complete! Now on to step 2.\n\n";
  cout << "Please choose a password to secure your account.\nPasswords should be between 6 and 32 characters\nand can include any characters (including special ones):\n" << endl;

  while (true) 
  {
    string upass_conf{};
    password_start:
      cout << "password: ";
      
      termios oldt;
      tcgetattr(STDIN_FILENO, &oldt);
      termios newt = oldt;
      newt.c_lflag &= ~ECHO;
      tcsetattr(STDIN_FILENO, TCSANOW, &newt);
      
      cin >> upass;

      if (upass.length() > 5 && upass.length() < 33) 
      {
        system("clear");
        cout << "Please re-type password to confirm: ";
        cin >> upass_conf;
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        if (upass_conf == upass) 
        {
          break;
        }
        else 
        {
          cout << "Passwords did not match. Please try again." << endl;
        }
      }
      else 
      {
        cout << "Password was not of the specified length. Please try again.\n\n";
      }
  }
  fstream userCredentials;
  userCredentials.open ("user_credentials.txt", ios::app);
  //TODO: encrypt and decrypt user information.
  userCredentials << uname + ":" + upass << endl;
  userCredentials.close();

  system("clear");

  cout << "Congratulations " + uname + "! You have now created an account!\n\n";
  cout << "Now time to login with your new credentials!\n" << endl;
}

void userLogin() 
{
  login_start:
    string uname{}, upass{};

    cout << "Please enter your login info below, or type \"register\" to create a new account:\n";
    cout << "username: ";
    cin >> uname;
    cout << "password: ";
    cin >> upass;

    system("clear");
    if (uname == "register" || upass == "register") 
    {
      userRegister();
      goto login_start; 
    }

    ifstream usernameCredCheck;
    usernameCredCheck.open ("user_credentials.txt");
    if (usernameCredCheck.is_open()) 
    {
      map<string, string> readUserCreds;

      for (string name; getline(usernameCredCheck, name, ':'); usernameCredCheck.get()) 
      {
        string pass;
        usernameCredCheck >> pass;
        readUserCreds[name] = pass;
        for (const auto& [name, value] : readUserCreds) 
        {
          if (name == uname && pass == upass) {
            system("clear");
            cout << "Login Success!\n\n";
            return void();
          }
        }
      }
      system("clear");
      cout << "Incorrect login Username / Password combination.\n\n";
      goto login_start;
    }
    else 
    {
      cout << "No registration file found." << endl << endl;;
      userRegister();
      userLogin();
    }
}
