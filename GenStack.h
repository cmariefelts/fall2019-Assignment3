#include <iostream>

using namespace std;


template <class T>
class GenStack
{
public:

  //Constructor
  GenStack()
  {
    theArray = new T[50];
    size = 50;
    top = -1;
  }

  //Overloaded Constructor
  GenStack(int maxSize)
  {
    if (maxSize < 1)
    {
      throw runtime_error("The max size can't be less than 1.");
    }
    theArray = new T[maxSize];
    size = maxSize;
    top = -1;
  }

  //Destructor
  ~GenStack()
  {

  }


  void push(T d)
  {
    //Check error/boundary check
    if (!isFull())
        theArray[++top] = d;
    else
    {
      cout << "We resized the array. Size = " << size << "Top = " << top << endl;
      sizeArray();

      push(d);
    }
  }

  T pop()
  {
    //Returns and removes
    //Error check if it's isEmpty
    if (isEmpty())
      throw runtime_error("Your stack is empty, so we cannot pop it!");
    return theArray[top--];
  }

  T peek()
  {
    //Check if array is empty
    if (isEmpty())
      throw runtime_error("Your stack is empty, so we cannot peek it!");
    else
      return theArray[top];
  }

  //Checking if the array is full
  bool isFull()
  {
    return (top == size - 1);
  }

  //Checking if the array is empty
  bool isEmpty()
  {
    return (top == -1);
  }

  //Making a size variable
  int size;
  //Making a top variable
  int top;

  //Pointer to theArray
  T *theArray;

private:
  //Sizing our array
  void sizeArray()
  {
    T* tArray = new T[size * 2];

    for (int i = 0; i < size; ++i)
    {
      tArray[i] = theArray[i];
    }

    delete[] theArray;
    theArray = tArray;

    //Updating the size of array
    size = size * 2;
  }
};

//TEMPLATE
//Used for generic types, allows us to use different types, parameters, etc...
// template <class T>

//CONSTRUCTOR
// GenStack::GenStack()
// {
//   theArray = new T[];
//   size = ;
//   top = ;
// }

//OVERLOADED CONSTRUCTOR
// template <class T>
// GenStack<T>::GenStack(int maxSize)
// {
//   theArray = new T[maxSize];
//   size = maxSize;
//   top = -1;
// }

// template <class T>
// GenStack<T>::~GenStack()
// {
//   //Figure this out
// }

// template <class T>
// void GenStack<T>::push(T d)
// {
//   //Check error/boundary check
//   //Figure it out
//   theArray[++top] = d;
// }

// template <class T>
// GenStack<T>::pop()
// {
//   //Returns and removes
//   //Error check if it's isEmpty
//   return theArray[top--];
// }

// template <class T>
// GenStack<T>::peek()
// {
//   return theArray[top];
// }
//
// template <class T>
// bool GenStack<T>::isFull()
// {
//
// }
