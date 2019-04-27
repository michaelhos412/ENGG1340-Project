#include "printingfunctions.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void printFile(string filename){
    int counter = 0;
    ifstream fin;
    fin.open(filename);
    if (fin.fail()){
        cout << endl << "Fail to open " << filename << ", therefore it cannot be displayed" << endl;
        exit(1);
    }
    else{
        string line;
        while(getline(fin,line)){
            counter++;
            cout << line << endl;
        }
        if (counter == 0){
            cout << "There are No Records in The File" << endl;
        }
    }
    fin.close();
}

void printMenu(){ // function to print menu
  cout << "1. Add Record" << endl; // done
  cout << "2. Display Record" << endl; // almost done
  cout << "3. Edit Record(remove record)" << endl; // done
  cout << "4. Set Financial Budget" << endl; // do this last
  cout << "5. Statistical Report" << endl; // done
  cout << "0. Exit" << endl;
}

void printShow(){
  cout << "1. Sort by Amount" << endl;
  cout << "2. Sort by Type (displays all the records)" << endl;
  cout << "3. Filter by Type (displays only one type (i/e))" << endl; //only one type
  cout << "4. Sort by Account (displays all the records)" << endl;
  cout << "5. Filter by Account (displays only one type)" << endl;
  cout << "6. Sort by Category (displays all the records)" << endl;
  cout << "7. Filter by Category (displays only one type)" << endl;
}
