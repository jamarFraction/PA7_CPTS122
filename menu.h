/*******************************************************************************************
* Programmer: Jamar Fraction                                                               *
* Class: CptS 122, Fall  2017; Lab Section 05											   *
* Programming Assignment: PA7															   *
* Date: November 8, 2017                                                                   *
* Description: This program fulfills the requirements for the seventh programming assignment*
********************************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>

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

								break;

							case 4:

								//Mark absences
								if (this->recordList->GetHead() != nullptr) {

									this->MarkAbsences();

								}
								else {

									//no list has been read in yet
									system("cls");
									cout << "Error: no list present" << endl;
									system("pause");
								}

								break;

							case 6:

								if (this->recordList->GetHead() != nullptr) {

									this->StartReportGeneration();

								}
								else {

									//no list has been read in yet
									system("cls");
									cout << "Error: no list present" << endl;
									system("pause");
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

				//are there any absences to read in?
				if (fileNumberOfAbsences != "0") {

					getline(passedClassList, fileListOfAbsences);

					fileListOfAbsences.pop_back();

				}
				else {

					//get the '*' at the end of the line as to not import another record
					getline(passedClassList, dummyLine);
				}
				

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
		if (currentRecord->GetNumberOfAbsences() != "0") {


			

			//keep popping the stack and pushing the nodes into a new stack until the first stack is empty
			//as a push is performed back into the original stack, write to the file

			AbsenceStack *tempStack = new AbsenceStack;
			StackNode * currentStackNode;

			while (currentRecord->GetStack()->isEmpty() == false) {

				currentStackNode = currentRecord->GetStack()->Pop();

				tempStack->Push(currentStackNode);

			}



			while (tempStack->isEmpty() == false) {

				//absences are now in reverse order in the temp stack
				currentStackNode = tempStack->Pop();

				//Variable to hold the info for the current absence
				Absence currentAbsence = currentStackNode->GetData();

				
				//xx/xx/xxxx
				outfile << currentAbsence.GetDate();

				currentRecord->GetStack()->Push(currentStackNode);

				//advance to the next absence
				if (tempStack->isEmpty() == false) {

					//print a comma
					outfile << ",";
				}
				else {

					//otherwise, print a star
					outfile << "*";
				}
				

				////check to see if there is another absence
				//if (currentStackNode != nullptr) {

				//	//if so, print a comma
				//	outfile << ",";

				//}
				//else {

				//	//otherwise, print a star
				//	outfile << "*";

				//}

			}

			

		}
	}

	bool HasListBeenLoaded() {

		//okay let's be honest, the logic here is fucked
		if (this->recordList != nullptr) {

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
  
	void MarkAbsences() {

		//input for menu
		int option = 0;

		
		time_t t = time(0);   // get time now
		struct tm * now = localtime(&t);
		

		string currentDate = "";
		std::ostringstream oss;

		//date in format mm/dd/yyyy
		oss << (now->tm_mon + 1) << "/" << (now->tm_mday) << "/" << (now->tm_year + 1900);
		currentDate = oss.str();


		//Create a pointer and point it to the first record in the list
		StudentRecordNode *location = this->recordList->GetHead();

		//Loop through the Students and prompt for an absence
		while (location != nullptr) {

			do {

				system("cls");

				//prompt for absence
				cout << "Was " << location->GetFirstName() << " " << location->GetLastName() <<
					" present? (1 = Yes, 2 = No): ";

				cin >> option;

				//The student was absent
				if (option == 2) {

					//push today if the student hasn't already been marked absent
					if (location->GetStack()->GetTop() == nullptr || location->GetStack()->Peek()->GetData().GetDate() != currentDate) {

						//Create pointer to a stack node, set the date to today, push the absence to the stack, increment the absence number
						StackNode *newNode = new StackNode();

						newNode->SetData(currentDate);

						location->GetStack()->Push(newNode);

						//convert the number of absences to an int + increment by 1
						int absence = std::stoi(location->GetNumberOfAbsences()) + 1;

						//set the number of absences
						location->SetAbsences(std::to_string(absence));


					}

				}


			} while (option != 1 && option != 2);
			
			//advance the location in the student list
			location = location->GetNext();
		}

		//Success!
		system("cls");
		cout << "Absences recorded sucessfully!" << endl;
		system("pause");

	}

	void StartReportGeneration() {

		int option = 0;

		do {
			//Sub-menu prompt
			system("cls");
			cout << "Which type of report would you like to generate?\n1. Most recent absence for all students\n2. Absences based on number of absences\n";
			cin >> option;

		} while (option < 1 || option > 2);


		//What kind of report?
		switch (option) {

		case 1:

			//report prints in this function.. so go there
			this->MostRecentAbsenceReport();

			break;
		case 2:

			//same as case 1.. see you there
			this->AbsenceLimitedReport();

			break;

		//you heard?	
		default:
			break;


		}
	}

	void MostRecentAbsenceReport() {

		cout << "Most recent absences\n\n";

		//First record in the list
		StudentRecordNode *currentRecord = this->recordList->GetHead();

		//String to hold the date
		string mostRecentAbsence;

		while (currentRecord != nullptr) {

			//if the stack is empty
			if (currentRecord->GetStack()->isEmpty() == false) {

				//set the absence date
				mostRecentAbsence = currentRecord->GetStack()->GetTop()->GetData().GetDate();

				//print
				cout << currentRecord->GetFirstName() << " " << currentRecord->GetLastName() << ": " <<
					mostRecentAbsence << endl;

			}
			else {

				//First Last: xx/xx/xxxx
				cout << currentRecord->GetFirstName() << " " << currentRecord->GetLastName() << ": " <<
					"No absences" << endl;


			}

			//advance to the next record in the list
			currentRecord = currentRecord->GetNext();


		}

		//and we wait..
		cout << "\n\n";
		system("pause");

		 
	}

	void AbsenceLimitedReport() {

		//at least this many absences
		int absenceFloor = 0;

		do {
			//Sub-menu prompt
			system("cls");
			cout << "Print records with at least how many absences? ";
			cin >> absenceFloor;

		} while (absenceFloor < 1);

		cout << "\n\n";


		//First record in the list
		StudentRecordNode *currentRecord = this->recordList->GetHead();

		//String to hold the date
		string mostRecentAbsence;



		while (currentRecord != nullptr) {

			//convert the number of absences to an int
			int absence = std::stoi(currentRecord->GetNumberOfAbsences());

			//check the record absences against the user's number
			if (absence >= absenceFloor) {

				cout << currentRecord->GetFirstName() << " " << currentRecord->GetLastName() << endl;

			}


			//advance to the next record in the list
			currentRecord = currentRecord->GetNext();
		}


		//and we wait..
		cout << "\n\n";
		system("pause");
	}
};