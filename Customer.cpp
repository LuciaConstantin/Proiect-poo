//
// Created by Lucia on 11/24/2023.
//

#include "Customer.hpp"
#include <fstream>

Customer::Customer(const std::string &firstName, const std::string &lastName, const std::string &email,
         const std::string &telephoneNumber, const std::string &id, const std::string &registrationDate)
        : Person(firstName, lastName, email, telephoneNumber, id),
          registrationDate(registrationDate) { }
void Customer::display() {
    Person::display();
    std::cout << " Registration date: " << registrationDate << std::endl;
}
void Customer::insertPerson(std::vector<std::shared_ptr<Person>> &Persons) {
    std::cout << "Customer insert " << std::endl;
    std::string lastName, firstName, email, phoneNumber, id, registrationDate;
    std::cout << "Last name: ";
    std::cin >> lastName;
    std::cout << "First name: ";
    std::cin >> firstName;
    std::cout << "Email: ";
    std::cin >> email;
    std::cout << "Phone number: ";
    std::cin >> phoneNumber;
    std::cout << "ID: ";
    std::cin >> id;
    std::cout << "Registration date: ";
    std::cin >> registrationDate;

/* Customer* newCustomer = new Customer(firstName, lastName, email, phoneNumber, id, registrationDate);
 Persons.push_back(newCustomer);*/
    std::shared_ptr<Person> newCustomer = std::make_shared<Customer>(firstName, lastName, email, phoneNumber, id, registrationDate);
    Persons.push_back(newCustomer);
    std::ofstream c("client.in", std::ios::app);
    if (c) {
        c << '\n' <<lastName << '\n' << firstName << '\n' << email << '\n' << phoneNumber <<'\n'<< id<<'\n' << registrationDate << '\n';
    c.close();}
    else {
    std::cerr << "Can't find the file" << std::endl;}

}