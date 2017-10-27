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

public:

    //Defualt constructor
    StudentRecordNode(int pRecordNumber = 0, int pIDNumber = 0, string pEmail = "", string pUnits = "", string pProgram = "", string pLevel = "");

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



    //Getters
    //////////////////////////////////////////////////
    //getter for the record number
    int GetRecordNumber();

    //getter for the ID Number 
    int GetIDNumber();

    //getter for the first name
    string GetFirstName();
    
    //getter for the last name
    string GetLastName();
    
    //getter for the email
    string GetEmail();

    //getter for the units (number of credits)
    string GetUnits();

    //getter for the program
    string GetProgram();
     
    //getter for the level (class standing)
    string GetLevel();


};