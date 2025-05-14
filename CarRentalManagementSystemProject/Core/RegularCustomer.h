#ifndef REGULAR_CUSTOMER_H
#define REGULAR_CUSTOMER_H
#include "Customer.h"

class RegularCustomer :public Customer {
    // No additional data members
public:
    RegularCustomer();                                      // default constructor
    RegularCustomer(int, std::string, std::string, std::string);          // regualr constructor
    RegularCustomer(const RegularCustomer&);                // copy constructor
    ~RegularCustomer();                 // destructor        
    virtual void print() const;            // overriden function
};

#endif  // REGULAR_CUSTOMER_H