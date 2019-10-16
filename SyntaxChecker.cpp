#include <iostream>
#include "SyntaxChecker.h"
#include <fstream>

using namespace std;

//CONSTRUCTOR
SyntaxChecker::SyntaxChecker(string fileName)
{
  countLines = 0;
  this->fileName = fileName;
  //Initializing the stacks
  deliStack = GenStack<Delimeter*>();
  readFile(fileName);

  checkDeliPair();
  isThereUnmatched();

}

//DESTRUCTOR
SyntaxChecker::~SyntaxChecker()
{

}

//Method to read the file the user gave me
void SyntaxChecker::readFile(string fileName)
{
  string line;
  ifstream fiStream;
  fiStream.open(fileName);
  //If we can't open the file, tell the user
  if (!fiStream)
  {
    throw runtime_error("We can't open your file!");
  }

  int countLines = 0;
  char delimeter;
  while (getline(fiStream, line))
  {
    countLines++;
    for (int i = 0; i < line.length(); ++i)
    {
      int firstQuote = -1;
      int secondQuote = -1 ;

      //Checking if the delimeters are in quotes. If they are, don't count them
      if (line[i] == '\"' || line[i] == '\'')
      {
        firstQuote = i;
        for (int x = i + 1; x < line.length();++x)
        {
          if (line[x] == '\"' || line[x] == '\'')
          {
            secondQuote = x;
          }
        }
      }
      //If the index is in between the quotations, continue to look for delimeters!
      if (i >= firstQuote && i <= secondQuote)
      {
        break;
      }
      //Iterating through lines to check if the line has a (,),[,],{, or }
      //If it does, create a pointer of that delimeter and push to stack
      if (line[i] == '(')
      {
        Delimeter* d = new Delimeter(countLines, '(');
        deliStack.push(d);
      }

      else if (line[i] == ')')
      {
        Delimeter* d = new Delimeter(countLines, ')');
        deliStack.push(d);
      }

      else if (line[i] == '[')
      {
        Delimeter* d = new Delimeter(countLines, '[');
        deliStack.push(d);
      }

      else if (line[i] == ']')
      {
        Delimeter* d = new Delimeter(countLines, ']');
        deliStack.push(d);
      }

      else if (line[i] == '{')
      {
        Delimeter* d = new Delimeter(countLines, '{');
        deliStack.push(d);
      }

      else if (line[i] == '}')
      {
        Delimeter* d = new Delimeter(countLines, '}');
        deliStack.push(d);
      }
    }
}
  //Close the user's file!
  fiStream.close();
}

void SyntaxChecker::checkDeliPair()
{
  //Iterate through the stack that holds the delimeters
  for (int i = 0; i <= deliStack.top; ++i)
  {
      //Once you find a pair, the delimeter class knows if it's a pair or not
      //if there's a pair, tell both delimeters that there is a match
      //Grab the object delimeter
      Delimeter* currDelimeter = deliStack.theArray[i];
      if (currDelimeter->hasPair == true)
      {
        continue;
      }
      else if (currDelimeter->delimeter == ']' || currDelimeter->delimeter == ')' || currDelimeter->delimeter == '}')
      {
        continue;
      }
      else
      {


      for (int x = i; x <= deliStack.top; ++x)
      {
        Delimeter* checkDeli = deliStack.theArray[x];

        if (checkDeli->delimeter == checkDeli->deliMatch)
        {
          checkDeli->isItMatch();
          currDelimeter->isItMatch();
          continue;

        }
      }
    }
  }
}

//Method to tell the user whether or not there is an unmatched delimeter
void SyntaxChecker::isThereUnmatched()
{
  for (int i = 0; i <= deliStack.top; ++i)
  {
    //If the delimeter in the stack doesn't have a pair, then:
    if (deliStack.theArray[i] -> hasPair == false)
    {
      //This prints to user where and what is the delimeter that is unmatched
      string error = "Line: " + to_string(deliStack.theArray[i]->countLines) + ", Unmatched Delimeter = " + string(1, deliStack.theArray[i]->delimeter);
      throw runtime_error(error);
    }
  }
  cout << "No unmatched delimeter found! Yay!" << endl;

}
