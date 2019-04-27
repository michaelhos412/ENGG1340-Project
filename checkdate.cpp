#include "checkdate.h"
string check_Date(string date, int current_Date){
  string  search;
  int start_Date,start_Month, start_Year;
  start_Month = stoi(date.substr(2,2));
  start_Year = stoi(date.substr(4,4));
    if(start_Month <= 7){
      if (start_Month % 2 != 0){ //jan, mar, may, jul (31 days)
        if (current_Date > 31){
          search = "0" + to_string(current_Date%31) + "0" + to_string(start_Month+1) + to_string(start_Year);
        }
        else if(current_Date < 10){
          search = "0" + to_string(current_Date) + "0" + to_string(start_Month) + to_string(start_Year);
        }
        else {
          search = to_string(current_Date) + "0" + to_string(start_Month) + to_string(start_Year);
        }
      }
      else if (start_Month == 2){ //feb (29 days if leap year, 28 if not)
        if (((start_Year % 4) == 0 && (start_Year % 100) != 0) || (start_Year % 400) == 0 ){
          if (current_Date > 29) { //leap year
            search = "0" + to_string(current_Date%29) + "0" + to_string(start_Month+1) + to_string(start_Year);
          }
          else if(current_Date < 10){
            search = "0" + to_string(current_Date) + "0" + to_string(start_Month) + to_string(start_Year);
          }
          else {
            search = to_string(current_Date) + "0" + to_string(start_Month) + to_string(start_Year);
          }
        }
        else {
          if (current_Date > 28){ //not leap year
            search = "0" + to_string(current_Date%28) + "0" + to_string(start_Month+1) + to_string(start_Year);
          }
          else if(current_Date < 10){
            search = "0" + to_string(current_Date) + "0" + to_string(start_Month) + to_string(start_Year);
          }
          else {
            search = to_string(current_Date) + "0" + to_string(start_Month) + to_string(start_Year);
          }
        }
      }
      else { //apr,jun (30 days)
        if (current_Date > 30){
          search = "0" + to_string(current_Date%30) + "0" + to_string(start_Month+1) + to_string(start_Year);
        }
        else if(current_Date < 10){
          search = "0" + to_string(current_Date) + "0" + to_string(start_Month) + to_string(start_Year);
        }
        else {
          search = to_string(current_Date) + "0" + to_string(start_Month) + to_string(start_Year);
        }
      }
    }
    else if(start_Month >=8 && start_Month < 10) { // aug,sept
      if (start_Month % 2 != 0){ //sept (30 days)
        if (current_Date > 30){
          search = "0" + to_string(current_Date%30) + to_string(start_Month+1) + to_string(start_Year);
        }
        else if(current_Date < 10){
          search = "0" + to_string(current_Date) + to_string(start_Month) + to_string(start_Year);
        }
        else {
          search = to_string(current_Date) + to_string(start_Month) + to_string(start_Year);
        }
      }
      else { //aug (31 days)
        if (current_Date > 31 ){
          search = "0" + to_string(current_Date%31) + to_string(start_Month+1) + to_string(start_Year);
        }
        else if(current_Date < 10){
          search = "0" + to_string(current_Date) + to_string(start_Month) + to_string(start_Year);
        }
        else {
          search = to_string(current_Date) + to_string(start_Month) + to_string(start_Year);
        }
      }
    }
    else {//oct,nov,dec
      if (start_Month % 2 != 0){ // nov (30 days)
        if (current_Date > 30){
          search = "0" + to_string(current_Date%30) + to_string(start_Month+1) + to_string(start_Year);
        }
        else if(current_Date < 10){
          search = "0" + to_string(current_Date) + to_string(start_Month) + to_string(start_Year);
        }
        else {
          search = to_string(current_Date) + to_string(start_Month) + to_string(start_Year);
        }
      }
      else if (start_Month == 12){ // dec (31 days)
        if ( current_Date > 31) {
          search = "0" + to_string(current_Date%31) + "01" + to_string(start_Year+1);
        }
        else if(current_Date < 10){
          search = "0" + to_string(current_Date) + to_string(start_Month) + to_string(start_Year);
        }
        else {
          search = to_string(current_Date) + to_string(start_Month) + to_string(start_Year);
        }
      }
      else { //oct (31 days)
        if (current_Date > 31 ){
          search = "0" + to_string(current_Date%31) + to_string(start_Month+1) + to_string(start_Year);
        }
        else if(current_Date < 10){
          search = "0" + to_string(current_Date) + to_string(start_Month) + to_string(start_Year);
        }
        else {
          search = to_string(current_Date) + to_string(start_Month) + to_string(start_Year);
        }
      }
    }
    return search;
}
