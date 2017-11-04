#include "StackNode.h"

StackNode::StackNode(Absence pAbsenceDate, StackNode *pNextNode){

    //Set the defualt variables to the constructor default values
	absenceDate.SetDay("");

	absenceDate.SetMonth("");

	absenceDate.SetYear("");

    //will be nullptr
    nextNode = nullptr;

}


Absence& StackNode::GetData(){

	return this->absenceDate;

}


void StackNode::SetData(Absence &passedData){

	this->absenceDate = passedData;

}

StackNode*& StackNode::GetNextNode(){

	return nextNode;

}

void StackNode::SetNextNode(StackNode *&passedNode){

    nextNode = passedNode;

}