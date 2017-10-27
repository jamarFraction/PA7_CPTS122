#include <string>
using std::string;

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

public:

    //Defualt constructor
    StudentRecordNode(int pRecordNumber = 0, int pIDNumber = 0, string pEmail = "", string pUnits = "", string pProgram = "",
     string pLevel = "", StudentRecordNode *next = nullptr);

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


};