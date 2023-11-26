//
// Created by Lucia on 11/24/2023.
//

#ifndef OOP_BOOK_HPP
#define OOP_BOOK_HPP

#include <iostream>
#include <vector>

class Book{
protected:
    std::string title;
    std::string author;
    std::string domain;
    std::string availability;
    std::string ISBN;
    std::string language;
    std::string publishingHouse;
    int publishingYear = 0;///optional
    int ID;
    static int counter;

public:
    Book() = default;

    ~Book() = default;
    void display();
    const std::string &getTitle() const;

    Book(const std::string &title,const std::string &author,const std::string &domain,
         const std::string &availability,const std::string &isbn,const std::string &language,
         const std::string &publishingHouse,int publishingYear);


    const std::string &getAvailability() const;
        void static bookInfo(const std::vector<Book> &books);
    void static booksAuthor(const std::vector<Book> &books);

    Book(const Book &c);
    Book &operator=(const Book &Book);

    void setAvailability(const std::string &avail);
    void changeBook(std::vector<Book> &books);

    void setIsbn(const std::string &isbn);

    void setPublishingYear(int publishingyear);
    void insertBook(std::vector<Book> & books);

    friend std::ostream &operator<<(std::ostream &os, const Book &book);
};



#endif //OOP_BOOK_HPP
