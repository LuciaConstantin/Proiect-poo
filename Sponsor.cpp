//
// Created by Lucia on 11/24/2023.
//

#include "Sponsor.hpp"

Sponsor::Sponsor(const std::string &firstName, const std::string &lastName, const std::string &email,
        const std::string &telephoneNumber, const std::string &id, const std::string &donationType,
        const std::string &donationDate, const std::string &quantity) : Person(firstName, lastName, email,telephoneNumber, id),donationType(donationType),donationDate(donationDate),quantity(quantity) {}

void Sponsor::display(){
    Person::display();
    std::cout << " Donation type: " << donationType << " Donation date: " << donationDate << "Donation quantity: "<<quantity<<std::endl;
}
void Sponsor::insertPerson(std::vector<std::shared_ptr<Person>> &Persons){
    std::cout << "Sponsor insert" << std::endl;
    std::string lastNameSpo, firstNameSpo, emailSpo, phoneNumberSpo, idSpo, donTypeSpo, donDateSpo, donquantSpo ;
    std::cout << "Last name: ";
    std::cin >> lastNameSpo;
    std::cout << "First name: ";
    std::cin >> firstNameSpo;
    std::cout << "Email: ";
    std::cin >> emailSpo;
    std::cout << "Phone number: ";
    std::cin >> phoneNumberSpo;
    std::cout << "ID: ";
    std::cin >> idSpo;
    std::cout << "Donation type: ";
    std::cin >> donTypeSpo;
    std::cout << "Donation date: ";
    std::cin >> donDateSpo;
    std::cout << "Donation quant: ";
    std::cin >> donquantSpo;

    std::shared_ptr<Person> newSponsor = std::make_shared<Sponsor>(firstNameSpo, lastNameSpo, emailSpo, phoneNumberSpo, idSpo, donTypeSpo, donDateSpo, donquantSpo);
    Persons.push_back(newSponsor);
    std::ofstream c("sponsor.in", std::ios::app);
    if (c) {
    c <<lastNameSpo << '\n' << firstNameSpo << '\n' << emailSpo << '\n' << phoneNumberSpo <<'\n'<< idSpo<<'\n' << donTypeSpo<<'\n' << donDateSpo<<'\n' <<donquantSpo<< '\n';
    c.close();
    } else {
    std::cerr << "Can't find the file" << std::endl;
    }
}