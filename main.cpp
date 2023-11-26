#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <cstring>
#include <string>
#include <chrono>
#include <ctime>
#include <memory>
#include <algorithm>
#include "Headers/Book.hpp"
#include "Headers/Person.hpp"
#include "Headers/Customer.hpp"
#include "Headers/Employee.hpp"
#include "Headers/Sponsor.hpp"
#include "Headers/LoanHistory.hpp"
#include "Headers/Exceptions.hpp"
//#include "../Headers/Exceptions.hpp"
#include <stdexcept>
///library management system



int main () {
    std::ifstream f("carte.in");
    if (!f) {
        std::cerr << "Can't open the file" << std::endl;
        return 1;
    }
    std::vector<Book> books;
    std::string title, author, domain, availability, ISBN, language, publishingHouse, ID;
    int publishingYear;
    while (getline(f, title)) {
        getline(f, author);
        getline(f, domain);
        getline(f, availability);
        getline(f, ISBN);
        getline(f, language);
        getline(f, publishingHouse);
        f >> publishingYear;
        f.ignore();//pt endline
        // getline(f, ID);

        Book newBook(title, author, domain, availability, ISBN, language, publishingHouse, publishingYear);
        books.push_back(newBook);
        getline(f, ID);

    }
    f.close();

    ////--------------------------------------------------------
    std::ifstream c("client.in");
    if (!c) {
        std::cerr << "Can't open the file " << std::endl;
        return 1;
    }

    std::string lastName, firstName, email, phoneNumber, id, date;
    std::vector<std::shared_ptr<Person>> customers;
    //std::vector<Customer> Customers;
    while (getline(c, firstName)) {
        getline(c, lastName);
        getline(c, email);
        getline(c, phoneNumber);
        getline(c, id);
        getline(c, date);

        std::shared_ptr<Person> newCustomer = std::make_shared<Customer>(firstName, lastName, email, phoneNumber, id,
                                                                         date);
        customers.push_back(newCustomer);

        getline(c, date);
    }
    c.close();
///----------------------------------------------------
    std::ifstream a("angajati.in");
    std::string lastNameEmp, firstNameEmp, CNP, address, emailAng, phoneNr, position, data_ang, id_emp;
    int salary;
    std::vector<std::shared_ptr<Person>> p2;

    while (getline(a, firstNameEmp)) {
        try {
            getline(a, lastNameEmp);
            getline(a, emailAng);
            getline(a, phoneNr);
            getline(a, id_emp);
            getline(a, CNP);
            getline(a, address);
            getline(a, position);
            getline(a, data_ang);
            a >> salary;
            a.ignore();

            std::shared_ptr<Person> newEmployee = std::make_shared<Employee>(firstNameEmp, lastNameEmp, emailAng,
                                                                             phoneNr, id_emp, CNP, address, position,
                                                                             data_ang, salary);

            p2.push_back(newEmployee);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        getline(a, id_emp);
    }

    a.close();

///-------------------------------------------------
    std::ifstream s("sponsor.in");
    std::string lastNamespon, firstNamespon, emailspon, nrtel, idspon, dontype, dondate, donquant;
    std::vector<std::shared_ptr<Person>> sponsors;
    while (getline(s, firstNamespon)) {
        getline(s, lastNamespon);
        getline(s, emailspon);
        getline(s, nrtel);
        getline(s, idspon);
        getline(s, dontype);
        getline(s, dondate);
        getline(s, donquant);

        std::shared_ptr<Person> newSponsor = std::make_shared<Sponsor>(lastNamespon, firstNamespon, emailspon, phoneNr,
                                                                       idspon, dontype, dondate, donquant);
        sponsors.push_back(newSponsor);

        getline(s, id);

    }
    s.close();
    std::cout << std::endl;

////-------------------books-----------------------------------------------------
    Book bk;
    for (const Book &cart: books)
        std::cout << cart << std::endl;
    bk.bookInfo(books);
    bk.booksAuthor(books);
    bk.insertBook(books);
    bk.changeBook(books);
    for (const Book &cart: books)
        std::cout << cart << std::endl;
    ///---------------------customers---------------------------------
    for (const auto &person: customers) {
        person->display();
    }
    Customer cst;
    cst.insertPerson(customers);
    cst.searchPers(customers);
    for (const auto &person: customers) {
        person->display();
    }
    ///-----------------------employees-----------------------------------
    Employee emp;
    for (const auto &person: p2) {
        person->display();
    }

    std::vector<std::shared_ptr<Employee>> employees;
    for (const auto &personPtr: p2)
        if (auto employeePtr = std::dynamic_pointer_cast<Employee>(personPtr))
            employees.push_back(employeePtr);
    try {
        emp.modifEmployee(employees);
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
    emp.insertPerson(p2);
    ////------------------------------sponsor----------------------------------------
    Sponsor newSpon;
    newSpon.insertPerson(sponsors);
    std::cout << std::endl << "The money that have been collected: " << newSpon.getCollectedAmount() << std::endl;
    for (const auto &person: sponsors) {
        person->display();
    }
    ///--------------------------------loanHistory---------------------------------------------
    LoanHistory lh;
    lh.addLoan(customers, books);
    lh.returnBook(books);


    return 0;
}
