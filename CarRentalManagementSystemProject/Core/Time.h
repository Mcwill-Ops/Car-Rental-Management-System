#ifndef TIME_H
#define TIME_H

class Time {
private:
    int hour;       // hours
    int minute;     // minutes
    int second;     //seconds
public:
    Time();                    // regular constructor
    Time(int, int, int);       // constructor with arguments
    Time(const Time&);         // copy constructor
    ~Time();                    // destructor

    void setTime(int, int, int);       // function to set hour, minutes and second
    int getHour() const;                // function ot get hour
    int getMinute() const;              // function to get minute
    int getSecond() const;             // function to get second

    void printTime() const;            // function to print the time
};


#endif //TIME_H