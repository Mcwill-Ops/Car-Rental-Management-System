#include "LuxuryCar.h"
#include <iostream>

// default constructor
LuxuryCar::LuxuryCar()
    :Car() {
    type = "Luxury Car";
}

// regular constructor
LuxuryCar::LuxuryCar(int id)
    :Car(id) {
    type = "Luxury Car";

}

// copy constructor
LuxuryCar::LuxuryCar(const LuxuryCar& anotherObject)
    :Car(anotherObject) {

}

// print (overriden function)
void LuxuryCar::print() const {
    std::cout << "Car id: " << id << " type: " << type << std::endl;
    std::cout << "Rental date: ";
    rentalDate.printDate();
    std::cout << "Return date: ";
    returnDate.printDate();
}

// destructor
LuxuryCar::~LuxuryCar() {
    // Does nothing
}
