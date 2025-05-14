#ifndef STANDARD_CAR_H
#define STANDARD_CAR_H
#include "Car.h"

class StandardCar :public Car {
    // No additional data members
public:
    StandardCar();                      // default constructor
    StandardCar(int);                       // regular constructor
    StandardCar(const StandardCar&);      // copy constructor
    ~StandardCar();      // destructor

    virtual void print() const;      // print (overriden function)
};



#endif    // STANDARD_