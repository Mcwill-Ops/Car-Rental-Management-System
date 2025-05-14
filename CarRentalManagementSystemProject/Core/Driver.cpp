/*
        SOME NOTES
        1- I have assumed that the maximum number of cars a customer can rent is 10
        2- For convenience I gave the same input for the car rental and return date for the rental process
*/

#include <iostream>
#include <string>
#include "LuxuryCar.h"
#include "StandardCar.h"
#include "RegularCustomer.h"
#include "CorporateCustomer.h"
#include "Company.h"


int main() {

    // object of class StandardCar class instantiated
    StandardCar* s1 = new StandardCar(101);
    StandardCar* s2 = new StandardCar(102);
    StandardCar* s3 = new StandardCar(103);

    // object of class LuxuryCar class instantiated
    LuxuryCar* l1 = new LuxuryCar(201);
    LuxuryCar* l2 = new LuxuryCar(202);
    LuxuryCar* l3 = new LuxuryCar(203);

    // object of class LuxuryCar class instantiated
    Company* c = new Company("CoenCars", "coencars@gmail.com", "Rue de Maisonneuve G2Y 1I8", "4587852655");



    // Add cars to the company
    c->addCar(s1);
    c->addCar(s2);
    c->addCar(s3);
    c->addCar(l1);
    c->addCar(l2);
    c->addCar(l3);
    std::cout << "======================= List of cars " << c->getName() << " company possess =======================" << std::endl << std::endl;
    c->listCars();      // list car of the company

    std::cout << std::endl;

    // removed some cars;
    c->removeCar(s1);
    c->removeCar(l1);

    std::cout << std::endl;


    // list cars of company after removal
    std::cout << "======================= List of cars" << c->getName() << " possess after removal =======================" << std::endl << std::endl;
    c->listCars();
    std::cout << std::endl;

    // search for a car
    if (c->searchCar(s1)) {                                 // Not in the company because it has been removed
        std::cout << s1->getId() << ": found" << std::endl;
    }
    else {
        std::cout << s1->getId() << ": not found" << std::endl;
    }

    if (c->searchCar(l3)) {                                       // available in the company
        std::cout << l3->getId() << ": found" << std::endl;
    }
    else {
        std::cout << l3->getId() << ": not found" << std::endl;
    }


    // object of class StandardCar class instantiated
    RegularCustomer* r1 = new RegularCustomer(1001, "Mcwill", "Loyola Campus H4B 1R6", "594 428 5824");
    CorporateCustomer* c1 = new CorporateCustomer(2001, "Concordia", "St Georges William H3G 1M8", "546 412 5416");

    std::cout << std::endl;

    // regular customer rents cars
    std::cout << "======================= " << r1->getName() << " rent cars list =======================" << std::endl << std::endl;
    r1->rentCar(s1, 14, 3, 2025, 10, 30, 45, 20, 5, 2025, 11, 59, 59);          // s1 cannot be rent because it's not in the company (it has been removed)
    r1->rentCar(s2, 14, 3, 2025, 10, 30, 45, 20, 5, 2025, 11, 59, 59);      // rent successfully
    r1->rentCar(l2, 14, 3, 2025, 10, 30, 45, 20, 5, 2025, 11, 59, 59);          // rent successfully

    r1->print();                        // print list of car of the regular customer
    std::cout << std::endl;

    // corporate customer rents cars
    std::cout << "======================= " << c1->getName() << " rent cars list =======================" << std::endl << std::endl;
    c1->rentCar(l2, 14, 3, 2025, 10, 30, 45, 20, 5, 2025, 11, 59, 59);      // l2 cannot be rent because it's not available for rental (regular customer already rent it)
    c1->rentCar(l3, 14, 3, 2025, 10, 30, 45, 20, 5, 2025, 11, 59, 59);      // rent successfully
    c1->rentCar(s3, 14, 3, 2025, 10, 30, 45, 20, 5, 2025, 11, 59, 59);      // rent successfully

    c1->print();                            // print list of car of the corporate customer
    std::cout << std::endl;

    // regular customer returned cars
    std::cout << "======================= " << r1->getName() << " returned cars =======================" << std::endl << std::endl;
    r1->returnCar(s1);                          // car not in the list of the regular customer (not in the company)
    r1->returnCar(l2);
    // l2 returned successfully
    std::cout << std::endl;


    std::cout << "======================= " << r1->getName() << " cars list after return =======================" << std::endl << std::endl;
    r1->print();                                        // posses car one car (s2)
    std::cout << std::endl;

    std::cout << "======================= " << c1->getName() << " returned cars =======================" << std::endl << std::endl;
    c1->returnCar(l3);                  // l3 returned successfully

    std::cout << std::endl;

    std::cout << "======================= " << c1->getName() << " cars list after return =======================" << std::endl << std::endl;
    c1->print();                                // posses 1 car (s3)              
    std::cout << std::endl;

    std::cout << "======================= " << r1->getName() << " rent cars list =======================" << std::endl << std::endl;
    r1->rentCar(l3, 14, 3, 2025, 10, 30, 45, 20, 5, 2025, 11, 59, 59);                  // rent successfully (because car has been returned by corporate customer)             
    r1->rentCar(s3, 14, 3, 2025, 10, 30, 45, 20, 5, 2025, 11, 59, 59);      // s3 cannot be rent because it's not available for rental (corporate customer still has it)

    r1->print();                        // posses 2 cars :s2 and l3
    std::cout << std::endl;


    std::cout << "======================= " << c1->getName() << " rent cars list =======================" << std::endl << std::endl;

    c1->rentCar(l2, 14, 3, 2025, 10, 30, 45, 20, 5, 2025, 11, 59, 59);          // rent successfully
    c1->rentCar(l3, 14, 3, 2025, 10, 30, 45, 20, 5, 2025, 11, 59, 59);          // cannot be rented (reglar customer has it)

    c1->print();                                // posses 2 cars: s3 and l2         
    std::cout << std::endl;

    // search if a customer has for a car

    if (c1->searchCar(s3)) {                                    // found in corporate car list
        std::cout << s3->getId() << ": found" << std::endl;
    }
    else {
        std::cout << s3->getId() << ": not found" << std::endl;
    }

    if (r1->searchCar(s3)) {                                       // not found because corporate customer has it
        std::cout << s3->getId() << ": found" << std::endl;
    }
    else {
        std::cout << s3->getId() << ": not found" << std::endl;
    }

    delete s1; delete s2; delete s3;
    delete l1; delete l2; delete l3;
    delete r1; delete c1;
    delete c;

    return 0;
}