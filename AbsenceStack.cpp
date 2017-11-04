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

StackNode*& AbsenceStack::GetTop() {

	return this->sTop;

}

void AbsenceStack::Push(StackNode *&passedData) {

	if(this->isEmpty()) {

		sTop = passedData;

	}
	else {

		//Create a pointer to a Stacknode and point it to the the top of the stack
		StackNode *temp = sTop;

		//set the top of the stack to the passedData
		sTop = passedData;

		//set the current sTop's next Node to the temp pointer (the Node that used to be the head Node)
		sTop->SetNextNode(temp);

	}

}

StackNode*& AbsenceStack::Pop() {

	//create a StackNode pointer and point it to the current sTop
	static StackNode *headNode = this->sTop;

	//point the new sTop to the current sTop's next node
	sTop = sTop->GetNextNode();

	//return the head node
	return headNode;
}