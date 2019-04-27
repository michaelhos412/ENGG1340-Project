#include "setbudget.h"
#include <iostream>
using namespace std;
void SetBudget(double &budget){
  cout << "Please enter your weekly budget (in HKD with 2 decimal places): ";
  cin >> budget;
  cout << "Your weekly budget has been set!! :D" << endl;
}
