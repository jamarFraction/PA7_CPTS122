#include <string>

using std::string;

class StudentRecord{

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

    int recodNumber;
    int IDNumber;
    FullName studentName;
    string email;
    string units;
    string program;
    string level;

public:

    //Defualt constructor
    StudentRecord(int pRecordNumber = 0, int pIDNumber = 0, string pEmail = "", string pUnits = "", string pProgram = "", string pLevel = "");


    int GetRecordNumber();
    
};