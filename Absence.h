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

