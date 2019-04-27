#include "getall.h"
#include "structandglobals.h"
#include <cstdlib>
using namespace std;
void GetAllRecords(Record RecordList[] ,string date , double &totalexpense, double &totalincome, int count, double &cash, double &debit, double &oct){
  // check if the date == date
  for(int i = 0 ; i < count ; i++){
    if(RecordList[i].date == date){
      if (RecordList[i].type == "i"){
        totalincome +=  stod(RecordList[i].amount);
      }
      else {
        totalexpense +=  stod(RecordList[i].amount);
        if (RecordList[i].account == "c"){
          cash += stod(RecordList[i].amount);
        }
        else if (RecordList[i].account == "d"){
          debit += stod(RecordList[i].amount);
        }
        else {
          oct += stod(RecordList[i].amount);
        }
      }
    }
    else{
      continue;
    }
  }
}
