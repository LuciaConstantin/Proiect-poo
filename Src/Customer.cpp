//
// Created by Lucia on 11/24/2023.
//

#include "../Headers/Customer.hpp"
#include <fstream>

Customer::Customer (const std::string &firstName, const std::string &lastName, const std::string &email,
                    const std::string &telephoneNumber, const std::string &id, const std::string &registrationDate)
        : Person(firstName, lastName, email, telephoneNumber, id),
          registrationDate(registrationDate) {}

void Customer::display () {
    Person::display();
    std::cout << " Registration date: " << registrationDate << std::endl;
}

void Customer::insertPerson (std::vector<std::shared_ptr<Person>> &Persons) {
    std::cout << "Customer insert " << std::endl;
    std::string lastNameCust, firstNameCust, emailCust, phoneNumberCust, idCust, registrationDateCust;
    std::cout << "Last name: ";
    std::cin >> lastNameCust;
    std::cout << "First name: ";
    std::cin >> firstNameCust;
    std::cout << "Email: ";
    std::cin >> emailCust;
    std::cout << "Phone number: ";
    std::cin >> phoneNumberCust;
    std::cout << "ID: ";
    std::cin >> idCust;
    std::cout << "Registration date: ";
    std::cin >> registrationDateCust;

/* Customer* newCustomer = new Customer(firstName, lastName, email, phoneNumber, id, registrationDate);
 Persons.push_back(newCustomer);*/
    std::shared_ptr<Person> newCustomer = std::make_shared<Customer>(firstNameCust, lastNameCust, emailCust,
                                                                     phoneNumberCust, idCust, registrationDateCust);
    Persons.push_back(newCustomer);
    std::ofstream c("client.in", std::ios::app);
    if (c) {
        c << std::endl;
        c << lastNameCust << '\n' << firstNameCust << '\n' << emailCust << '\n' << phoneNumberCust << '\n' << idCust
          << '\n' << registrationDateCust;
        c.close();
    } else {
        std::cerr << "Can't find the file" << std::endl;
    }
    std::cout << std::endl;

}