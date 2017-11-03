#include "Absence.h"

Absence::Absence(int pDay, string pMonth, int pYear){

	day = pDay;

	month = pMonth;

	year = pYear;

}

void Absence::SetDay(int passedDay) {

	day = passedDay;

}

void Absence::SetMonth(string passedMonth) {

	month = passedMonth;

}

void Absence::SetYear(int passedYear) {

	year = passedYear;

}

int Absence::GetDay() {

	return day;

}
 
string Absence::GetMonth() {

	return month;

}

int Absence::GetYear() {

	return year;

}
