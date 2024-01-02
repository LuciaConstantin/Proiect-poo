//
// Created by Lucia on 12/16/2023.
//

#include "../Headers/Reservation.hpp"

void ReservationManager::addReservation(std::vector<std::shared_ptr<Hall>> &Halls) {
    std::string pName, hName, dt, st;
    std::cout << "The reservation information is:" << std::endl;
    std::cout << "Person name: ";
    getline(std::cin, pName);
    std::cout << "Hall name: ";
    getline(std::cin, hName);
    std::cout << "Reservation date: ";
    getline(std::cin, dt);
    std::cout << "Reservation seat: ";
    getline(std::cin, st);
    auto foundHall = std::find_if(Halls.begin(), Halls.end(),
                                  [&](const std::shared_ptr<Hall> &p) {
                                      return p->getHallName() == hName;});
    if (foundHall != Halls.end()) {
        Reservation reservation(pName, hName, dt, st);
        makeReservation(reservation);
    } else
        std::cout << "The reservation can't be made because the hall doesn't exist";

}


const std::string &Reservation::getHallName() const {
    return hallName;
}

const std::string &Reservation::getDate() const {
    return date;
}

const std::string &Reservation::getSeat() const {
    return seat;
}

Reservation::Reservation(const std::string &personName, const std::string &hallName, const std::string &date,
                         const std::string &seat) : personName(personName), hallName(hallName), date(date),
                                                    seat(seat) {}


bool DateValidator::validate(const Reservation &reservation) const {
    auto it = reservedDatesAndSeats.find(reservation.getDate());
    if (it != reservedDatesAndSeats.end()) {
        const auto &reservedSeats = it->second;
        if (reservedSeats.find(reservation.getSeat()) != reservedSeats.end()) {
            return false;
        }
    }

    reservedDatesAndSeats[ reservation.getDate() ].insert(reservation.getSeat());

    return true;
}

bool HallValidator::validate(const Reservation &reservation) const {

    auto it = reservedHallsAndSeats.find(reservation.getHallName());
    if (it != reservedHallsAndSeats.end()) {
        const auto &reservedSeats = it->second;
        if (reservedSeats.find(reservation.getSeat()) != reservedSeats.end()) {
            return false;
        }
    }


    reservedHallsAndSeats[ reservation.getHallName() ].insert(reservation.getSeat());

    return true;
}

bool SeatValidator::validate(const Reservation &reservation) const {

    auto it = reservedSeatsAndDates.find(reservation.getSeat());
    if (it != reservedSeatsAndDates.end()) {
        const auto &reservedDates = it->second;
        if (reservedDates.find(reservation.getDate()) != reservedDates.end()) {
            return false;
        }
    }


    reservedSeatsAndDates[ reservation.getSeat() ].insert(reservation.getDate());

    return true;
}


bool ReservationManager::makeReservation(const Reservation &reservation) {
    bool atLeastOneStrategyPassed = false;

    for (const auto &strategy: validationStrategies) {
        if (strategy->validate(reservation)) {

            atLeastOneStrategyPassed = true;
        }
    }

    if (atLeastOneStrategyPassed) {

        std::cout << "Reservation registered successfully!" << std::endl;
        return true;
    } else {
        std::cout << "The reservation could not be made due to validation rules." << std::endl;
        return false;
    }
}