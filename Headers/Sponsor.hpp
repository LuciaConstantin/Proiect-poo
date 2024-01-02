//
// Created by Lucia on 11/24/2023.
//

#ifndef OOP_SPONSOR_HPP
#define OOP_SPONSOR_HPP
#include <memory>
#include <iostream>
#include "Person.hpp"
#include <fstream>
#include <string>
#include "../Headers/Book.hpp"

class Sponsor : public Person {
private:
    std::string donationType;
    std::string donationDate;
    std::string quantity;
    static int collectedAmount;
public:
    Sponsor() = default;

    virtual ~Sponsor() = default;

    Sponsor(const std::string &firstName, const std::string &lastName, const std::string &email,
            const std::string &telephoneNumber, const std::string &id, const std::string &donationType,
            const std::string &donationDate, const std::string &quantity) ;

    void display() override;
    void insertPerson(std::vector<std::shared_ptr<Person>> &Persons) override;
   // static int getCollectedAmount();
   void sponsorsFromFile(std::vector<std::shared_ptr<Person>> &sponsors);

};


#endif //OOP_SPONSOR_HPP
