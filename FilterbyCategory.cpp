
#include "FilterbyCategory.h"

void FilterbyCategory(Record RecordList[] ,string date , string category , int count, int& sortedlistindex){
    Record temp;
    Record* SortedbyCategoryList = new Record[databasesize];
    // check if the date == date
    for(int i = 0 ; i < count ; i++){
      if(RecordList[i].date == date && RecordList[i].category == category){
        SortedbyCategoryList[sortedlistindex] = RecordList[i];
        sortedlistindex += 1;
      }
      else{
        continue;
      }
    }
    int counter = 0;
    while (counter < sortedlistindex){
      cout << SortedbyCategoryList[counter].date << " " << SortedbyCategoryList[counter].amount << " " << SortedbyCategoryList[counter].type << " " << SortedbyCategoryList[counter].account << " " << SortedbyCategoryList[counter].category << endl;
      counter += 1;
    }
    delete [] SortedbyCategoryList;
}
