/*******************************************************************************************
* Programmer: Jamar Fraction                                                               *
* Class: CptS 122, Fall  2017; Lab Section 05											   *
* Programming Assignment: PA7															   *
* Date: November 8, 2017                                                                   *
* Description: This program fulfills the requirements for the seventh programming assignment*
********************************************************************************************/
#include <stdbool.h>
#include <iostream>
#include "StackNode.h"

class AbsenceStack{

private:

    //Pointer to the top of the stack
    StackNode *sTop;


public:

    //Default constructor
    AbsenceStack(StackNode *passedTop = nullptr);

	StackNode*& GetTop();

    //IsEmpty
    bool isEmpty();

    //Push
    void Push(StackNode *&passedData);

	//Pop 
	StackNode*& Pop();

	//Peek
	StackNode* Peek();
};