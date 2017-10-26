#include "StudentRecord.h"

StudentRecord::StudentRecord(int pRecordNumber, int pIDNumber, string pEmail, string pUnits, string pProgram, string pLevel){
    
    
    recodNumber = pRecordNumber;

    IDNumber = pIDNumber;

    email = pEmail;

    units = pUnits;

    program = pProgram;

    level = pLevel;

}

int StudentRecord::GetRecordNumber(){


    return recodNumber;


}