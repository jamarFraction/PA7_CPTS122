#include <iostream>
#include <ctime>
#include "menu.h"

using std::cout;
using std::endl;

int main(void){


	//time_t t = time(0);   // get time now
	//struct tm * now = localtime(&t);
	//cout << (now->tm_year + 1900) << '-'
	//	<< (now->tm_mon + 1) << '-'
	//	<< now->tm_mday
	//	<< endl;



    //create a new menu
    Menu newMenu;

    //start the menu loop
    newMenu.RunApp();
    
    return 0;
}