//
// Created by Lucia on 11/24/2023.
//

#include "Employee.hpp"
#include <fstream>
#include <string>
#include <limits>

Employee::Employee(const std::string &firstName, const std::string &lastName, const std::string &email,
         const std::string &telephoneNumber, const std::string &id, const std::string &cnp,
         const std::string &address, const std::string &position, const std::string &hireDate, int salary)
        : Person(firstName, lastName, email, telephoneNumber, id), CNP(cnp), address(address), position(position),
          hireDate(hireDate), salary(salary) {}

void Employee::display(){
    Person::display();
    std::cout << " CNP: " << CNP << " Address: " << address << " Position: " << position << " Hire date: "
    << hireDate << "Salary: "<<salary<<std::endl;
}
void Employee::modifEmployee(std::vector<Employee> &employees) {
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
    for (Employee &ang: employees) {
        {
            if (ang.lastName == nameEmp) {
                ok = 1;
                break;
            }
        }
        i++;
    }

    if (ok == 1) {
        if ("address" == dataEmp)
            employees[i].address = infoEmp;
        else if ("email" == dataEmp)
            employees[i].email = infoEmp;
        else if ("phoneNumber" == dataEmp)
            employees[i].telephoneNumber = infoEmp;
        else if ("salary" == dataEmp)
            employees[i].salary = std::stoi(infoEmp);
        else
            std::cout << "The data " << dataEmp << " can't be modified " << std::endl;
    } else
        std::cout << "The employee doesn't exist ";
    std::ofstream f("angajati.in");
    for (const Employee &ang: employees)
        f << ang.lastName << std::endl << ang.firstName << std::endl << ang.email<< std::endl <<ang.telephoneNumber<< std::endl
          <<ang.id<< std::endl <<ang.CNP << std::endl << ang.address<< std::endl <<ang.position<< std::endl <<ang.hireDate<< std::endl <<ang.salary<< std::endl;

    f.close();
}
void Employee::insertPerson(std::vector<std::shared_ptr<Person>> &Persons) {
    std::cout << "Employee insert " << std::endl;
    std::string lastName, firstName, email, phoneNumber, id, cnp, addr, posit, date, sal ;
    std::cout << "Last name: ";
    std::cin >> lastName;
    std::cout << "First name: ";
    std::cin >> firstName;
    std::cout << "Email: ";
    std::cin >> email;
    std::cout << "Phone number: ";
    std::cin >> phoneNumber;
    std::cout << "ID: ";
    std::cin >> id;
    std::cout << "CNP: ";
    std::cin >> cnp;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Address: ";
    getline(std::cin,addr);
    std::cout << "Position: ";
    std::cin >> posit;
    std::cout << "Hire date: ";
    std::cin >> date;
    std::cout << "Salary: ";
    std::cin >> sal;

    std::shared_ptr<Person> newEmployee = std::make_shared<Employee>(firstName, lastName, email, phoneNumber, id, cnp, addr, posit, date, std::stoi(sal));
    Persons.push_back(newEmployee);
    std::ofstream c("angajati.in", std::ios::app);
    if (c) {
    c <<lastName << '\n' << firstName << '\n' << email << '\n' << phoneNumber <<'\n'<< id<<'\n' << cnp<<'\n'
    <<addr<<'\n' <<posit<<'\n' <<date<<'\n' <<sal<< '\n';
    c.close();
    } else {
    std::cerr << "Can't find the file" << std::endl;
    }
}
