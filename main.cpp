#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main ()
{
// Declraing My Variables
  bool my_bool = true;
  int fav;
  int choice;
  string header_message;
  string header;
  string header1;
  string header2;
  string header_end;

// Making my_bool variable false
  my_bool = (5==7);
  cout << "The value is: " << my_bool << endl;

// Asking user for their favorite number
  cout << "Please enter your favorite number: ";
  cin >> fav;

// If the user input is equal to 7, we print this message
  if (fav==7)
  {
    cout << "Hey! Cool number!" << endl;
  }
// If the user input is less than 11, we print this message
  else if (fav<11)
  {
    cout << "Well, at least that's small enough to remember.." << endl;
  }
// If the user input is greater than 11, we print this message
  else
  {
    cout << "Sorry, I can't be bothered to count that high right now.." << endl;
  }

// Combining my statements
  if (fav<11)
  {
    if (fav==7)
    {
      cout << "Hey! Cool number!" << endl;
    }
    cout << "Well, at least that's small enough to remember.." << endl;
  }

// Adding the short-circuit evaluation code
  if (false && true)
  {
    std::cout << "This is output from the Short-Circuit Evaluation part." << std::endl;
  }

// Creating a final menu
  header = "Okay, now what do you want to do?";
  header1 = "1. See your number again";
  header2 = "2. Just quit";
  header_end = "Your choice ==> ";
  header_message.assign(0,' ');
  cout << header_message << endl;
  header_message.assign(0,' ');
  cout << header_message << endl;
  cout << header_message << header << endl;
  header_message.assign(0,' ');
  cout << header_message << endl;
  cout << header_message << header1 << endl;
  cout << header_message << header2 << endl;
  header_message.assign(0,' ');
  cout << header_message << endl;
  cout << header_message << header_end;

// Inputting the user's choice
  cin >> choice;
// If the user chooses option 1, it will repeat their inputted number
  if (choice==1)
  {
    cout << "Your number: " << fav << endl;
  }
// If the user chooses option 2, program will exit
  else if (choice==2)
  {
    cout << "Goodbye!" << endl;
  }
// If use inputs anything other than 1 or 2, invalid message will appear
  else
  {
    cout << "Not valid, try again." << endl;
  }

  return 0;
}
