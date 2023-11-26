//
// Created by Lucia on 11/24/2023.
//

#include "../Headers/Employee.hpp"
#include "../Headers/Exceptions.hpp"
#include <fstream>
#include <string>
#include <limits>
#include <stdexcept>


Employee::Employee(const std::string &firstName, const std::string &lastName, const std::string &email,
                   const std::string &telephoneNumber, const std::string &id, const std::string &cnp,
                   const std::string &address, const std::string &position, const std::string &hireDate, int salary)
        : Person(firstName, lastName, email, telephoneNumber, id), CNP(cnp), address(address), position(position),
          hireDate(hireDate), salary(salary) {

     if ( cnp.length() != 13 ) {
         std::cout << "This employee " << lastName << " " << firstName;
         throw exceptionCNP();
     }
}


void Employee::display() {
    Person::display();
    std::cout << " CNP: " << CNP << " Address: " << address << " Position: " << position << " Hire date: "
              << hireDate << "Salary: " << salary << std::endl;
}

void Employee::modifEmployee(const std::vector<std::shared_ptr<Employee>> &employees) {
    std::string nameEmp;
    std::cout << "Enter the last name of the employee you want to modify: ";
    std::getline(std::cin, nameEmp);

    int i = 0;
    int ok = 0;

    for (const auto &emp : employees) {
        if (emp->lastName == nameEmp) {
            ok = 1;
            break;
        }
        i++;
    }

    if (ok==1) {
        std::string dataEmp, infoEmp;

        std::cout << "What do you want to change? (address, email, phoneNumber, salary): ";
        std::cin >> dataEmp;

        std::cout << "Insert the modification: ";
        std::cin >> infoEmp;

        if (dataEmp == "address") {
            employees[i]->address = infoEmp;
        } else if (dataEmp == "email") {
            employees[i]->email = infoEmp;
        } else if (dataEmp == "phoneNumber") {
            if (infoEmp.length() != 10)
                throw exceptionPhoneNumber();
            else
                employees[i]->telephoneNumber = infoEmp;
        } else if (dataEmp == "salary") {
            int sal = std::stoi(infoEmp);
            if (sal < 2300)
                throw exceptionSalary();
            else
                employees[i]->salary = sal;
        } else {
            std::cout << "The data " << dataEmp << " can't be modified." << std::endl;
        }
    } else {
        std::cout << "Employee with last name '" << nameEmp << "' not found." << std::endl;
    }

    // Save the modifications to the file
    std::ofstream f("angajati.in");
    for (const auto &ang : employees)
        f << ang->lastName << '\n'
          << ang->firstName << '\n'
          << ang->email << '\n'
          << ang->telephoneNumber << '\n'
          << ang->id << '\n'
          << ang->CNP << '\n'
          << ang->address << '\n'
          << ang->position << '\n'
          << ang->hireDate << '\n'
          << ang->salary << '\n';

    f.close();
}


void Employee::insertPerson(std::vector<std::shared_ptr<Person>> &Persons) {
    std::cout << "Employee insert " << std::endl;
    std::string lastNameEmp, firstNameEmp, emailEmp, phoneNumberEmp, idEmp, cnpEmp, addrEmp, positEmp, dateEmp, salEmp;
    std::cout << "Last name: ";
    std::cin >> lastNameEmp;
    std::cout << "First name: ";
    std::cin >> firstNameEmp;
    std::cout << "Email: ";
    std::cin >> emailEmp;
    std::cout << "Phone number: ";
    std::cin >> phoneNumberEmp;
    std::cout << "ID: ";
    std::cin >> idEmp;
    std::cout << "CNP: ";
    std::cin >> cnpEmp;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Address: ";
    getline(std::cin, addrEmp);
    std::cout << "Position: ";
    std::cin >> positEmp;
    std::cout << "Hire date: ";
    std::cin >> dateEmp;
    std::cout << "Salary: ";
    std::cin >> salEmp;

    std::shared_ptr<Person> newEmployee = std::make_shared<Employee>(firstNameEmp, lastNameEmp, emailEmp,
                                                                     phoneNumberEmp, idEmp, cnpEmp, addrEmp, positEmp,
                                                                     dateEmp, std::stoi(salEmp));
    Persons.push_back(newEmployee);
    std::ofstream c("angajati.in", std::ios::app);

    c<<std::endl;
    c << lastNameEmp << '\n' << firstNameEmp << '\n' << emailEmp << '\n' << phoneNumberEmp << '\n' << idEmp << '\n'
      << cnpEmp << '\n'
      << addrEmp << '\n' << positEmp << '\n' << dateEmp << '\n' << salEmp << '\n';
    c.close();

}
