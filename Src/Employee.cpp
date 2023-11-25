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
          hireDate(hireDate), salary(salary) { }


void Employee::display(){
    Person::display();
    std::cout << " CNP: " << CNP << " Address: " << address << " Position: " << position << " Hire date: "
    << hireDate << "Salary: "<<salary <<std::endl;
}
void Employee::modifEmployee(std::vector<std::shared_ptr<Employee>> &employees) {
    std::string dataEmp, infoEmp, nameEmp;
    std::cout << "Employee data modification" << std::endl;
    std::cout << "Last name: ";
    std::cin >> nameEmp;
    std::cout << "What do you want to change?" << std::endl;
    std::cin >> dataEmp;
    std::cout << "Insert the modification: " << std::endl;
    std::cin >> infoEmp;
    int i = 0;
    bool ok = 0;
    for (const auto &emp: employees)
   {
        {
            if (emp->lastName == nameEmp) {
                ok = 1;
                break;
            }
        }
        i++;
    }
    if (ok == 1) {
        if ( "address" == dataEmp )
            employees[i]->address = infoEmp;
        else if ( "email" == dataEmp )
            employees[i]->email = infoEmp;
        else if ( "phoneNumber" == dataEmp ) {
            if ( infoEmp.length() != 10 )
                throw exceptionPhoneNumber();
            else
                employees[i]->telephoneNumber = infoEmp;
        }
        else if ("salary" == dataEmp)
        {
            int sal=std::stoi(infoEmp);
            if(sal< 2300)
                throw exceptionSalary();
            else
                employees[i]->salary = sal;}
        else
            std::cout << "The data " << dataEmp << " can't be modified " << std::endl;
    } else
        std::cout << "The employee doesn't exist ";
    std::ofstream f("angajati.in");
    for (const auto &ang: employees)
        f << ang->lastName << std::endl << ang->firstName << std::endl << ang->email<< std::endl <<ang->telephoneNumber<< std::endl
          <<ang->id<< std::endl <<ang->CNP << std::endl << ang->address<< std::endl <<ang->position<< std::endl <<ang->hireDate<< std::endl <<ang->salary<< std::endl<<'\n';

    f.close();
}
void Employee::insertPerson(std::vector<std::shared_ptr<Person>> &Persons) {
    std::cout << "Employee insert " << std::endl;
    std::string lastNameEmp, firstNameEmp, emailEmp, phoneNumberEmp, idEmp, cnpEmp, addrEmp, positEmp, dateEmp, salEmp ;
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
    getline(std::cin,addrEmp);
    std::cout << "Position: ";
    std::cin >> positEmp;
    std::cout << "Hire date: ";
    std::cin >> dateEmp;
    std::cout << "Salary: ";
    std::cin >> salEmp;

    std::shared_ptr<Person> newEmployee = std::make_shared<Employee>(firstNameEmp, lastNameEmp, emailEmp, phoneNumberEmp, idEmp, cnpEmp, addrEmp, positEmp, dateEmp, std::stoi(salEmp));
    Persons.push_back(newEmployee);
    std::ofstream c("angajati.in", std::ios::app);
    if (c) {
    c <<lastNameEmp << '\n' << firstNameEmp << '\n' << emailEmp << '\n' << phoneNumberEmp <<'\n'<< id<<'\n' << cnpEmp<<'\n'
    <<addrEmp<<'\n' <<positEmp<<'\n' <<dateEmp<<'\n' <<salEmp<< '\n';
    c.close();
    } else {
    std::cerr << "Can't find the file" << std::endl;
    }
}
