#include <iostream>
#include <fstream>
#include <string>

#include "StudentRecordList.h"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::getline;

class Menu{

public:

    //Default constructor
    Menu(){

        recordList = new StudentRecordList();

    }

    void RunApp(){

        DisplayMenu();

    }


private:

    StudentRecordList *recordList;

    void DisplayMenu(){
        
                //worker variable to be used for user menu option selection
                int option = 0;
        
                do{
        
                    //clear the screen
                    system("cls");
                
                        //Print the menu
                        cout << "Attendance Tracker MENU\n1. Import course list\n2. Load master list\n3. Store master list\n4. Mark absences\n" <<
                        "5. Edit absences\n6. Generate report\n7. Exit" << endl;
                
                        //Get the user input for a menu option
                        cin >> option;
                
                        //Run based on input
                        switch(option){
                
                            case 1 :
                            //Import the course list from classList.csv only if the current list is empty
                            if(this->recordList->GetHead() == nullptr){

                                this->ImportClassList();

								StackNode *tempNode = recordList->GetHead()->GetStack()->Pop<class T>();

                            }else{

                                //error, file already read in
                                system("cls");
                                cout << "Error- File already read in!" << endl;

                            }

							

							
					
                                
                                break;
                            
                                
            
                            //exit +
                            //anything else    
                            default:
                                
                                break;
                        }
        
        
        
                //if whatever that got passed into option isn't "7", this loop will loop
                }while(option != 7);
    }
        
    void ImportClassList(){

        //fstream variable that will hold the file
        ifstream classList("classList.csv");

        //if the file was opened successfully
        if(classList.is_open()){

            //pass the file to the processing function
            processFile(classList);

            //success
            cout << "Class list read in successfully!" << endl;
            system("pause");
            
        }else{

            //OoooOOOoooOOooOOOOooo where's the file, fam?
            cout << "Error opening file!" << endl;
			system("pause");
        }


    }
        
    void processFile(ifstream &passedClassList){

        //get the first line of the file to discard it
        string dummyLine = "";

        //pull the first line into the dummyLine, it's USELESS.. unacceptable
        getline(passedClassList, dummyLine);

        //while there is still data in the file
        while(!passedClassList.eof()){

            //Record variables
            int fileRecordNumber = 0;
            int fileIDNumber = 0;
            string fileLastName = "";
            string fileFirstName = "";
            string fileEmail = "";
            string fileUnits = "";
            string fileProgram = "";
            string fileLevel = "";
			string trash = "";

            //Pull all of the information from the line into local variables
            //Record number
            passedClassList >> fileRecordNumber;
            passedClassList.ignore(1, ',');

            //ID Number
            passedClassList >> fileIDNumber;
            passedClassList.ignore(1, ',');
            passedClassList.ignore(1, '\"');

            //Name
            getline(passedClassList, fileLastName, ',');

            getline(passedClassList, fileFirstName, '\"');
            passedClassList.ignore(1, ',');

            //Email
            getline(passedClassList, fileEmail, ',');

            //Units
            getline(passedClassList, fileUnits, ',');

            //Program
            getline(passedClassList, fileProgram, ',');

            //Level
            getline(passedClassList, fileLevel, '\n');

			//getline(passedClassList, trash, '\r');

            //Pass the variables to the insertion function
            recordList->InsertRecord(fileRecordNumber, fileIDNumber, fileLastName, fileFirstName, fileEmail, fileUnits, fileProgram, fileLevel);

        }


    }
  
};