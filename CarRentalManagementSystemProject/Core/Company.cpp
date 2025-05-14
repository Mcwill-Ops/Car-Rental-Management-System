#include "Company.h"
#include <iostream>


// default contructor
Company::Company()
    :name(""), address(""), email(""), telNumber(""), maxNumCars(1000) {
    cars = new Car * [maxNumCars];
    for (int i = 0; i < maxNumCars; i++) {
        cars[i] = nullptr;
    }
    numCars = 0;
}

// regular constructor
Company::Company(std::string name, std::string address, std::string email, std::string telNumber)
    :maxNumCars(1000) {
    this->name = name;
    this->address = address;
    this->email = email;
    this->telNumber = telNumber;
    cars = new Car * [maxNumCars];
    for (int i = 0; i < maxNumCars; i++) {
        cars[i] = nullptr;
    }
    numCars = 0;
}

// copy constructor
Company::Company(const Company& anotherObject)
    :maxNumCars(1000) {
    this->name = anotherObject.name;
    this->address = anotherObject.address;
    this->email = anotherObject.email;
    this->telNumber = anotherObject.telNumber;
    cars = new Car * [maxNumCars];
    for (int i = 0; i < maxNumCars; i++) {
        cars[i] = anotherObject.cars[i];
    }
    numCars = 0;
}

// destructor
Company::~Company() {
    for (int i = 0; i < maxNumCars; i++) {
        delete cars[i];
    }
    delete[]cars;
}


// setters
void Company::setName(std::string name) { this->name = name; }
void Company::setAddress(std::string address) { this->address = address; }
void Company::setEmail(std::string email) { this->email = email; }
void Company::setTelNumber(std::string telNumber) { this->telNumber = telNumber; }


// geters
std::string Company::getName() const { return name; }
std::string Company::getAddress() const { return address; }
std::string Company::getEmail() const { return email; }
std::string Company::getTelNumber() const { return telNumber; }


// subsytem to manage the array of cars
// function to add a car
void Company::addCar(Car* car) {
    if (numCars < maxNumCars) {
        cars[numCars] = car;
        numCars++;
        car->setAvailability(true);             // car is available int the company
        return;
    }
    std::cout << "Limit exceeded; impossible to add a car" << std::endl;
}
// function to remove a car
void Company::removeCar(Car* car) {
    for (int i = 0; i < numCars; i++) {
        if (cars[i]->getId() == car->getId()) {
            for (int j = i; j < numCars - 1; j++) {
                cars[j] = cars[j + 1];
            }
            numCars--;
            std::cout << car->getId() << " was removed successfully" << std::endl;
            car->setAvailability(false);                                                // car is not available in the company
            return;
        }
    }
}

// function to search a car
bool Company::searchCar(Car* car) const {
    for (int i = 0; i < numCars; i++) {
        if (cars[i]->getId() == car->getId()) {
            return true;
        }
    }
    return false;
}

// function to list cars
void Company::listCars() const {
    std::cout << "ID " << "  Type" << std::endl;


    for (int i = 0; i < numCars; i++) {
        std::cout << cars[i]->getId() << "  " << cars[i]->getType() << std::endl;
    }
}
