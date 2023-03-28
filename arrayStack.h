// ---------------------------------------------------------------------------
// Name: Christelle Mbemba
// Course-Section: CS255-01
// Assignment: Project #7
// Date due: 24/03/2023
// Description: The program is a html validor, is supposed to accepte a txt file and
//				add analyse it, and found if it respect the the html standard
// ---------------------------------------------------------------------------
#include <iostream>
using namespace std;

template <typename Type>
class arrayStack
{
private:
    int maxStackSize; //variable to store the maximum stack size
    int stackTop;     //variable to point to the top of the stack
    Type *list;       //pointer to the array that holds the
                      //stack elements

    void copyStack(const arrayStack<Type>& otherStack)
      //Function to make a copy of otherStack.
      //Postcondition: A copy of otherStack is created and
      //               assigned to this stack.
    {
        delete [] list;
        maxStackSize = otherStack.maxStackSize;
        stackTop = otherStack.stackTop;

        list = new Type[maxStackSize];

        //copy otherStack into this stack
        for (int j = 0; j < stackTop; j++)
            list[j] = otherStack.list[j];
    }
public:
    arrayStack(int stackSize = 100)
      //constructor
      //Create an array of the size stackSize to hold
      //the stack elements. The default stack size is 100.
      //Postcondition: The variable list contains the base
      //               address of the array, stackTop = 0, and
      //               maxStackSize = stackSize.
    {
        if (stackSize <= 0)
        {
            cout << "Size of the array to hold the stack must "
                << "be positive." << endl;
            cout << "Creating an array of size 100." << endl;

            maxStackSize = 100;
        }
        else
            maxStackSize = stackSize;   //set the stack size to
                                    //the value specified by
                                    //the parameter stackSize

        stackTop = 0;                   //set stackTop to 0
        list = new Type[maxStackSize];  //create the array to
                                    //hold the stack elements
    }//end constructor

    arrayStack(const arrayStack<Type>& otherStack)
      //copy constructor
    {
        list = nullptr;

        copyStack(otherStack);
    }
    const arrayStack<Type>& operator=(const arrayStack<Type>& otherStack)
      //Overload the assignment operator.
    {
        if (this != &otherStack) //avoid self-copy
            copyStack(otherStack);

        return *this;
    }

    void initializeStack()
      //Function to initialize the stack to an empty state.
      //Postcondition: stackTop = 0
    {
        stackTop = 0;
    }//end initializeStack

    bool isEmptyStack()
      //Function to determine whether the stack is empty.
      //Postcondition: Returns true if the stack is empty,
      //               otherwise returns false.
    {
        return (stackTop == 0);
    }//end isEmptyStack

    bool isFullStack()
      //Function to determine whether the stack is full.
      //Postcondition: Returns true if the stack is full,
      //               otherwise returns false.
    {
        return (stackTop == maxStackSize);
    }

    void push(const Type& newItem)
      //Function to add newItem to the stack.
      //Precondition: The stack exists and is not full.
      //Postcondition: The stack is changed and newItem
      //               is added to the top of the stack.
    {
        if (!isFullStack())
        {
            list[stackTop] = newItem;   //add newItem to the
                                    //top of the stack
            stackTop++; //increment stackTop
        }
        else
            cout << "Cannot add to a full stack." << endl;
    }

    Type top()
      //Function to return the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: If the stack is empty, the program
      //               terminates; otherwise, the top element
      //               of the stack is returned.
    {
        return list[stackTop - 1];  //return the element of the
                                //stack indicated by
                                //stackTop - 1
    }

    void pop()
      //Function to remove the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: The stack is changed and the top
      //               element is removed from the stack.
    {
        if (!isEmptyStack())
            stackTop--;      //decrement stackTop
        else
            cout << "Cannot remove from an empty stack." << endl;
    }

  /*  ~arrayStack()
      //destructor
      //Remove all the elements from the stack.
      //Postcondition: The array (list) holding the stack
      //               elements is deleted.
   {
        cout<<"Freeing dynamically allocating memory."<<endl;
        delete [] list; //deallocate the memory occupied
                    //by the array
    }
    */
    
    friend ostream& operator<<(ostream& os, const arrayStack<Type>& stack)
    {
        
        for (int i = stack.stackTop - 1; i >= 0; i--)
        {
            os << stack.list[i] << " ";
        }
    
        return os;
    }    
    
    
};






