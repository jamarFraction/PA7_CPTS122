#include "StackNode.h"

StackNode::StackNode(StackNode *pNextNode){

    //Set the defualt variables to the constructor default values
	absenceDate.SetDate("");

    //will be nullptr
    nextNode = nullptr;

}


Absence& StackNode::GetData(){

	return this->absenceDate;

}

void StackNode::SetData(string passedDate) {

	//create a new absence
	static Absence newAbsence;

	//set the data
	newAbsence.SetDate(passedDate);

	//set value of absence date in this new stacknode
	this->absenceDate = newAbsence;

}

StackNode*& StackNode::GetNextNode(){

	return nextNode;

}

void StackNode::SetNextNode(StackNode *&passedNode){

    nextNode = passedNode;

}