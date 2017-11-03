#include "AbsenceStack.h"


AbsenceStack::AbsenceStack(StackNode *passedTop){

    sTop = passedTop;

}

bool AbsenceStack::isEmpty(){

    //if the pointer to data head is a null ptr
    if(this->sTop == nullptr){

        //the stack is empty
        return true;

    }

    //the stack is not empty
    return false;

}

void AbsenceStack::Push(StackNode *&passedData){

    //Create a pointer to a Stacknode and point it to the the top of the stack
    StackNode *temp = sTop;
    

    //Pushing into an empty stack
    if(temp == nullptr){

        sTop = passedData;

    }else{

        //Pushing into a non-empty stack

        //set the old top's next pointer to the passedData
        

        //set the top of the stack to the passedData
        sTop = passedData;

    }

}

StackNode*& AbsenceStack::Pop() {

	//check to see if the stack is empty
	if (this->isEmpty()) {

		//return a nullptr becuase the stack is empty
		return nullptr;

	}

	//the stack is not empty

	//create a StackNode pointer and point it to the current sTop
	StackNode *headNode = this->sTop;

	//point the new sTop to the current sTop's next node
	sTop = sTop->GetNextNode();

	//return the head node
	return headNode;
}