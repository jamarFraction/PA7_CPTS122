#include <iostream>
#include <string>

using std::string;

#pragma once
class Absence{

public:

	//Default constructor
	Absence(int day =  0, string month = "", int year = 0);

	void SetDay(int passedDay);
	void SetMonth(string passedMonth);
	void SetYear(int passedYear);

	int GetDay();
	string GetMonth();
	int GetYear();



private:

	int day;
	string month;
	int year;


};

