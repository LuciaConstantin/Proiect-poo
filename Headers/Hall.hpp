//
// Created by Lucia on 12/15/2023.
//

#ifndef OOP_HALL_HPP
#define OOP_HALL_HPP
#include "../Headers/Resource.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>

class Hall:public Resource {
private:
    std::string hallName;
    int nrSeats;
    std::string dimensions;
    std::string openingHour;
    std::string closingHour;
public:
    void display() override;

    Hall(const std::string &hallName, int nrSeats, const std::string &dimensions, const std::string &openingHour,
         const std::string &closingHour);

    const std::string &getHallName() const;
    void hallsFromFile(std::vector<std::shared_ptr<Hall>> &halls);
};


#endif //OOP_HALL_HPP
