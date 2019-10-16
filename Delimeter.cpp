#include <iostream>
#include "Delimeter.h"

using namespace std;

//CONSTRUCTOR
Delimeter::Delimeter(int countLines, char delimeter)
{
  this->delimeter = delimeter;
  this->countLines = countLines;
  //Setting bool to false
  hasPair = false;
  //Method that checks for pairs
  checkDeliPair();
}

//DESTRUCTOR
Delimeter::~Delimeter()
{

}


void Delimeter::isItMatch()
{
  this->hasPair = true;
}

//Groups the delimeter and its match together
void Delimeter::checkDeliPair()
{
  if (delimeter == '(')
    deliMatch = ')';
  if (delimeter == ')')
    deliMatch = '(';
  if (delimeter == '[')
    deliMatch = ']';
  if (delimeter == ']')
    deliMatch = '[';
  if (delimeter == '{')
    deliMatch = '}';
  if (delimeter == '}')
    deliMatch = '{';
}
