#include "AddRecord.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include "structandglobals.h"
using namespace std;

void AddRecord(Record RecordList[] , int count){
  string date,amount;
  stringstream am;
  double amount_double;
  string type, account, category;
  cout << "Enter date (ddmmyyyy): ";
  cin >> date;
  cout << "Enter amount (in HKD with 2 decimal places): ";
  cin >> amount_double;
  am << fixed << setprecision(2) << amount_double; //
  amount = am.str();
  cout << "Enter type (e (expense)/ i (income)): ";
  cin >> type;
  while (true) {
    if (type == "i") break;
    else if (type == "e") break;
    else {
      cout << "Sorry, your input is wrong. Please try again!" << endl;
      cout << "Enter type to be displayed first (i/e): ";
      cin >> type;
    }
  }
  cout << "Enter account (c (cash) / d (debit) / o (octopus)): ";
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
  cout << "Enter category (f (food) / u (utilities) / t (transport) / o (others)): ";
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
  RecordList[count].date = date;
  RecordList[count].amount = amount;
  RecordList[count].type = type;
  RecordList[count].account = account;
  RecordList[count].category = category;
  ofstream fout;
  fout.open(date+".txt", ios::app);
  if (fout.fail()) {// ada yang salah disini
    cout << "Fail to open in add record" << date << ".txt " << endl;
  }
  else {
    fout << date << " " << amount << " " << type << " " << account << " " << category << endl;
    fout.close();
  }
}
