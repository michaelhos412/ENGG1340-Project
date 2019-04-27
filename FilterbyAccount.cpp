#include <iostream>
#include <string>
#include "structandglobals.h"
#include "FilterbyAccount.h"
using namespace std;

void FilterbyAccount(Record RecordList[] ,string date , string account , int count, int& sortedlistindex, int databasesize){
    Record temp;
    Record* SortedbyAccountList = new Record[databasesize];
    // check if the date == date
    for(int i = 0 ; i < count ; i++){
      if(RecordList[i].date == date && RecordList[i].account == account){
        SortedbyAccountList[sortedlistindex] = RecordList[i];
        sortedlistindex += 1;
      }
      else{
        continue;
      }
    }
    int counter = 0;
    while (counter < sortedlistindex){
      cout << SortedbyAccountList[counter].date << " " << SortedbyAccountList[counter].amount << " " << SortedbyAccountList[counter].type << " " << SortedbyAccountList[counter].account << " " << SortedbyAccountList[counter].category << endl;
      counter += 1;
    }
    delete [] SortedbyAccountList;
}
