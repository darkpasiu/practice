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

// fixture
struct DateTest: testing::Test
{
	Date* date;
	DateTest()
	{
		date = new Date();
	}
	virtual ~DateTest()
	{
		delete date;
	}
};


TEST(ClassDate, CheckConstructor1)
{
    int year = 2020;
    int month = 6;
    int day = 12;

    Date date(year, month, day);

    EXPECT_TRUE(date.getYear() == year);
    EXPECT_TRUE(date.getMonth() == month);
    EXPECT_TRUE(date.getDay() == day);
}

TEST(ClassDate, CheckConstructor2)
{

    Date date;

    EXPECT_TRUE(date.getYear() == 0);
    EXPECT_TRUE(date.getMonth() == 0);
    EXPECT_TRUE(date.getDay() == 0);
}
