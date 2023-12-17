// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring> 

int main()
{
  std::cout << "Buffer Overflow Example" << std::endl;

  //  The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
  //  even though it is a constant and the compiler buffer overflow checks are on.
  //  You need to modify this method to prevent buffer overflow without changing the account_order
  //  varaible, and its position in the declaration. It must always be directly before the variable used for input.

  const std::string account_number = "CharlieBrown42";
  char user_input[20];
  std::cout << "Enter a value: ";

  // bool var to keep asking user for input, when the entered input > 20 char
  bool char20LimitNotMet = true;

  // str1 is used to count the number of characters (user_input)
  std::string str1;

  // variable to close program if user fails 5 times
  int userInputFailedAttempts = 0;

  // while loop is executed in the first run (even before user enters any input)
  // and it will run until the user input is less than 21 char or user fails 5 times 
  while (char20LimitNotMet)
  {
    // reads user input using std::getline to handle spaces and newlines
    std::getline(std::cin, str1);  // Use std::getline for input
    
  
    // find the number of char in user's input
    int charCount = str1.size();

    // if user's input characters are more than 20, it asks user to try again
    if ( charCount > 20)
    {
      std::cout << "Please enter a value with 20 characters OR less (*** current value's char count: " << charCount << " ***): ";

      // counts number of failed attempts to prevent indefinite loop
      userInputFailedAttempts = userInputFailedAttempts + 1;

      // terminates the program after 5 failed attempts
      if (userInputFailedAttempts == 5)
      {
        std::cout << "\n\n\t\t*** Too many failed attempts! the program is closing now. ***\n\n";
        return 0;
      }
      
    }
    if ( charCount < 21) 
    {
      // exits while loop if the number of char in user's input is 20 or less
      char20LimitNotMet = false;
      const int length = str1.length(); 
  
    // copying the contents of the string to USER_INPUT CHAR
    strcpy(user_input, str1.c_str()); 

    std::cout << "\nYou entered: " << user_input << "\n\t*** Char Lenght: " << length << " ***" << std::endl;
    // for (int i = 0; i < length; i++) 
    // { 
    //     std::cout << user_input[i]; 
    // } 
    }
  }
  
  // displays user's input and account number, only if the number of char in user's input is 20 or less
  std::cout << "Account Number = " << account_number << std::endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
