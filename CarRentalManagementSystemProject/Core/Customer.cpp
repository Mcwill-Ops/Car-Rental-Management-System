#include "Customer.h"
#include <iostream>

// default constructor
Customer::Customer()
    :id(0), name(""), address(""), telNumber(""), maxNumCar(10) {
    cars = new Car * [maxNumCar];
    for (int i = 0; i < maxNumCar; i++) {
        cars[i] = nullptr;
    }
    numCars = 0;
}

// regular constructor
Customer::Customer(int id, std::string name, std::string address, std::string telNumber)
    :maxNumCar(10) {
    this->id = id;
    this->name = name;
    this->address = address;
    this->telNumber = telNumber;
    cars = new Car * [maxNumCar];
    for (int i = 0; i < maxNumCar; i++) {
        cars[i] = nullptr;
    }
    numCars = 0;
}

// copy constructor
Customer::Customer(const Customer& anotherObject)
    :maxNumCar(10) {
    this->id = anotherObject.id;
    this->name = anotherObject.name;
    this->address = anotherObject.address;
    this->telNumber = anotherObject.telNumber;
    cars = new Car * [maxNumCar];
    for (int i = 0; i < maxNumCar; i++) {
        cars[i] = anotherObject.cars[i];     
    }
    this->numCars = anotherObject.numCars;
}

//destructor
Customer::~Customer() {             //  need to delete each object and delete the array itself
    for (int i = 0; i < maxNumCar; i++) {
        delete cars[i];
    }
    delete[] cars;
}


// setters
void Customer::setName(int name) { this->name = name; }
void Customer::setAddress(std::string address) { this->address = address; }
void Customer::setTelNumber(std::string telNumber) { this->telNumber = telNumber; }


// getters
int Customer::getId() const { return id; }
std::string Customer::getName() const { return name; }
std::string Customer::getAddress() const { return address; }
std::string Customer::getTelNumber() const { return telNumber; }
int Customer::getNumCars() const { return numCars; }

// fucntion to rent a car
void Customer::rentCar(Car* car, int rentalDay, int rentalMonth, int rentalYear, int rentalHour, int rentalMinute, int rentalSecond
    , int returnDay, int returnMonth, int returnYear, int returnHour, int returnMinute, int returnSecond) {
    if (numCars < maxNumCar) {
        if (car->getAvailable()) {
            cars[numCars] = car;
            numCars++;
            car->setAvailability(false);
            car->setRentalDate(rentalDay, rentalMonth, rentalYear, rentalHour, rentalMinute, rentalSecond);
            car->sentReturnDate(returnDay, returnMonth, returnYear, returnHour, returnMinute, returnSecond);
            return;
        }
        else {
            std::cout << car->getId() << ": is not available for rental" << std::endl;
        }
    }
    else {
        std::cout << "Number of car you can rent has been exceeded" << std::endl;
    }
}


// function to return a car
void Customer::returnCar(Car* car) {
    for (int i = 0; i < numCars; i++) {
        if (cars[i]->getId() == car->getId()) {
            for (int j = i; j < numCars - 1; j++) {
                cars[j] = cars[j + 1];
            }
            numCars--;
            car->setAvailability(true);
            std::cout << car->getId() << " returned successfully" << std::endl;
            car->setRentalDate(0, 0, 0, 0, 0, 0);                    // reset rental date
            car->sentReturnDate(0, 0, 0, 0, 0, 0);                       // reset return date
            return;
        }
    }
    std::cout << car->getId() << ": Not found to be returned" << std::endl;
}


// function to list cars
void Customer::listCars() const {
    for (int i = 0; i < numCars; i++) {
        cars[i]->print();
        std::cout << std::endl;
    }
}

bool Customer::searchCar(const Car* car) const {
    for (int i = 0; i < numCars; i++) {
        if (cars[i]->getId() == car->getId()) {
            return true;
        }
    }
    return false;
}
