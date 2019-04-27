#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <sstream>

using namespace std;


struct Record {
    string date;
    string amount;
    string type;
    string account;
    string category;

};
int databasesize = 100;
Record* Records = new Record[databasesize]; // a dynamic array pointed by Records

#endif //MICHAELPROJECT_STRUCTRECORD_H
