#include <iostream>
#include "Time.h"

// regular constructor
Time::Time()
    :hour(0), minute(0), second(0) {
}

// constructor with arguments
Time::Time(int h, int min, int sec)
    :hour(h), minute(min), second(sec) {
}

// copy constructor
Time::Time(const Time& anotherObject) {
    this->hour = anotherObject.hour;
    this->minute = anotherObject.minute;
    this->second = anotherObject.second;
}

// destructor
Time::~Time() {
    //Does nothing
}

int Time::getHour() const { return hour; }        // function to get hour
int Time::getMinute() const { return minute; }        // function to get minute
int Time::getSecond() const { return second; }       // function to get second

// function to set hour, minutes and second
void Time::setTime(int hour, int minute, int second) {
    this->hour = (hour >= 0 && hour < 24) ? hour : 0;
    this->minute = (minute >= 0 && minute < 60) ? minute : 0;
    this->second = (second >= 0 && second < 60) ? second : 0;
}

// function to print the time
void Time::printTime() const {
    std::cout << hour << ":" << minute << ":" << second << std::endl;
}
