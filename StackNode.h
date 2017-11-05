#include <iostream>
#include <stdio.h>
#include "Absence.h"


class StackNode{

private:

	Absence absenceDate;

    StackNode *nextNode;

    
public:

    //Defualt Constructor
    StackNode(StackNode *pNextNode = nullptr);

    //Getter for the data
    Absence& GetData();

    //Setter for the data
	void SetData(string passedAbsenceDate);

    //Getter for the next Node
    StackNode*& GetNextNode();

    // //Setter for the next Node
    void SetNextNode(StackNode *&passedNode);

};