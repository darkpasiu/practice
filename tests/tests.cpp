#include <iostream>
#include "../src/date.hpp"
#include <gtest/gtest.h>

using namespace std;

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
	
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

TEST_F(DateTest, CheckFixtureConstructor1)
{
    EXPECT_TRUE(date->getYear() == 0);
    EXPECT_TRUE(date->getMonth() == 0);
    EXPECT_TRUE(date->getDay() == 0);
}

TEST_F(DateTest, CheckFixtureConstructor2)
{
    int year = 2020;
    int month = 6;
    int day = 12;

    date->SetDate(year, month, day);

    EXPECT_TRUE(date->getYear() == year);
    EXPECT_TRUE(date->getMonth() == month);
    EXPECT_TRUE(date->getDay() == day);
}

TEST_F(DateTest, CheckSetYear)
{
    int year = 2000;
    EXPECT_TRUE(date->getYear() == 0);

    date->setYear(year);
    EXPECT_TRUE(date->getYear() == year);
}

TEST_F(DateTest, CheckSetMonth)
{
    int month = 12;
    EXPECT_TRUE(date->getMonth() == 0);

    date->setMonth(month);
    EXPECT_TRUE(date->getMonth() == month);
}

TEST_F(DateTest, CheckSetDay)
{
    int day = 15;
    EXPECT_TRUE(date->getDay() == 0);

    date->setDay(day);
    EXPECT_TRUE(date->getDay() == day);
    // test failure
    EXPECT_TRUE(date->getDay() == 7);
}

TEST_F(DateTest, CheckLeapYear)
{
    int year = 2000;
    date->setYear(year);
    EXPECT_TRUE(date->leapYear() == true);

    year = 2001;
    date->setYear(year);
    EXPECT_TRUE(date->leapYear() == false);
}

