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
        string passedEmail, string passedUnits, string passedProgram, string passedLevel);

    //Setter for the head node
    void SetHead(StudentRecordNode *&passedNode);    

    //Getter for the head node
    StudentRecordNode *GetHead();
 

private:

    //Start of the list
    StudentRecordNode *headNode;

    //Private helper function for making nodes
    StudentRecordNode *&makeNode(int passedRecordNumber, int passedIDNumber, string passedLastName, string passedFirstName,
        string passedEmail, string passedUnits, string passedProgram, string passedLevel);

    
    void SetValues(StudentRecordNode *&passedNode, int passedRecordNumber, int passedIDNumber, string passedLastName, string passedFirstName,
        string passedEmail, string passedUnits, string passedProgram, string passedLevel);    

};