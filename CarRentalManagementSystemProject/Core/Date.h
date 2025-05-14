#ifndef DATE_H
#define DATE_H
#include "Time.h"

class Date {
private:
    int day;        // day
    int month;      // month
    int year;       // year
    Time time;      // time
public:
    Date();                // regular constructor
    Date(int, int, int);   // constructor with arguments
    Date(const Date&);     // copy constructor
    ~Date();               // destructor

    void setDate(int, int, int, int, int, int);      // function to set the date
    int getDay() const;             // function to get the day
    int getMonth() const;          // function to get the month
    int getYear() const;            // function to get the year
    void printDate() const;         // function to print the date
};

#endif  // DATE_H