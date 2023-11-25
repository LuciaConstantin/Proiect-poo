//
// Created by Lucia on 11/24/2023.
//

#ifndef OOP_BOOK_HPP
#define OOP_BOOK_HPP
#include <iostream>
#include <vector>

class Book {
private:
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
    const std::string &getTitle() const;
   /*Book(const std::string &title, const std::string &author, const std::string &domain,
         const std::string &availability, const std::string &isbn, const std::string &language,
         const std::string &publishingHouse, int publishingYear);*/
   Book(const std::string& title, const std::string& author, const std::string& domain,
        const std::string& availability, const std::string& isbn, const std::string& language,
        const std::string& publishingHouse, int publishingYear);

    friend std::ostream &operator<<(std::ostream &os, const Book &Book);
    void static bookInfo(const std::vector<Book> &books);
    void static booksAuthor(const std::vector<Book> &books);
    Book(const Book &c);
    Book &operator=(const Book &Book);

};


#endif //OOP_BOOK_HPP
