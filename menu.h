#include <iostream>
#include <fstream>
#include <string>

#include "StudentRecordList.h"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
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
								if (HasListBeenLoaded() == false) {

									this->ImportClassList();

								}

                                break;

							case 2:
								//Import the course list from master.txt only if the current list is empty
								if (HasListBeenLoaded() == false) {

									this->ImportMasterList();


								}

								break;



							case 3:

								//wrinting to the "master" text file
								this->StartWriteToMasterFile();


                            
                
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
            processFile(classList , "class");

			//close the file 
			classList.close();

            //success
			system("cls");
            cout << "Class list read in successfully!" << endl;
            system("pause");
            
        }else{

            //OoooOOOoooOOooOOOOooo where's the file, fam?
			system("cls");
            cout << "Error opening file!" << endl;
			system("pause");
        }

    }
        
    void processFile(ifstream &passedClassList, string listType){

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

			//Check for class or master list type
			if (listType == "class") {

				//Level
				getline(passedClassList, fileLevel, '\n');


				//Pass the variables to the insertion function
				recordList->InsertRecord(fileRecordNumber, fileIDNumber, fileLastName, fileFirstName, fileEmail, fileUnits, fileProgram, fileLevel);

			}
			else {

				//master list type
				//Level
				getline(passedClassList, fileLevel, ',');

				//Number of absences
				string fileNumberOfAbsences;

				getline(passedClassList, fileNumberOfAbsences, '*');

				//list of absences
				string fileListOfAbsences;

				getline(passedClassList, fileListOfAbsences, '*');

				recordList->InsertRecord(fileRecordNumber, fileIDNumber, fileLastName, fileFirstName,
					fileEmail, fileUnits, fileProgram, fileLevel, fileNumberOfAbsences, fileListOfAbsences);


			}
            
        }


    }

	void StartWriteToMasterFile() {


		//check to see if the list has already been populated
		if (this->recordList->GetHead() != nullptr) {

			//Assign our text file as the file to be written to
			ofstream outfile("master.txt");

			//check for the file being open
			if (outfile.is_open()) {

				//pass the outfile to the writing function
				WriteListToFile(outfile);

				//close the outfile
				outfile.close();

				//success
				system("cls");
				cout << "Class list written successfully!" << endl;
				system("pause");

			}
			else {

				//OoooOOOoooOOooOOOOooo where's the file, fam?
				system("cls");
				cout << "Error opening file!" << endl;
				system("pause");

			}
		}
		else {

			//there is no class list on record
			system("cls");
			cout << "Error: No class list has been read in.\nYou must read in a class list before being able\nto write to the master file\n" << endl;
			system("pause");
		}

		


	}

	void WriteListToFile(ofstream &outfile) {

		//Write the first line of the file that gives a format for the data contained
		outfile << "RecordNumber,ID,Name,Email,Units,Program,Level,Number of Absences*Absence1,etc..*";

		//Create a pointer and point it to the head Record of the list
		StudentRecordNode *location = this->recordList->GetHead();

		//Loop through the list, visiting each node
		while (location != nullptr) {

			//pass the outfile and the pointer to the node-writing function
			PrintStudentRecordToFile(outfile, location);

			//update the pointer to the Node's next pointer
			location = location->GetNext();
		}

	}

	void PrintStudentRecordToFile(ofstream &outfile, StudentRecordNode *&currentRecord) {

		outfile << "\n" << currentRecord->GetRecordNumber() << "," << currentRecord->GetIDNumber() << ",\"" <<
			currentRecord->GetLastName() << "," << currentRecord->GetFirstName() << "\"," << currentRecord->GetEmail() <<
			"," << currentRecord->GetUnits() << "," << currentRecord->GetProgram() <<
			"," << currentRecord->GetLevel() << "," << currentRecord->GetNumberOfAbsences() << "*";

		//check to see if the current record has absences or not
		if (currentRecord->GetNumberOfAbsences() != 0) {


			//the record has at least one absence
			StackNode *currentStackNode = currentRecord->GetStack()->GetTop();


			while (currentStackNode != nullptr) {

				//Variable to hold the info for the current absence
				Absence currentAbsence = currentStackNode->GetData();

				//xx/xx/xxxx
				outfile << currentAbsence.GetMonth() << "/" << currentAbsence.GetDay() << "/" << currentAbsence.GetYear();

				//advance to the next absence
				currentStackNode = currentStackNode->GetNextNode();



				//check to see if there is another absence
				if (currentStackNode != nullptr) {

					//if so, print a comma
					outfile << ",";

				}
				else {

					//otherwise, print a star
					outfile << "*";

				}

			}

		}
	}

	bool HasListBeenLoaded() {


		if (this->recordList->GetHead() == nullptr) {

			return false;

		}
		

		//error, file already read in
		system("cls");
		cout << "Error: File already read in!" << endl;
		system("pause");

		return true;

	}

	void ImportMasterList() {


		//fstream variable that will hold the file
		ifstream masterList("master.txt");

		//if the file was opened successfully
		if (masterList.is_open()) {

			//pass the file to the processing function
			processFile(masterList, "master");

			//close the file 
			masterList.close();

			//success
			system("cls");
			cout << "Master list read in successfully!" << endl;
			system("pause");

		}
		else {

			//OoooOOOoooOOooOOOOooo where's the file, fam?
			system("cls");
			cout << "Error opening file!" << endl;
			system("pause");
		}




	}
  
};