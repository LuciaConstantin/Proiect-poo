//
// Created by Lucia on 11/24/2023.
//

#include "LoanHistory.hpp"


LoanHistory::LoanHistory(const std::string &loanDate, const std::string &returnDate, const std::shared_ptr<Book> &book,
            const std::shared_ptr<Person> &customer) : loanDate(loanDate), returnDate(returnDate), book(book),
                                                       customer(customer) {}
void LoanHistory::addLoan(std::vector<std::shared_ptr<Person>> &Persons, const std::vector<Book> &books)
{
    ///interactive part, with console
    std::ofstream f("loanHistory.in",std::ios::app);
    std:: string firstNameCust,lastNameCust, bookTitle;
    std::cout<<"Customer name: "<<std::endl;
    std::cout<<"Customer last name:";
    std::getline(std::cin, lastNameCust);
    std::cout<<"Customer first name:";
    std::getline(std::cin, firstNameCust);
    std::cout<<"Book title: ";
    std::getline(std::cin, bookTitle);

    ///finding out if the customer and the book already exists, if not we can't proceed with the loan
    auto foundCustomer = std::find_if(Persons.begin(), Persons.end(),
                                      [&](const std::shared_ptr<Person> &p) {
                                          return p->getFirstName() == firstNameCust && p->getLastName() == lastNameCust;
                                      });
    auto foundBook = std::find_if(books.begin(), books.end(),
                                  [&](const Book &c) { return c.getTitle() == bookTitle; });
    ///Finding the current date and adding it automatically into the file
    auto current =std:: chrono::system_clock::now();
    auto now_timet = std::chrono::system_clock::to_time_t(current);
    auto date = localtime(&now_timet);
    int year= date->tm_year+1900;///tm_year represents the number of years starting from 1900
    int month= date->tm_mon+1;
    int day=date->tm_mday;
    if (foundCustomer != Persons.end() && foundBook != books.end())
    {
        f<<lastNameCust<<"\n"<<firstNameCust<<"\n"<<bookTitle<<"\n"<<day<<" "<<month<<" "<<year<<"\n";
    }
    else if (foundCustomer==Persons.end())
    {
        customer = std::make_shared<Customer>();
        Persons.push_back(customer);
        std::shared_ptr<Customer> customerDowncast = std::dynamic_pointer_cast<Customer>(customer);
        customerDowncast->insertPerson(Persons);
        f<<lastNameCust<<"\n"<<firstNameCust<<"\n"<<bookTitle<<"\n"<<day<<" "<<month<<" "<<year<<"\n";

    }
    else
        std::cout<<"The book or the customer that was added was not found"<<std::endl;

    f.close();
}