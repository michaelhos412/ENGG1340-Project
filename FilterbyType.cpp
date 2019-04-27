#include "FilterbyType.h"
#include <iostream>
#include <string>
#include "structandglobals.h"
using namespace std;

void FilterbyType(Record RecordList[] ,string date , string type , int count, int &sortedlistindex,int databasesize){
    Record temp;
    Record* SortedbyTypeList = new Record[databasesize];
    // check if the date == date
    for(int i = 0 ; i < count ; i++){
      if(RecordList[i].date == date && RecordList[i].type == type){
        SortedbyTypeList[sortedlistindex] = RecordList[i];
        sortedlistindex += 1;
      }
      else{
        continue;
      }
    }
    int counter = 0;
    while (counter < sortedlistindex){
      cout << SortedbyTypeList[counter].date << " " << SortedbyTypeList[counter].amount << " " << SortedbyTypeList[counter].type << " " << SortedbyTypeList[counter].account << " " << SortedbyTypeList[counter].category << endl;
      counter += 1;
    }
    delete [] SortedbyTypeList;
}
