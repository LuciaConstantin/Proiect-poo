//
// Created by Lucia on 11/24/2023.
//

#include "../Headers/Person.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include "../Headers/Exceptions.hpp"

const std::string &Person::getFirstName() const {
    return firstName;
}

const std::string &Person::getLastName() const {
    return lastName;
}

Person::Person(const std::string &firstName, const std::string &lastName, const std::string &email,
               const std::string &telephoneNumber, const std::string &id) : firstName(firstName), lastName(lastName),
                                                                            email(email),
                                                                            telephoneNumber(telephoneNumber), id(id) {}

void Person::display() {
    std::cout << "Last name: " << lastName << " First name: " << firstName << " Email: " << email
              << " Telephone number: " << telephoneNumber << " ID: " << id;
}

void Person::searchPers(const std::vector<std::shared_ptr<Person>> &Persons) {
    std::cout << "Searching for a person in the database " << std::endl;
    std::string lastName_pers, firstName_pers;
    std::cout << "Last Name: ";
    std::cin >> lastName_pers;
    std::cout << "First Name: ";
    std::cin >> firstName_pers;
    int ok=0;
    for (const auto &personPtr: Persons) {
        const Person &cli=*personPtr; // Dereference the shared pointer
        if (cli.getLastName() == lastName_pers && cli.getFirstName() == firstName_pers) {
            std::cout << lastName_pers << " " << firstName_pers << " is in the database" << std::endl;
            ok=1;
            break;
        }
    }
    if (ok == 0)
        std::cout << "This person is not in the database" << std::endl;
    std::cout << std::endl;
}

void Person::setFirstName(const std::string &fName) {
    Person::firstName = fName;
}

void Person::setLastName(const std::string &lName) {
    Person::lastName = lName;
}

void Person::setEmail(const std::string &eml) {
    Person::email = eml;
}

void Person::setTelephoneNumber(const std::string &telNumber) {
    Person::telephoneNumber = telNumber;
}

const std::string &Person::getEmail() const {
    return email;
}

const std::string &Person::getTelephoneNumber() const {
    return telephoneNumber;
}
/*int Person::searchPerson(std::vector<std::shared_ptr<Person>> &Persons, std::string LastName, std::string FirstName)
{
    auto foundCustomer = std::find_if(Persons.begin(), Persons.end(),
                                      [&](const std::shared_ptr<Person> &p) {
                                          return p->getFirstName() == FirstName && p->getLastName() == LastName;});
    if(foundCustomer != Persons.end())
        return 0;
    else
        return 1;
}*/