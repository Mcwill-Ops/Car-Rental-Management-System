#include <iostream>
#include "Date.h"

// regular constructor
Date::Date()
    :day(0), month(0), year(0) {
}

// constructor with arguments
Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

// copy constructor
Date::Date(const Date& anotherObject) {
    this->day = anotherObject.day;
    this->month = anotherObject.month;
    this->year = anotherObject.year;
    this->time = anotherObject.time;
}

// destructor
Date::~Date() {
    //Does nothing
}

int Date::getDay() const { return day; }     // function to get the day
int Date::getMonth() const { return day; }   // function to get the month
int Date::getYear() const { return day; }       // function to get the year

// function to set the date
void Date::setDate(int day, int month, int year, int hour, int minute, int second) {
    this->day = day;
    this->month = month;
    this->year = year;
    time.setTime(hour, minute, second);
};

// function to print the date
void Date::printDate() const {
    std::cout << day << "/" << month << "/" << year << " ";
    time.printTime();
}


