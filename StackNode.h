/*******************************************************************************************
* Programmer: Jamar Fraction                                                               *
* Class: CptS 122, Fall  2017; Lab Section 05											   *
* Programming Assignment: PA7															   *
* Date: November 8, 2017                                                                   *
* Description: This program fulfills the requirements for the seventh programming assignment*
********************************************************************************************/
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

	void SetNextToNull();

};