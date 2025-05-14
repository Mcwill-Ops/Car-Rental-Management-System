#include "CorporateCustomer.h"
#include <iostream>


// deafult constructor
CorporateCustomer::CorporateCustomer()
    :Customer() {
}

// regular constructor
CorporateCustomer::CorporateCustomer(int id, std::string name, std::string address, std::string telNumber)
    :Customer(id, name, address, telNumber) {
}

// copy constructor
CorporateCustomer::CorporateCustomer(const CorporateCustomer& anotherObject)
    :Customer(anotherObject) {
}


// destructor 
CorporateCustomer::~CorporateCustomer() {
    // does nothing
}

// overriden function
void CorporateCustomer::print() const {
    std::cout << "Customer ID: " << id << std::endl << "Name: " << name << std::endl << std::endl;
    listCars();
}
