#include "checkbudget.h"
void checkBudget(double budget, double expense){
  if (budget == 0){
    cout << "You have not entered weekly budget!" << endl;
  }
  else if (expense > budget){
    cout << "ALERT : You have spent too much !!!" << endl;
    cout << "You exceed HKD " << (expense - budget) << " from your weekly budget" << endl;
    cout << "Better luck next week!!" << endl;
  }
  else{
    cout << "Congratulations!!! Your expense is HKD " << (budget - expense) << " below your weekly budget" << endl;
    cout << "Keep it on!!" << endl;
  }
}
