#include "Car.h"

// default constructor
Car::Car()
    :id(0), available(false) {
}

// regular constructor
Car::Car(int id)
    :available(false) {
    this->id = id;
}

// copy constructor
Car::Car(const Car& anotherObject) {
    id = anotherObject.id;
    type = anotherObject.type;
    available = anotherObject.available;
    rentalDate = anotherObject.rentalDate;
    returnDate = anotherObject.returnDate;
}

// destructor
Car::~Car() {
    // Does nothing
}

// setters
void Car::setType(std::string type) { this->type = type; }
void Car::setAvailability(bool available) { this->available = available; }

void Car::setRentalDate(int day, int month, int year, int hour, int minute, int second) {
    rentalDate.setDate(day, month, year, hour, minute, second);
}

void Car::sentReturnDate(int day, int month, int year, int hour, int minute, int second) {
    returnDate.setDate(day, month, year, hour, minute, second);
}

// getters
int Car::getId() const { return id; }
std::string Car::getType() const { return type; }
bool Car::getAvailable() const { return available; }

