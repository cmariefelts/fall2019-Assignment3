#include <iostream>
#include "GenStack.h"
#include "Delimeter.h"


using namespace std;

class SyntaxChecker
{
public:
  //CONSTRUCTOR
  SyntaxChecker(string fileName);
  //DESTRUCTOR
  ~SyntaxChecker();

  //Taking in the file of the user fileName
  void readFile(string fileName);
  //Checks if the delimeters have pairs in the file
  void checkDeliPair();
  void isThereUnmatched();

  //Delimeter Stack
  GenStack<Delimeter*> deliStack;
  //Line count variable
  int countLines;
  //File the user gives us
  string fileName;
};
