#ifndef DATE_H
#define DATE_H
 
class Date
{
    private:
        int m_year;
        int m_month;
        int m_day;
 
    public:
        Date();
        Date(int year, int month, int day);
 
        void SetDate(int year, int month, int day);
        void setYear(int year) { m_year = year; };
        void setMonth(int month) { m_month = month; };
        void setDay(int day)  { m_day = day; };

        bool leapYear();

        int getYear() { return m_year; };
        int getMonth() { return m_month; };
        int getDay()  { return m_day; };
};
 
#endif
