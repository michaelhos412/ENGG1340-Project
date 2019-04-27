#include "SortbyAmount.h"

void SortbyAmount(Record RecordList[] , string date, int count){

    // create a new list with the same size as the dynamic array and store all the records there after that sort it then output the list to a file and show the records in the main program
    Record temp;
    Record* SortedbyAmountList = new Record[databasesize];
    // check if the date == date
    int sortedlistindex = 0;
    for(int i = 0 ; i < count ; i++){
        if(RecordList[i].date == date){
            SortedbyAmountList[sortedlistindex] = RecordList[i];
            sortedlistindex += 1;
        }
        else{
            continue;
        }
    }
    if (sortedlistindex == 0){
        cout << "No records on " << date << endl;
    }
    else {
        for(int i = 0 ; i < sortedlistindex ; i++){
            for(int j = 0 ; j < sortedlistindex-1 ; j++){
                if(stod(SortedbyAmountList[j].amount) > stod(SortedbyAmountList[j+1].amount)){
                    temp = SortedbyAmountList[j+1];
                    SortedbyAmountList[j+1] = SortedbyAmountList[j];
                    SortedbyAmountList[j] = temp;
                }
            }
        }
        //i pindahin in kedalam else
        int counter = 0;
        while (counter < sortedlistindex){
            cout << SortedbyAmountList[counter].date << " " << SortedbyAmountList[counter].amount << " " << SortedbyAmountList[counter].type << " " << SortedbyAmountList[counter].account << " " << SortedbyAmountList[counter].category << endl;
            counter += 1;
        }
    }
    delete [] SortedbyAmountList;
}
