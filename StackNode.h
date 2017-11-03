#include <iostream>
#include <stdio.h>
#include "Absence.h"


class StackNode{

private:

	Absence absenceDate;

    StackNode *nextNode;

    
public:

    //Defualt Constructor
    StackNode(Absence passedData = NULL, StackNode* passednextNode = nullptr);

    //Getter for the data
    Absence& GetData();

    //Setter for the data
    void SetData(Absence &passedData);

    //Getter for the next Node
    Absence* GetNextNode();

    // //Setter for the next Node
    void SetNextNode(Absence *&passedNode);

};