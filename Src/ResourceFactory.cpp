//
// Created by Lucia on 12/15/2023.
//

#include "../Headers/ResourceFactory.hpp"
#include "../Headers/Book.hpp"
#include "../Headers/Hall.hpp"

std::shared_ptr<Resource> BookFactory::createResource() {
    std::string title, author, domain, availability, ISBN, language,publishingHouse;
    int publishingYear;
    // Get title and author from user input or any other source
    std::cout << "Enter book details:\n";
    std::cout << "Title: ";
    std::getline(std::cin, title);
    std::cout << "Author: ";
    std::getline(std::cin, author);
    std::cout << "Domain: ";
    std::getline(std::cin, domain);
    std::cout << "Availability: ";
    std::getline(std::cin, availability);
    std::cout << "ISBN: ";
    std::getline(std::cin, ISBN);
    std::cout << "Language: ";
    std::getline(std::cin, language);
    std::cout << "Publishing House: ";
    std::getline(std::cin, publishingHouse);
    std::cout << "Publishing Year: ";
    return std::make_shared<Book>(title, author, domain, availability, ISBN, language, publishingHouse, publishingYear);
}

std::shared_ptr<Resource> HallFactory::createResource() {
    std::string hallName, dimensions, openingHour, closingHour;
    int nrSeats;
    std::cout<<"Enter hall details:\n";
    std::cout << "Hall name: ";
    std::getline(std::cin, hallName);
    std::cout << "Dimensions : ";
    std::getline(std::cin, dimensions);
    std::cout << "Opening Hour: ";
    std::getline(std::cin, openingHour);
    std::cout << "Closing Hour: ";
    std::getline(std::cin, closingHour);
    std::cout <<"Number of seats: ";
    std::cin>>nrSeats;
    return std::make_shared<Hall>(hallName, nrSeats, dimensions, openingHour, closingHour);
}