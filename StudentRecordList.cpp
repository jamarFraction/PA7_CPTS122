#include "StudentRecordList.h"

StudentRecordList::StudentRecordList(StudentRecordNode *head){

    headNode = head;

}

void StudentRecordList::InsertRecord(int passedRecordNumber, int passedIDNumber, string passedLastName, string passedFirstName, string passedEmail, string passedUnits, string passedProgram, string passedLevel){

    //Create a pointer to a StudentRecordNode and point it to a new record node with default values
    StudentRecordNode *newRecord = new StudentRecordNode();

    this->SetValues(newRecord, passedRecordNumber, passedIDNumber, passedLastName, passedFirstName, passedEmail,
                    passedUnits, passedProgram, passedLevel);

    //insert the node into an empty list
    if (headNode == nullptr)
    {
        //The list is empty so set the head of the list to the new node
        this->SetHead(newRecord);
    }
    else
    {

        //Set the new node's next record to the current head node
        newRecord->SetNext(headNode);

        //Set the head node to the new record
        this->SetHead(newRecord);
    }

}

void StudentRecordList::SetValues(StudentRecordNode *&passedNode, int passedRecordNumber, int passedIDNumber, string passedLastName, string passedFirstName, string passedEmail, string passedUnits, string passedProgram, string passedLevel){

    passedNode->SetRecordNumber(passedRecordNumber);

    passedNode->SetIDNumber(passedIDNumber);

    passedNode->SetFullName(passedFirstName, passedLastName);

    passedNode->SetEmail(passedEmail);

    passedNode->SetUnits(passedUnits);

    passedNode->SetProgram(passedProgram);

    passedNode->SetLevel(passedLevel);
}

void StudentRecordList::SetHead(StudentRecordNode *&passedNode){

    this->headNode = passedNode;

}

StudentRecordNode*& StudentRecordList::GetHead(){

    return headNode;

}
