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
        temp->SetNextNode(passedData);

        //set the top of the stack to the passedData
        sTop = passedData;

    }

}