/*******************************************************************************************
* Programmer: Jamar Fraction                                                               *
* Class: CptS 122, Fall  2017; Lab Section 05											   *
* Programming Assignment: PA7															   *
* Date: November 8, 2017                                                                   *
* Description: This program fulfills the requirements for the seventh programming assignment*
********************************************************************************************/
#include <string>
#include <sstream>
#include "AbsenceStack.h"

using std::string;
using std::istringstream;


class StudentRecordNode{

    //FullName class created to hold the first and last name of a student
    class FullName{
    public:
        string lastName;
        string firstName;

        //Default constructor
        FullName(string pLastName = "", string pFirstName = ""){

            lastName = pLastName;
            firstName = pFirstName;

        }
    };

    
private:

    // record number (max 3 digits)
    // ID number (max 9 digits)
    // name (last, first)
    // email
    // units (number of credits for class or AU for audit)
    // program (major)
    // level (freshman, sophomore, junior, senior, graduate)
	
    int recordNumber;
    int IDNumber;
    FullName studentName;
    string email;
    string units;
    string program;
    string level;
    StudentRecordNode *nextRecord;

    string numberOfAbsences;
    AbsenceStack *stackTop;

public:

    //Defualt constructor
    StudentRecordNode(int pRecordNumber = 0, int pIDNumber = 0, string pEmail = "", string pUnits = "", string pProgram = "",
     string pLevel = "", StudentRecordNode *next = nullptr, string pNumOfAbsences = "0", AbsenceStack *pStackTop = nullptr);

    //Setters
    //////////////////////////////////////////////////
    //setter for the record number
    void SetRecordNumber(int passedRecordNumber);

    //setter for the ID Number
    void SetIDNumber(int passedIDNumber);

    //setter for the Full Name
    void SetFullName(string passedFirstName, string passedLastName);

    //setter for the email
    void SetEmail(string passedEmail);

    //setter for the units
    void SetUnits(string passedUnits);

    //setter for the program
    void SetProgram(string passedProgram);
    
    //setter for the level
    void SetLevel(string passedLevel);

    //Setter for the next record
    void SetNext(StudentRecordNode *&passedRecord);

	//Setter for the absences
	void SetAbsences(string passedAbsences);

	//Process Absence List
	//Function takes the string representation of the dates the student has been
	//absent and pushes them into the absence stack
	void ProcessAbsenceList(string passedAbsenceDates);


    //Getters
    //////////////////////////////////////////////////
    //getter for the record number
    int GetRecordNumber() const;

    //getter for the ID Number 
    int GetIDNumber() const;

    //getter for the first name
    string GetFirstName() const;
    
    //getter for the last name
    string GetLastName() const;
    
    //getter for the email
    string GetEmail() const;

    //getter for the units (number of credits)
    string GetUnits() const;

    //getter for the program
    string GetProgram() const;
     
    //getter for the level (class standing)
    string GetLevel() const;

    //Getter for the next record
    StudentRecordNode* GetNext() const;

	//getter for the numbe fo absences
	string GetNumberOfAbsences() const;

	//Getter for the absence stack
	AbsenceStack*& GetStack();


};