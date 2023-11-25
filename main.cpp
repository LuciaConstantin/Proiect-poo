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
#include "Book.hpp"
#include "Person.hpp"
#include "Customer.hpp"
#include "Employee.hpp"
#include "Sponsor.hpp"
#include "LoanHistory.hpp"
#include "Exceptions.hpp"
///library management system



int main() {
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
        getline (f,ID);

    }
    f.close();

    for (const Book &cart: books)
        std::cout << cart << std::endl;
    std::ifstream c("client.in");
    if (!c) {
        std::cerr << "Can't open the file " << std::endl;
        return 1;
    }
    ////--------------------------------------------------------
    std::string lastName, firstName, email, phoneNumber, id, date;
   // std::vector<shared_ptr<Person>> Persons;
    std::vector<std::shared_ptr<Person>> p1;
    //std::vector<Customer> Customers;
    while (getline(c, firstName)) {
        getline(c, lastName);
        getline(c, email);
        getline(c, phoneNumber);
        getline(c, id);
        getline(c, date);

        std::shared_ptr<Person> newCustomer = std::make_shared<Customer>(firstName, lastName, email, phoneNumber, id, date);
        p1.push_back(newCustomer);

        getline(c, date);
    }
    c.close();
    /*for (const auto &person : p1) {
        person->display();
    }
    Customer newCust;
    //newCust.insertPerson(p1);

    for (const auto &person : p1) {
        person->display();
    }*/
///----------------------------------------------------
    std::ifstream a("angajati.in");
    std::string lastNameEmp, firstNameEmp, CNP, address, emailAng, phoneNr, position, data_ang, id_emp;
    int salary;
   // std::vector<Employee> employees;
    std::vector<std::shared_ptr<Person>> p2;
    while (getline(a, firstNameEmp)) {
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
        std::shared_ptr<Person> newEmployee=std::make_shared<Employee>(lastNameEmp, firstNameEmp, emailAng, phoneNr, id_emp, CNP, address, position, data_ang,
                             salary);

        p2.push_back(newEmployee);
        getline(a,id_emp);
    }
    a.close();
    std::cout << std::endl;
   /* for (const auto &person : p2) {
        person->display();
    }
    Employee newEmp;
   // newEmp.insertPerson(p2);

    for (const auto &person : p2) {
        person->display();
    }*/
///-------------------------------------------------
    std::ifstream s("sponsor.in");
    std::string lastNamespon, firstNamespon, emailspon, nrtel, idspon, dontype, dondate, donquant;
    std::vector<std::shared_ptr<Person>> p3;
    while (getline(s, firstNamespon)) {
        getline(s, lastNamespon);
        getline(s, emailspon);
        getline(s, nrtel);
        getline(s, idspon);
        getline(s, dontype);
        getline(s, dondate);
        getline(s, donquant);

        std::shared_ptr<Person> newSponsor=std::make_shared<Sponsor>(lastNamespon, firstNamespon, emailspon, phoneNr, idspon,dontype,dondate,donquant);
        p3.push_back(newSponsor);

        getline(s, id);

    }
    s.close();
   /* std::cout << std::endl;
    for (const auto &person : p3) {
        person->display();
    }
    Sponsor newSpon;
    //newSpon.insertPerson(p3);

    for (const auto &person : p3) {
        person->display();
    }*/
    LoanHistory lh;
    //lh.addLoan(p1,books);
    /*Employee emp;
    std::vector<std::shared_ptr<Employee>> employees;
    for (const auto& personPtr : p2)
        if (auto employeePtr = std::dynamic_pointer_cast<Employee>(personPtr))
            employees.push_back(employeePtr);
    try{
    emp.modifEmployee(employees);
    }
    catch(std::exception& e) {
        std::cout << e.what() << '\n';
    }
    std::cout<<std::endl<<"Merge in continuare"<<std::endl;*/

    return 0;
}
