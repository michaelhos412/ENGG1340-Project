#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include "structandglobals.h"
#include "printingfunctions.cpp"
#include "EditRecord.cpp"
#include "checkdate.cpp"
#include "AddRecord.cpp"
#include "getall.cpp"
#include "SortbyAmount.cpp"
#include "setbudget.cpp"
#include "FilterbyType.cpp"
#include "checkbudget.cpp"
#include "FilterbyAccount.cpp"
#include "FilterbyCategory.cpp"
using namespace std;

void IncreaseSizeofArray(Record* &Records , int &rc_size , int change ){
    Record* NewSize_Records = new Record[rc_size+change];
    for(int i = 0 ; i < rc_size ; i++){
      NewSize_Records[i] = Records[i];
    }
    //delete the old dynamic array
    delete [] Records;
    //point to new dynamic array
    Records = NewSize_Records;
    delete [] NewSize_Records;
}

int main(){
  int option, RecordCount = 0;
  string date , type , account , category , DateToEdit , LineToEdit;
  double budget = 0;
  double totalspent = 0 , cash_expense = 0 , debit_expense = 0 , oct_expense = 0;
  while (true){
    printMenu();
    cin >> option;
    while (true){
      if (option <= 5 && option >= 0) {
        break;
      }
      else{
        cout << "Sorry, your choice is out of range. Please try again!" << endl;
        cout << "Enter Choice: ";
        cin >> option;
      }
    }
    if (option == 0){
      break;
    }
    else if (option == 1){
      AddRecord(Records, RecordCount);
      RecordCount += 1;
      if (RecordCount > databasesize){
        IncreaseSizeofArray(Records , databasesize , databasesize);
      }
    }
    else if(option == 2){
      int counterline = 0;
      printShow();
      cout << "Enter Choice (e.g. 1,2,etc.): ";
      cin >> option;
      while (true){
        if (option <= 7  && option > 0) {
          break;
        }
        else{
          cout << "Sorry, your choice is out of range. Please try again!" << endl;
          cout << "Enter Choice: ";
          cin >> option;
        }
      }
      cout << "Enter Date (ddmmyyyy): ";
      cin >> date;
      while (true){
        if (option <= 7  && option > 0) {
          break;
        }
        else{
          cout << "Sorry, your choice is out of range. Please try again!" << endl;
          cout << "Enter Choice: ";
          cin >> option;
        }
      }
      if(option == 1){
        SortbyAmount(Records,date,RecordCount);
      }
      else if(option == 2){
        cout << "Enter type to be displayed first (i/e): ";
        cin >> type;
        //loop until it inputs the right type
        while (true) {
          if (type == "i") break;
          else if (type == "e") break;
          else {
            cout << "Sorry, your input is wrong. Please try again!" << endl;
            cout << "Enter type to be displayed first (i/e): ";
            cin >> type;
          }
        }
        if (type == "i"){
          FilterbyType(Records,date,type,RecordCount,counterline);
          FilterbyType(Records,date,"e",RecordCount,counterline);
          if (counterline == 0) {
            cout << "There is no record in the file" << endl;
          }
        }
        else {
          FilterbyType(Records,date,type,RecordCount,counterline);
          FilterbyType(Records,date,"i",RecordCount,counterline);
          if (counterline == 0) {
            cout << "There is no record in the file" << endl;
          }
        }
      }
      else if(option == 3){
        cout << "Please enter the type (i/e): ";
        cin >> type;
        while (type != "i" && type != "e"){
          cout << "Sorry, your input is wrong. Please try again!" << endl;
          cin >> type;
        }
        FilterbyType(Records, date, type, RecordCount,counterline);
        if (counterline == 0) {
          cout << "There is no record in the file." << endl;
        }
      }
      else if(option == 4){
        FilterbyAccount(Records , date , "c" ,RecordCount, counterline);
        FilterbyAccount(Records , date , "d" ,RecordCount, counterline);
        FilterbyAccount(Records , date , "o" ,RecordCount, counterline);
        if (counterline == 0) {
          cout << "There is no record in the file" << endl;
        }
      }
      else if(option == 5){
        cout << "Please enter which account you want to see (c / d / o): ";
        cin >> account;
        while (true){
          if ( account == "c") break;
          else if (account == "d") break;
          else if (account == "o") break;
          else {
            cout << "Sorry, your input is not in the choices. Please try again!" << endl;
            cout << "Enter Choice: ";
            cin >> account;
          }
        }
        FilterbyAccount(Records , date , account ,RecordCount, counterline);
        if (counterline == 0) {
          cout << "There is no record in the file" << endl;
        }
      }
      else if(option == 6){
        FilterbyCategory(Records , date , "f" ,RecordCount, counterline);
        FilterbyCategory(Records , date , "t" ,RecordCount, counterline);
        FilterbyCategory(Records , date , "u" ,RecordCount, counterline);
        FilterbyCategory(Records , date , "o" ,RecordCount, counterline);
        if (counterline == 0) {
          cout << "There is no record in the file" << endl;
        }
      }
      else if(option == 7){
        cout << "Please enter which category you want to see (f / t / u / o): ";
        cin >> category;
        while (true) {
          if (category == "f") break;
          else if (category == "t") break;
          else if (category == "u") break;
          else if (category == "o") break;
          else {
            cout << "Sorry, your input is not in the choices. Please try again!" << endl;
            cout << "Enter Choice: ";
            cin >> category;
          }
        }
        FilterbyCategory(Records , date , category ,RecordCount, counterline);
        if (counterline == 0) {
          cout << "There is no record in the file" << endl;
        }
      }
    }
    else if(option == 3){
      int result;
      //get the date to be edited
      cout << "What date do you want to edit: ";
      cin >> DateToEdit;
      //ask which one they wanna Edit
      cout << "Your data on that date: " << endl;
      SortbyAmount(Records,DateToEdit,RecordCount);
      cout << "Please write which record you want to edit (Format: ddmmyyyy amount type account category): ";
      cin.ignore();
      getline(cin, LineToEdit);
      //editting record
      result = EditRecord(LineToEdit , DateToEdit , Records , RecordCount);
      if (result != 0){
        cout << LineToEdit << " has been removed" << endl; // Ganti yg ini buat sesuain to the parameter
      }
      else{
        cout << "There is no such record" << endl;
      }
    }
    else if(option == 4){
      SetBudget(budget);
    }
    else if(option == 5){
      double totalincome = 0, totalexpense = 0,cash = 0, debit = 0, oct = 0;
      string week,date, search, max;
      int last,start_Date,start_Month, start_Year,current_Date;
      cout << "Choose the week you want to display (e.g. week 1, week 2, etc): " << endl;
      cout << "1. Week 1\n2. Week 2\n3. Week 3 \n4. Week 4\n5. Week 5\ninput: ";
      cin.ignore();
      getline(cin, week);
      cout << "Please enter the first date of " << week << "(ddmmyyyy): ";
      cin >> date;
      current_Date = stoi(date.substr(0,2));
      for (int i=0; i<7; i++){
        search = check_Date(date, current_Date);
        GetAllRecords( Records , search , totalexpense, totalincome, RecordCount, cash,  debit,  oct);
        current_Date++;
      }
      if (totalexpense == 0 && totalincome == 0) {
        cout << "There is no record in the file" << endl;
      }
      else{
        if (cash > debit && cash > oct){
          max = "Cash";
        }
        else if (debit > cash && debit > oct){
          max = "Debit";
        }
        else if (oct > debit && oct > cash){
          max = "Octopus";
        }
        ofstream fout;
        fout.open(week+date+".txt");
        if (fout.fail()){
          cout << "Fail to open " << week <<date<<".txt" << endl;
        }
        else{
          string answer;
          fout << "Your total income this week is HKD " << totalincome << endl;
          fout << "Your total expense this week is HKD " << totalexpense << endl;
          fout << "Summary of your expense this week: " << endl;
          fout << "Cash: HKD " << cash << endl;
          fout << "Debit: HKD " << debit << endl;
          fout << "Octopus: HKD " << oct << endl;
          fout << "Mostly used: " << max << endl;
          checkBudget(budget, totalexpense);
          cout << "Your statistical report has successfully made with name \"" << week <<date<<".txt\"" << endl;
          cout << "Do you want to see the report? (yes/no)";
          cin >> answer;
          if (answer == "yes") {
            printFile(week+date+".txt");
          }
          else if(answer == "no"){
            cout << "Okay then, you can see it in your document" << endl;
          }
          else {
            cout << "Your answer is not in the choices" << endl;
          }
        }
      }
    }//this closes the elif
  }//this closes the while
}
