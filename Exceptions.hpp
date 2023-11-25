//
// Created by Lucia on 11/24/2023.
//

#ifndef OOP_EXCEPTIONS_HPP
#define OOP_EXCEPTIONS_HPP
#include <stdexcept>
#include <iostream>

class exceptionSalary: public std::exception {
public:
    const char* what() const noexcept override{
        return ("The salary should be more or equal to the minimum wage so we can't make the modification");
    }
};

class exceptionPhoneNumber: public std::exception{
    const char* what() const noexcept override{
        return ("The phone number should have 10 digits so we can't make the modification");
    }
};




#endif //OOP_EXCEPTIONS_HPP
