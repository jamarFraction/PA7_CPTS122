#include "StudentRecordNode.h"

StudentRecordNode::StudentRecordNode(int pRecordNumber, int pIDNumber, string pEmail, string pUnits, string pProgram, string pLevel){
    
    recordNumber = pRecordNumber;

    IDNumber = pIDNumber;

    email = pEmail;

    units = pUnits;

    program = pProgram;

    level = pLevel;

}

int StudentRecordNode::GetRecordNumber(){

    //return the private member
    return recordNumber;
}

void StudentRecordNode::SetRecordNumber(int passedRecordNumber){


    if(passedRecordNumber > 999){

        //if the number passed in is greater than the digit threshold
        //set it to the maximum allowable number that is 3 digits
        recordNumber = 999;

    }else{
        
        //otherwise, set it to the absolute value of the passed int
        recordNumber = abs(passedRecordNumber);

    }
}

int StudentRecordNode::GetIDNumber(){

    //return the private data member
    return IDNumber;

}

void StudentRecordNode::SetIDNumber(int passedIDNumber){

    //if the number passed in is greater than the 9-digit threshold
    //set it to the maximum allowable number that is 9 digits
    if(passedIDNumber > 999999999){

        IDNumber = 999999999;

    }else{

        //otherwise, set it to the absolute value s of the passed int
        IDNumber = abs(passedIDNumber);

    }

}

void StudentRecordNode::SetFullName(string passedFirstName, string passedLastName){

    //set the first and last name to the strings passed in
    this->studentName.firstName = passedFirstName;

    this->studentName.lastName = passedLastName;

}

string StudentRecordNode::GetFirstName(){

    //return the student's first name
    return this->studentName.firstName;

}

string StudentRecordNode::GetLastName(){

    //return the student's last name
    return this->studentName.lastName;

}

void StudentRecordNode::SetEmail(string passedEmail){

    //set the private data member to the passed in string
    email = passedEmail;

}

string StudentRecordNode::GetEmail(){

    //return the email
    return email;

}

void StudentRecordNode::SetUnits(string passedUnits){

    units = passedUnits;

}

string StudentRecordNode::GetUnits(){

    return units;

}

void StudentRecordNode::SetProgram(string passedProgram){

    program = passedProgram;


}

void StudentRecordNode::SetLevel(string passedLevel){

    level = passedLevel;


}

string StudentRecordNode::GetProgram(){

    return program;

}

string StudentRecordNode::GetLevel(){

    return level;


}