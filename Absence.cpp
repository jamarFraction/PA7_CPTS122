#include "Absence.h"

Absence::Absence(string pDay, string pMonth, string pYear){

	day = pDay;

	month = pMonth;

	year = pYear;

}

void Absence::SetDay(string passedDay) {

	day = passedDay;

}

void Absence::SetMonth(string passedMonth) {

	month = passedMonth;

}

void Absence::SetYear(string passedYear) {

	year = passedYear;

}

string Absence::GetDay() {

	return day;

}
 
string Absence::GetMonth() {

	return month;

}

string Absence::GetYear() {

	return year;

}
