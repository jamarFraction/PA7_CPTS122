#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::string;

class Menu{

public:

    //defualt constructor
    Menu(){}

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
                    //Import the course list from classList.csv
                        this->ImportClassList();
                        break;
                    
                        
    
                    //exit +
                    //anything else    
                    default:
                        
                        break;
                }



        //if whatever that got passed into option isn't "7", this loop will loop
        }while(option != 7);
    }




private:

    void ImportClassList(){

        //fstream variable that will hold the file
        fstream classList("classList.csv");

        //if the file was opened successfully
        if(classList.is_open()){

            //pass the file to the processing function
            processFile(classList);
            
        }else{

            //OoooOOOoooOOooOOOOooo where's the file, fam?
            cout << "Error opening file!" << endl;
        }


    }
        
    
    void processFile(fstream &passedClassList){

        //get the first line of the file to discard it
        string dummyLine = "";

        //pull the first line into the dummyLine, it's USELESS
        std::getline(passedClassList, dummyLine);
    }
        
};