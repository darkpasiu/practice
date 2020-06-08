#include "date.hpp"
#include <iostream>

// Date constructor
Date::Date(int year, int month, int day)
{
    SetDate(year, month, day);
}
 
// Date constructor
Date::Date()
{
    SetDate(0, 0, 0);
}
 
// Date member function
void Date::SetDate(int year, int month, int day)
{
    m_month = month;
    m_day = day;
    m_year = year;
}

// Date member function
bool Date::leapYear()
{
    //std::cout << m_year << std::endl;
    //std::cout << m_year % 4 << std::endl;
    bool isLeapYear = false;

    if ( m_year % 4 == 0 )
        isLeapYear = true;
    else
        isLeapYear = false;

    return isLeapYear;
}

