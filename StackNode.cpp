#include "StackNode.h"

StackNode::StackNode(){

    //Set the defualt variables to the constructor default values
	absenceDate.SetDay(0);

	absenceDate.SetMonth("");

	absenceDate.SetYear(0);

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