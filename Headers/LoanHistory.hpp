//
// Created by Lucia on 11/24/2023.
//

#ifndef OOP_LOANHISTORY_HPP
#define OOP_LOANHISTORY_HPP
#include <iostream>
#include <memory>
#include <fstream>
#include "Book.hpp"
#include "Person.hpp"
#include "Customer.hpp"
#include <algorithm>
#include <chrono>
#include <ctime>
#include <fstream>
#include "../Headers/WaitingList.hpp"

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
    void addLoan(std::vector<std::shared_ptr<Person>> &Persons, std::vector<Book> &books);
    using PersonBookPair = std::tuple<std::shared_ptr<ConcretePerson>, Book>;
    void returnBook(std::vector<Book> &books,const std::vector<PersonBookPair> &observers);
    void display();



};


#endif //OOP_LOANHISTORY_HPP
