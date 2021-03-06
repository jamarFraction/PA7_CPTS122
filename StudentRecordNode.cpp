#include "StudentRecordNode.h"

StudentRecordNode::StudentRecordNode(int pRecordNumber, int pIDNumber, string pEmail, string pUnits, string pProgram, string pLevel,
    StudentRecordNode *next, string pNumOfAbsences, AbsenceStack *pStackTop){
    
    recordNumber = pRecordNumber;

    IDNumber = pIDNumber;

    email = pEmail;

    units = pUnits;

    program = pProgram;

    level = pLevel;

    nextRecord = next;

	numberOfAbsences = pNumOfAbsences;

	this->stackTop = new AbsenceStack;

	//stackTop = nullptr;

}

int StudentRecordNode::GetRecordNumber() const{

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

int StudentRecordNode::GetIDNumber() const{

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

string StudentRecordNode::GetFirstName() const{

    //return the student's first name
    return this->studentName.firstName;

}

string StudentRecordNode::GetLastName() const{

    //return the student's last name
    return this->studentName.lastName;

}

void StudentRecordNode::SetEmail(string passedEmail){

    //set the private data member to the passed in string
    email = passedEmail;

}

string StudentRecordNode::GetEmail() const{

    //return the email
    return email;

}

void StudentRecordNode::SetUnits(string passedUnits){

    units = passedUnits;

}

string StudentRecordNode::GetUnits() const{

    return units;

}

void StudentRecordNode::SetProgram(string passedProgram){

    program = passedProgram;


}

void StudentRecordNode::SetLevel(string passedLevel){

    level = passedLevel;


}

string StudentRecordNode::GetProgram() const{

    return program;

}

string StudentRecordNode::GetLevel() const{

    return level;


}

void StudentRecordNode::SetNext(StudentRecordNode *&passedRecord){

    nextRecord = passedRecord;

}

StudentRecordNode* StudentRecordNode::GetNext() const{

    return nextRecord;

}

AbsenceStack*& StudentRecordNode::GetStack(){

	//returning our stack
	return this->stackTop;

}

void StudentRecordNode::SetAbsences(string passedAbsences) {

	//Setting the node absences to the absolute value of the passed absences
	this->numberOfAbsences = passedAbsences;

}

string StudentRecordNode::GetNumberOfAbsences() const{

	//returning the number of absences this node has had
	return this->numberOfAbsences;

}

void StudentRecordNode::ProcessAbsenceList(string passedAbsenceDates) {

	//The istream representation of the lis tof absences.. needed for geline
	istringstream AbsenceList(passedAbsenceDates);

	//Variables to hold dates and days
	string currentFullDate = "";
	string previousDate = "";



	//start the loop
	do {
		
		//set the previous date to what will be the last date pulled from the line
		previousDate = currentFullDate;

		//use getline to pull the next date from the line
		getline(AbsenceList, currentFullDate, ',');

		//are the dates the same?
		if (currentFullDate != previousDate) {
			//if not:

			//Allocate space for a new node
			StackNode *newNode = new StackNode;
			
			//set it's values to the current date
			newNode->SetData(currentFullDate);

			//push it into our absence stack
			this->GetStack()->Push(newNode);

		}



		//if no new information was pulled from the line, currentDate will remian the same as the last
		//run through the loop..
		//same information = end of new dates
	} while (currentFullDate != previousDate);

}