//
// Created by Lucia on 12/15/2023.
//

#include "../Headers/Hall.hpp"

void Hall::display()
{
    std::cout<<"The name of the hall: "<<hallName<<"\n Number of seats: "<<nrSeats<<"\n Dimensions: "<<dimensions
    <<"\n Opening hour: "<<openingHour<<"\n Closing hour: "<<closingHour<<std::endl;
}


const std::string &Hall::getHallName() const {
    return hallName;
}
void Hall::hallsFromFile(std::vector<std::shared_ptr<Hall>> &halls){

    std::ifstream h("Hall.in");
    std::string hName, hDimensions, hOpening,hclosing;
    int hSeats;
    while(getline(h,hName)){
        h>>hSeats;
        h.ignore();
        getline(h,hDimensions);
        getline(h, hOpening);
        getline(h, hclosing);
        std::shared_ptr<Hall> ha = std::make_shared<Hall>(hName, hSeats, hDimensions, hOpening, hclosing);
        halls.push_back(ha);
        getline(h, hDimensions);///for the space between the data
    }
    h.close();
}

Hall::Hall(const std::string &hallName, int nrSeats, const std::string &dimensions, const std::string &openingHour,
           const std::string &closingHour) : hallName(hallName), nrSeats(nrSeats), dimensions(dimensions),
                                             openingHour(openingHour), closingHour(closingHour) {}
