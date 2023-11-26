//
// Created by Lucia on 11/24/2023.
//

#include "../Headers/Book.hpp"
#include <iostream>
#include <vector>
#include <string>

int Book::counter = 0;

const std::string &Book::getTitle() const {
    return title;
}
/*Book::Book(const std::string &title, const std::string &author, const std::string &domain,
     const std::string &availability, const std::string &isbn, const std::string &language,
     const std::string &publishingHouse, int publishingYear, const std::string &ID) : title(title),author(author),domain(domain),availability(availability),ISBN(isbn),language(language),
                                                                                      publishingHouse(publishingHouse),publishingYear(publishingYear),id(++counter) { }*/
Book::Book(const std::string& title, const std::string& author, const std::string& domain,
           const std::string& availability, const std::string& isbn, const std::string& language,
           const std::string& publishingHouse, int publishingYear)
        : title(title), author(author), domain(domain), availability(availability),
          ISBN(isbn), language(language), publishingHouse(publishingHouse),
          publishingYear(publishingYear), ID(++counter) {}

std::ostream &operator<<(std::ostream &os, const Book &book) {
    os << "title: " << book.title << " author: " << book.author << " domain: " << book.domain
       << " availability: " << book.availability << " ISBN: " << book.ISBN << " language: " << book.language
       << " publishingHouse: " << book.publishingHouse << " publishingYear: " << book.publishingYear << " ID: "
       << book.ID << std::endl;
    return os;
}
void Book::bookInfo(const std::vector<Book> &books) {
    std::string bookTitle;
    std::cout << "For which Book do you want to find out the information: ";
    getline(std::cin, bookTitle);
    int i = 0;
    int ok = 0;
    for (const Book &cart: books) {
        if (cart.title == bookTitle)///std::strcmp
        {
            ok = 1;
            break;
        }
        i++;
    }

    if (ok == 0)
        std::cout << "The book is not found in the database" << std::endl;
    else {
        std::cout << "The book is found in the database and has the information: " << std::endl;
        std::cout << "title: " << books[i].title << " author: " << books[i].author << " domain: "
                  << books[i].domain
                  << " availability: " << books[i].availability << " ISBN: " << books[i].ISBN << " language: "
                  << books[i].language
                  << " publishingHouse: " << books[i].publishingHouse << " publishingYear: "
                  << books[i].publishingYear << " ID: "
                  << books[i].ID << std::endl;
    }
    std::cout<<std::endl;

}
void Book::booksAuthor(const std::vector<Book> &books) {
    std::cout << "Search the books based on the author " << std::endl;
    std::string authorName;
    getline(std::cin, authorName);
    int ok = 0;
    int i = 0;
    for (const Book &cart: books) {
        if (authorName == cart.author)///std::strcmp
        {
            std::cout << "The author " << authorName << " wrote: " << books[i].title << std::endl;
            ok = 1;
        }
        i++;
    }
    if (ok == 0)
        std::cout << "The author " << authorName << " doesn't exist in our library " << std::endl;
    std::cout<<std::endl;

}
Book::Book(const Book &c)
        : title(c.title), author(c.author), domain(c.domain), availability(c.availability),
          ISBN(c.ISBN), language(c.language), publishingHouse(c.publishingHouse),
          publishingYear(c.publishingYear),
          ID(c.ID) {
}
Book& Book::operator= (const Book &Book) {
    title = Book.title;
    author = Book.author;
    domain = Book.domain;
    availability = Book.availability;
    ISBN = Book.ISBN;
    language = Book.language;
    publishingHouse = Book.publishingHouse;
    publishingYear = Book.publishingYear;
    ID = Book.ID;
    return *this;
}

const std::string &Book::getAvailability() const {
    return availability;
}

void Book::setAvailability(const std::string &avail){
    Book::availability = avail;
}
void Book::setIsbn(const std::string &isbn) {
    ISBN = isbn;
}

void Book::setPublishingYear(int publishingyear) {
    Book::publishingYear = publishingyear;
}

///this function is used to change the book with a new one, the new book is identical with the one that was changed
void Book::changeBook(std::vector<Book> &books) {
    for (Book &book : books) {
        if (book.getAvailability() == "retrasa") {
            std::cout<<"This book "<<book.getTitle()<<" is not in a good condition and is going to be replaced with a new one from a different edition"<<std::endl;
            std::string isbn_new;
            int year;
            Book newBook = book;///copy
            newBook.setAvailability("disponibila");
            ++counter;
            newBook.ID = counter;
            std::cout<<"The new ISBN: ";
            std::cin>>isbn_new;
            newBook.setIsbn(isbn_new);
            std::cout<<"The new year: ";
            std::cin>>year;
            newBook.setPublishingYear(year);
            std::swap(book, newBook);///swap
        }
    }
    std::cout<<std::endl;
}
void Book::insertBook(std::vector<Book> & books)
{
    std::string bookTitleIns, authorIns, domainIns, availabilityIns, ISBNIns, languageIns, publishingHouseIns;
    int publishingYearIns;
    std::cout << "New book insert "<<std::endl;
    std::cout << "Book title: ";
    getline(std::cin, bookTitleIns);
    std::cout << "Author: ";
    getline(std::cin, authorIns);
    std::cout << "Domain: ";
    getline(std::cin, domainIns);
    std::cout << "Availability: ";
    std::cin >> availabilityIns;
    std::cout << "ISBN: ";
    std::cin >> ISBNIns;
    std::cout << "Language: ";
    std::cin >> languageIns;
    std::cout << "Publishing house: ";
    std::cin >> publishingHouseIns;
    std::cout <<" Publishing year: ";
    std::cin >>publishingYearIns;
    Book newBook(bookTitleIns,authorIns,domainIns,availabilityIns,ISBNIns,languageIns,publishingHouseIns, publishingYearIns);
    books.push_back(newBook);
    std::cout<<std::endl;
}


