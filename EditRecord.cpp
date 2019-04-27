#include "EditRecord.h"
#include "structandglobals.h"
#include <iostream>
#include <string>
using namespace std;
int EditRecord(string deleteline, string DateToEdit, Record RecordList[] , int count){
  int counter =0;
  for (int i=0; i < count ; i++){
      string combination;
      combination = RecordList[i].date + " " + RecordList[i].amount + " " + RecordList[i].type + " " + RecordList[i].account + " " + RecordList[i].category;// ini i yang cari aja
      if (combination == deleteline){
        RecordList[i].date = "-";
        RecordList[i].amount = "-";
        RecordList[i].type = "-";
        RecordList[i].account = "-";
        RecordList[i].category = "-";
        counter ++;
      }
      else {
        continue;
      }
  }
  return counter;
}
