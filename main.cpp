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
#include "Headers/Menu.hpp"
//#include "../Headers/Exceptions.hpp"
#include <stdexcept>
#include "Headers/ResourceFactory.hpp"
#include "Headers/Reservation.hpp"

///library management system


int main() {
    Book b;
    std::vector<Book> books;
    b.readFromFile(books);
    ////--------------------------------------------------------
    Customer c;
    std::vector<std::shared_ptr<Person>> customers;
    c.CustomersFromFile(customers);
    ///----------------------------------------------------
    Employee e;
    std::vector<std::shared_ptr<Person>> p2;
    e.employeesFromFile(p2);
    ///-------------------------------------------------
    Sponsor s;
    std::vector<std::shared_ptr<Person>> sponsors;
    s.sponsorsFromFile(sponsors);
    ///-------------------------------------------------
    std::shared_ptr<Hall> h;
    std::vector<std::shared_ptr<Hall>> halls;
    h->hallsFromFile(halls);
    ///--------------------------------------------------
    std::vector<WaitingList::PersonBookPair> observers;
    ///----------------------------------------------------
    Menu* M=Menu ::getInstance();
    M->displayMenu(customers, books, p2, sponsors,halls, observers);






    return 0;
}
