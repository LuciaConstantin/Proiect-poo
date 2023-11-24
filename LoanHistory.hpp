//
// Created by Lucia on 11/24/2023.
//

#ifndef OOP_LOANHISTORY_HPP
#define OOP_LOANHISTORY_HPP
#include <iostream>
#include <memory>
#include "Book.hpp"
#include "Person.hpp"
#include "Customer.hpp"
#include <algorithm>
#include <chrono>
#include <ctime>
#include <fstream>

class LoanHistory
{
private:
    std::string loanDate;
    std::string returnDate;
    std::shared_ptr<Book> book;
    std::shared_ptr<Person> customer;
public:
    LoanHistory(const std::string &loanDate, const std::string &returnDate, const std::shared_ptr<Book> &book,
                const std::shared_ptr<Person> &customer);

    LoanHistory()=default;
    ~LoanHistory()=default;
    void addLoan(std::vector<std::shared_ptr<Person>> &Persons, const std::vector<Book> &books);


};


#endif //OOP_LOANHISTORY_HPP
