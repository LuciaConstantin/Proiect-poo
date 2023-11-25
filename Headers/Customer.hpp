//
// Created by Lucia on 11/24/2023.
//

#ifndef OOP_CUSTOMER_HPP
#define OOP_CUSTOMER_HPP

#include <iostream>
#include <vector>
#include "Person.hpp"
#include <memory>

class Customer : public Person {
private:
    std::string registrationDate;
public:
    Customer() = default;
    virtual ~Customer() = default;
    Customer(const std::string &firstName, const std::string &lastName, const std::string &email,
             const std::string &telephoneNumber, const std::string &id, const std::string &registrationDate);
    void display() override;
    void insertPerson(std::vector<std::shared_ptr<Person>> &Persons) override ;
};



#endif //OOP_CUSTOMER_HPP
