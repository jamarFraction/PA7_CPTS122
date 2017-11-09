/*******************************************************************************************
* Programmer: Jamar Fraction                                                               *
* Class: CptS 122, Fall  2017; Lab Section 05											   *
* Programming Assignment: PA7															   *
* Date: November 8, 2017                                                                   *
* Description: This program fulfills the requirements for the seventh programming assignment*
********************************************************************************************/
#include <iostream>
#include <string>
#include "StudentRecordNode.h"

using std::string;
using std::cout;
using std::endl;

class StudentRecordList{

public:

    //default constructor
    StudentRecordList(StudentRecordNode *head = nullptr);

    //Insertion of a record
    void InsertRecord(int passedRecordNumber, int passedIDNumber, string passedLastName, string passedFirstName,
        string passedEmail, string passedUnits, string passedProgram, string passedLevel,
		string passedNumberOfAbsences = "", string passedAbsenceList = "");

    //Setter for the head node
    void SetHead(StudentRecordNode *&passedNode);    

    //Getter for the head node
    StudentRecordNode *&GetHead();
 

private:

    //Start of the list
    StudentRecordNode *headNode;

    void SetValues(StudentRecordNode *&passedNode, int passedRecordNumber, int passedIDNumber, string passedLastName, string passedFirstName,
        string passedEmail, string passedUnits, string passedProgram, string passedLevel);    

};