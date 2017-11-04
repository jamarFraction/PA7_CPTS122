#include <iostream>
#include <string>

using std::string;

#pragma once
class Absence{

public:

	//Default constructor
	Absence(string day =  "", string month = "", string year = "");

	void SetDay(string passedDay);
	void SetMonth(string passedMonth);
	void SetYear(string passedYear);

	string GetDay();
	string GetMonth();
	string GetYear();



private:

	string day;
	string month;
	string year;


};

