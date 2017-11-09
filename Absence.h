/*******************************************************************************************
* Programmer: Jamar Fraction                                                               *
* Class: CptS 122, Fall  2017; Lab Section 05											   *
* Programming Assignment: PA7															   *
* Date: November 8, 2017                                                                   *
* Description: This program fulfills the requirements for the seventh programming assignment*
********************************************************************************************/
#include <iostream>
#include <string>

using std::string;

#pragma once
class Absence{

public:

	//Default constructor
	Absence(string date = "");

	void SetDate(string passedDate);

	string GetDate();

	
private:

	string date;


};

