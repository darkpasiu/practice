#include <iostream>
#include "../src/date.hpp"

using namespace std;

int main()
{
    cout << "dzien dobry ^^" << endl;

    // memory leak
    char *x = new char[100];
    delete[] x;

    Date date(2020, 6, 4);
    date.leapYear();


    return 0;
} 
