#include "Absence.h"

Absence::Absence(string pDate){

	date = pDate;

}

void Absence::SetDate(string passedDate) {

	date = passedDate;

}

string Absence::GetDate() {

	return this->date;
}
