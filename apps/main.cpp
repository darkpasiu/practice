#include <iostream>
#include "../src/date.hpp"

using namespace std;

int main()
{
    cout << "dzien dobry ^^" << endl;

    // memory leak
    char *x = new char[100];

    return 0;
} 
