//
// Created by Lucia on 11/24/2023.
//

#include "../Headers/LoanHistory.hpp"
#include <memory>


LoanHistory::LoanHistory(const std::string &loanDate, const std::string &returnDate, const std::shared_ptr<Book> &book,
                         const std::shared_ptr<Person> &customer) : loanDate(loanDate), returnDate(returnDate),
                                                                    book(book),
                                                                    customer(customer) {}
const std::string &LoanHistory::getReturnDate() const {
    return returnDate;
}

std::shared_ptr<Person>LoanHistory::getCustomers() const {
    return customer;
}


void LoanHistory::display()
{
    std::cout << "Loan Date: " << loanDate << std::endl;
    std::cout << "Return Date: " << returnDate << std::endl;
    std::cout << "Book Title: " << book->getTitle() << std::endl;
    std::cout << "Customer last name: " << customer->getFirstName() <<std::endl;
    std::cout << "Customer first name: " << customer->getLastName() << std::endl;
}

void LoanHistory::addLoan(std::vector<std::shared_ptr<Person>> &Persons, std::vector<Book> &books) {
    ///interactive part, with console
    std::ofstream f("loanHistory.in", std::ios::app);
    std::string firstNameCust, lastNameCust, bookTitle;
    std::cout << "Adding a loan " << std::endl;
    std::cout << "Customer name" << std::endl;
    std::cout << "Customer last name: ";
    std::getline(std::cin, lastNameCust);
    std::cout << "Customer first name:";
    std::getline(std::cin, firstNameCust);
    std::cout << "Book title: ";
    std::getline(std::cin, bookTitle);

    ///finding out if the customer and the book already exists, if not we can't proceed with the loan
    auto foundCustomer = std::find_if(Persons.begin(), Persons.end(),
                                      [&](const std::shared_ptr<Person> &p) {
                                          return p->getFirstName() == firstNameCust && p->getLastName() == lastNameCust;});
    auto foundBook = std::find_if(books.begin(), books.end(),
                                  [&](const Book &c) {
                                      return c.getTitle() == bookTitle;});///returns the an interator to the first correct value


    ///Finding the current date and adding it automatically into the file
    auto current = std::chrono::system_clock::now();
    auto now_timet = std::chrono::system_clock::to_time_t(current);
    auto date = localtime(&now_timet);
    int year_start = date->tm_year + 1900; ///tm_year represents the number of years starting from 1900
    int month_start = date->tm_mon + 1;
    int day_start = date->tm_mday;

    time_t epoch = std::mktime(date);
    epoch += (60*60*24*21);
    auto date_return=localtime(&epoch);
    int year_return = date_return->tm_year + 1900;
    int month_return = date_return->tm_mon + 1;
    int day_return = date_return->tm_mday;

    /*int foundCustomer;
    foundCustomer=customer->searchPerson(Persons,lastNameCust, firstNameCust);*/

    if (foundCustomer != Persons.end()  && foundBook != books.end() && foundBook->getAvailability() == "disponibila") {
        f<<std::endl;
        f <<lastNameCust << "\n" << firstNameCust << "\n" << bookTitle << "\n" << day_start << "." << month_start << "." << year_start<< "\n"<<
        day_return<<"."<<month_return<<"."<<year_return;
        foundBook->setAvailability("imprumutata");
        std::cout<<"The book has been successfully rented "<<std::endl;
    }
    else if (foundCustomer == Persons.end() && foundBook->getAvailability() == "disponibila") {
        customer = std::make_shared<Customer>();
        Persons.push_back(customer);
        std::shared_ptr<Customer> customerDowncast = std::dynamic_pointer_cast<Customer>(customer);
        customerDowncast->insertPerson(Persons);
        f<<std::endl;
        f << lastNameCust << "\n" << firstNameCust << "\n" << bookTitle << "\n" << day_start << "." << month_start << "." << year_start<< "\n"<<
          day_return<<"."<<month_return<<"."<<year_return<<'\n';
        foundBook->setAvailability("imprumutata");
        std::cout<<"The book has been successfully rented "<<std::endl;

    }
    else if (foundBook != books.end() &&foundBook->getAvailability() != "disponibila")
        std::cout << "The book is not available at the moment";
    else
        std::cout << "The book that was added was not found" << std::endl;

    f.close();
}

void LoanHistory::returnBook(std::vector<Book> &books){
    std::string lastNameCust, firstNameCust, bookTitle;
    std::cout<<"Book return"<<std::endl;
    std::cout << "Customer name" << std::endl;
    std::cout << "Customer last name: ";
    std::getline(std::cin, lastNameCust);
    std::cout << "Customer first name:";
    std::getline(std::cin, firstNameCust);
    std::cout << "Book title: ";
    std::getline(std::cin, bookTitle);


    ///i need to compare the data of return with the current data
    auto current = std::chrono::system_clock::now();
    auto now_timet = std::chrono::system_clock::to_time_t(current);
    auto date = localtime(&now_timet);
    int year = date->tm_year + 1900; ///tm_year represents the number of years starting from 1900
    int month = date->tm_mon + 1;
    int day = date->tm_mday;

    int ok=1;
    std::ifstream l("loanHistory.in");
    std::string firstNameL,lastNameL, bookTitleL, loanDateL, returnDateL;
    while(getline(l,lastNameL))
    {
        ok=1;
        getline(l, firstNameL);
        getline(l, bookTitleL);
        getline(l, loanDateL);
        getline(l, returnDateL);

        if(lastNameL==lastNameCust && firstNameL==firstNameCust && bookTitleL==bookTitle)
        {
            ok=0;
            break;
        }
        getline(l,loanDateL);

    }
    if(ok==1)
        std::cout<<"The data that has been introduced doesn't exist";
    else
    {
        std::string ret = returnDateL;
        std::string delimiter = ".";
        std::string retDayStr = ret.substr(0, ret.find(delimiter));
        int retDay = std::stoi(retDayStr);

        size_t pos = ret.find(delimiter) + 1;
        std::string retMonthStr = ret.substr(pos, ret.find(delimiter, pos) - pos);
        int retMonth = std::stoi(retMonthStr);

        pos = ret.find(delimiter, pos) + 1;
        std::string retYearStr = ret.substr(pos);
        int retYear = std::stoi(retYearStr);
        auto foundBook = std::find_if(books.begin(), books.end(),
                                      [&](const Book &c) {
                                          return c.getTitle() == bookTitle;});
        foundBook->setAvailability("disponibila");

        if((retDay<day|| retDay==day) && (retMonth==month || retMonth-1== month) && retYear==year)
        {
            std::cout << "The return has successfully been completed";
        }
        else
        {
            std::cout<< "The customer needs to pay a fine of: ";
            if(retMonth==month)
                std::cout<<(day-retDay)<<"lei"<<std::endl;
            else if(retMonth!=month)
                std::cout<<(month-retMonth)*30+(day-retDay)<<" lei"<<std::endl;
        }
    }



}




