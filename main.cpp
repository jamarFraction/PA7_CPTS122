#include <iostream>
#include "StudentRecordNode.h"
#include "menu.h"

using std::cout;
using std::endl;

int main(void){

    // StudentRecord newStudent;

    // cout << "Record Number: " << newStudent.GetRecordNumber() << endl;

    //create a new menu
    Menu newMenu;

    //start the menu loop
    newMenu.DisplayMenu();
    
    return 0;
}