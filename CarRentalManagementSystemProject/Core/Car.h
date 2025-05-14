#ifndef CAR_H
#define CAR_H
#include <string>
#include "Date.h"

class Car {
protected:
    int id;                 // car id
    std::string type;        //car type
    bool available;         // car availability
    Date rentalDate;        // car rental date
    Date returnDate;            // car return date
public:
    Car();                      // default constructor
    Car(int);               // regular constructor
    Car(const Car&);        // copy constructor
    virtual ~Car();             // destructor

    //setters
    void setType(std::string);               // function to set type
    void setAvailability(bool);                         // function to set availability
    void setRentalDate(int, int, int, int, int, int);           // function to set the rental date
    void sentReturnDate(int, int, int, int, int, int);          // function to set the return date

    //getters
    int getId() const;              // function to get the id
    std::string getType() const;                // function to get the type
    bool getAvailable() const;     // function to get the availability

    virtual void print() const = 0;      // pure virtual function (need to have implementation in the derived classes)
};


#endif   // CAR_H