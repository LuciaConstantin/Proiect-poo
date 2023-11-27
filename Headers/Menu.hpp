//
// Created by Lucia on 11/26/2023.
//

#ifndef OOP_MENU_HPP
#define OOP_MENU_HPP
#include <iostream>
#include "../Headers/LoanHistory.hpp"
#include "../Headers/Sponsor.hpp"
#include "../Headers/Employee.hpp"

class Menu {
private:
    Sponsor newSpon;
    LoanHistory lh;
    Book bk;
    Customer cst;
    Employee emp;
    std::shared_ptr<Person> pers;

public:
    void displayMenu(std::vector<std::shared_ptr<Person>> &Customers, std::vector<Book> &books,
                     std::vector<std::shared_ptr<Person>> &Employees,std::vector<std::shared_ptr<Person>> &Sponsors);

    //Menu(const Sponsor &newSpon, const LoanHistory &lh, const Book &bk, const Customer &cst, const Employee &emp);

    Menu(const Sponsor &newSpon, const LoanHistory &lh, const Book &bk, const Customer &cst, const Employee &emp,
         const std::shared_ptr<Person> &pers);
};


#endif //OOP_MENU_HPP
