//
// Created by Lucia on 11/24/2023.
//

#ifndef OOP_EMPLOYEE_HPP
#define OOP_EMPLOYEE_HPP
#include <iostream>
#include <vector>
#include "Person.hpp"
#include <memory>
#include <fstream>
#include <string>

class Employee : public Person {
private:
    std::string CNP;
    std::string address;
    std::string position;
    std::string hireDate;
    int salary = 0;
public:
    Employee() = default;
    virtual ~Employee() = default;

    Employee(const std::string &firstName, const std::string &lastName, const std::string &email,
             const std::string &telephoneNumber, const std::string &id, const std::string &cnp,
             const std::string &address, const std::string &position, const std::string &hireDate, int salary);

    void display() override;
    static void modifEmployee(const std::vector<std::shared_ptr<Employee>> &employees);
    void insertPerson(std::vector<std::shared_ptr<Person>> &Persons)override;
    void employeesFromFile(std::vector<std::shared_ptr<Person>> &emp);
};


#endif //OOP_EMPLOYEE_HPP
