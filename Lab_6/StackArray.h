//--------------------------------------------------------------------
//
//  Laboratory 6                                         StackLinked.h
// 
//  Class declaration for the linked implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template <typename DataType>
class StackArray : public Stack<DataType> {
public:
    StackArray(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);
    //Function: Default constructor.
    //Creates starting node with empty element pointing to NULL.

    StackArray(const StackArray& other);
    //Function: Copy constructor
    //Creates a copy of the other stack called by the function.

    StackArray& operator=(const StackArray& other);
    //Function: Assignment overload.
    //Copies the contents of one stack to another.

    ~StackArray();
    //Function: Deletion call.
    //Deletes the memory of stacks when they are not needed.

    void push(const DataType& newDataItem) throw (logic_error);
    //Function: Pushes data into stack.
    //Creates a temporary pointer and then assigns top to a new node while attaching it to the temporary pointer. Then deletes the temp pointer.

    DataType pop() throw (logic_error);
    //Function: Pops the top data out.
    //Creates a temporary pointer and temporary dataItem. Assigns top to the next node and deletes the temporary pointer. Returns the data inside the temporary dataItem.

    void clear();
    //Function: Clears and deletes the data items.
    //Delinks the top node in order to delete any references to the previous items.

    bool isEmpty() const;
    //Function: Checks if the stack is empty.
    //Looks to see if the top is pointing to NULL. If it is then returns true. Otherwise it returns false.

    bool isFull() const;
    //Function: Checks if the stack is full.
    //I have put an arbitrary limit of 8 on the stack, and this function checks if there are eight or more nodes.
    //If there are it returns true. If there are not then it returns false.

    void showStructure() const;
    //Creates a structure in order to show the stack as well as to give an image of the stack.
    //Credit for this function goes to the book "C++ Data Structures third edition: A Laboratory Course"

private:
    int maxSize;
    int top;
    DataType* dataItems;
};

#endif		//#ifndef STACKARRAY_H
#pragma once
