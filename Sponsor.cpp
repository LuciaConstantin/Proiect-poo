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
    std::string lastName, firstName, email, phoneNumber, id, donType, donDate, donquant ;
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
    std::cout << "Donation type: ";
    std::cin >> donType;
    std::cout << "Donation date: ";
    std::cin >> donDate;
    std::cout << "Donation quant: ";
    std::cin >> donquant;

    std::shared_ptr<Person> newSponsor = std::make_shared<Sponsor>(firstName, lastName, email, phoneNumber, id, donType, donDate, donquant);
    Persons.push_back(newSponsor);
    std::ofstream c("sponsor.in", std::ios::app);
    if (c) {
    c <<lastName << '\n' << firstName << '\n' << email << '\n' << phoneNumber <<'\n'<< id<<'\n' << donType<<'\n' << donDate<<'\n' <<donquant<< '\n';
    c.close();
    } else {
    std::cerr << "Can't find the file" << std::endl;
    }

}