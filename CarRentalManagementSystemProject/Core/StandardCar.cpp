#include "StandardCar.h"
#include <iostream>


// default constructor
StandardCar::StandardCar()
    :Car() {
    type = "Standard Car";
}

// regular constructor
StandardCar::StandardCar(int id)
    :Car(id) {
    type = "Standard Car";

}

// copy constructor
StandardCar::StandardCar(const StandardCar& anotherObject)
    : Car(anotherObject) {
}


// print (overriden function)
void StandardCar::print() const {
    std::cout << "Car id: " << id << " type: " << type << std::endl;
    std::cout << "Rental date: ";
    rentalDate.printDate();
    std::cout << "Return date: ";
    returnDate.printDate();
}

// destructor
StandardCar::~StandardCar() {
    // Does nothing
}
