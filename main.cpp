#include <iostream>
#include "SyntaxChecker.h"

using namespace std;

//Main Method
int main(int argc, char **argv)
{
  //Set bool to true so it keeps running unless user wants to quit
  bool keepRunning = true;
  string fileName;
  fileName = argv[1];

  while (keepRunning)
  {
    try
    {
        SyntaxChecker* synt = new SyntaxChecker(fileName);
    }
    catch (runtime_error e)
    {
      cout << e.what() << endl;
    }

    //Where the user inputs what they want to do
    string enterFile;
    cout << "Do you want to enter another file? 'Yes or No': " << endl;
    cin >> enterFile;

    if (enterFile == "no" || enterFile == "No")
    {
      cout << "Exiting now!" << endl;
      keepRunning = false;
    }
    else if (enterFile == "yes" || enterFile == "Yes")
    {
      cout << "Enter the name of the file to be checked! " << endl;
      cin >> fileName;
    }
    else
    {
      cout << "Goodbye." << endl;
      keepRunning = false;
    }
  }
}
