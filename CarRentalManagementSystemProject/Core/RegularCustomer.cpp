#include "RegularCustomer.h"
#include <iostream>


// default constructor
RegularCustomer::RegularCustomer()
    :Customer() {
}

// regualr constructor
RegularCustomer::RegularCustomer(int id, std::string name, std::string address, std::string telNumber)
    :Customer(id, name, address, telNumber) {
}

// copy constructor
RegularCustomer::RegularCustomer(const RegularCustomer& anotherObject)
    :Customer(anotherObject) {
}


// destructor
RegularCustomer::~RegularCustomer() {
    // does nothing
}

// overriden function
void RegularCustomer::print() const {
    std::cout << "Customer ID: " << id << std::endl << "Name: " << name << std::endl << std::endl;
    listCars();
}
