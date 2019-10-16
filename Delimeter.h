#include <iostream>

using namespace std;

class Delimeter
{
public:
  Delimeter(int countLines, char delimeter);
  ~Delimeter();

  //Method definitions
  void isItMatch();
  void checkDeliPair();

  //Variable declarations
  char delimeter;
  int countLines;
  char deliMatch;
  bool hasPair;
};
