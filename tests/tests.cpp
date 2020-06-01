#include <iostream>
#include "../src/date.hpp"
#include <gtest/gtest.h>

using namespace std;

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
	
    cout << "dzien dobry, nakurwiam testy, nie cykaj, zaraz cos sie zjebie ^^" << endl;
	
    return 0;
}
