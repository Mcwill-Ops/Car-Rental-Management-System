#ifndef CORPORATE_CUSTOMER_H
#define CORPORATE_CUSTOMER_H
#include "Customer.h"


class CorporateCustomer :public Customer {
    // No additional data members
public:
    CorporateCustomer();                                            // deafult constructor
    CorporateCustomer(int, std::string, std::string, std::string);            // regular constructor
    CorporateCustomer(const CorporateCustomer&);        // copy constructor
    ~CorporateCustomer();               // destructor              
    virtual void print() const;                        // overriden function
};

#endif      // CORPORATE_CUSTOMER_H
