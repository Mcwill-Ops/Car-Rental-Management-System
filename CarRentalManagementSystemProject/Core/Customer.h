#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Car.h"



// class Customer
// assumption that the number of car a customer can rent is 10
class Customer {
protected:
    int id;                     // customer id
    std::string name;            // customer name
    std::string address;                 // customer address
    std::string telNumber;                       // customer tel number
    const int maxNumCar;        // maximum number of car
    Car** cars;            // list of cars
    int numCars;            // keep track of the number of cars
public:
    Customer();                             // default constructor
    Customer(int, std::string, std::string, std::string);     // regular constructor
    Customer(const Customer&);          // copy constructor
    virtual ~Customer();                   //destructor

    // setters
    void setName(int);
    void setAddress(std::string);
    void setTelNumber(std::string);

    // getters
    int getId() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getTelNumber() const;
    int getNumCars() const;

    // subsytem to manage list of car
    void rentCar(Car*, int, int, int, int, int, int, int, int, int, int, int, int);        // function to rent car
    void returnCar(Car*);                                                          // function to return car
    void listCars() const;                                                      // function to list car
    bool searchCar(const Car*) const;                      // function to search car

    // print function
    virtual void print() const = 0;              // pure virtual function

};

#endif      // CUSTOMER_H
