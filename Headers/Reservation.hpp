//
// Created by Lucia on 12/16/2023.
//

#ifndef OOP_RESERVATION_HPP
#define OOP_RESERVATION_HPP
#include <iostream>
#pragma once/// compilare
#include <unordered_set>
#include <vector>
#include <string>
#include <unordered_map>
#include "../Headers/Hall.hpp"
#include <memory>
#include <algorithm>

class Reservation {
private:
    std::string personName;
    std::string hallName;
    std::string date;
    std::string seat;
public:

    Reservation(const std::string &personName, const std::string &hallName, const std::string &date,
                const std::string &seat);
    const std::string &getSeat() const;
    const std::string &getHallName() const;
    const std::string &getDate() const;
};
class ValidationStrategy {
public:
    virtual bool validate(const Reservation& reservation) const = 0;
    virtual ~ValidationStrategy() = default;
};

class DateValidator : public ValidationStrategy {
private:
    mutable std::unordered_map<std::string, std::unordered_set<std::string>> reservedDatesAndSeats;

public:
    bool validate(const Reservation& reservation) const override;
};

class HallValidator : public ValidationStrategy {
private:
   mutable std::unordered_map<std::string, std::unordered_set<std::string>> reservedHallsAndSeats;

public:
    bool validate(const Reservation& reservation) const override;
};

class SeatValidator : public ValidationStrategy {
private:
    mutable std::unordered_map<std::string, std::unordered_set<std::string>> reservedSeatsAndDates;

public:
    bool validate(const Reservation& reservation) const override ;
};

class ReservationManager {
private:
    DateValidator dateValidator;
    SeatValidator seatValidator;
    HallValidator hallValidator;
    std::vector<ValidationStrategy*> validationStrategies;

public:
    ReservationManager() : validationStrategies{&dateValidator, &seatValidator, &hallValidator} {}
    bool makeReservation(const Reservation& reservation);
    void addReservation(std::vector<std::shared_ptr<Hall>> &Halls);
};




#endif //OOP_RESERVATION_HPP
