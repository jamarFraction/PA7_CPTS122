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

    //IsEmpty
    bool isEmpty();

    //Push
    void Push(StackNode &passedData);

	//Pop 
	StackNode*& Pop();
};