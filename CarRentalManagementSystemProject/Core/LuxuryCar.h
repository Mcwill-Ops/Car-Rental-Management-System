#ifndef LUXURY_CAR_H
#define LUXURY_CAR_H
#include "Car.h"

class LuxuryCar :public Car {
    // No additional data members
public:
    LuxuryCar();                        // default constructor
    LuxuryCar(int);                         // regular constructor
    LuxuryCar(const LuxuryCar&);            // copy constructor
    ~LuxuryCar();            // destructor

    virtual void print() const;           // print (overriden function)

};

#endif      // LUXURY_CAR_H