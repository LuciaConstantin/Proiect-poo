//
// Created by Lucia on 11/27/2023.
//

#ifndef OOP_RAREBOOKS_HPP
#define OOP_RAREBOOKS_HPP


#include "Book.hpp"

class RareBooks: public Book{
private:
    std::string historicalValue;
    std::string origin;
    std::string materials;
};


#endif //OOP_RAREBOOKS_HPP
