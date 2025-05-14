#ifndef COMPANY_H
#define COMPANY_H
#include "Car.h"

class Company {
private:
    std::string name;        // company name
    std::string address;     // company address
    std::string email;           // company email
    std::string telNumber;               // company tel number
    Car** cars;             // list of cars of the company
    const int maxNumCars;         // max number of cars
    int numCars;                // keeps track of the number of cars
public:
    Company();                             // default contructor
    Company(std::string, std::string, std::string, std::string);         // regular constructor
    Company(const Company&);               // copy constructor
    ~Company();                             // destructor

    // setters
    void setName(std::string);
    void setAddress(std::string);
    void setEmail(std::string);
    void setTelNumber(std::string);

    // geters
    std::string getName() const;
    std::string getAddress() const;
    std::string getEmail() const;
    std::string getTelNumber() const;

    // subsytem to manage the array of cars
    void addCar(Car*);                     // function to add a car
    void removeCar(Car*);                  // function to remove a car
    bool searchCar(Car*) const;            // function to search a car
    void listCars() const;                 // function to list cars

};


#endif  //COMPANY_H