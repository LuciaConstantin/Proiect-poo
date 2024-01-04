//
// Created by Lucia on 11/26/2023.
//

#ifndef OOP_MENU_HPP
#define OOP_MENU_HPP
#include <iostream>
#include "../Headers/LoanHistory.hpp"
#include "../Headers/Sponsor.hpp"
#include "../Headers/Employee.hpp"
#include "../Headers/ResourceFactory.hpp"
#include "../Headers/Hall.hpp"
#include "../Headers/Reservation.hpp"

class Menu {
private:
    Sponsor newSpon;
    LoanHistory lh;
    Book bk;
    Customer cst;
    Employee emp;
    std::shared_ptr<Person> pers;
    std::shared_ptr<ResourceFactory> resourceFactory;
    Menu(const Sponsor &newSpon, const LoanHistory &lh, const Book &bk, const Customer &cst, const Employee &emp,
                                       const std::shared_ptr<Person> &pers);
    static Menu *instancePtr;

public:
    using PersonBookPair = std::tuple<std::shared_ptr<ConcretePerson>, Book>;
    void displayMenu();

    Menu(const Menu&) =delete;/// deleting copy constructor
    static Menu* getInstance();


};


#endif //OOP_MENU_HPP
