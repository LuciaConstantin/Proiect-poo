//
// Created by Lucia on 11/24/2023.
//

#ifndef OOP_PERSON_HPP
#define OOP_PERSON_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <cstring>

class Person {
protected:
    std::string lastName;
    std::string firstName;
    std::string email;
    std::string telephoneNumber;
    std::string id;
public:
    Person() = default;

    virtual ~Person() = default;

    const std::string &getFirstName() const;

    const std::string &getLastName() const;


    Person(const std::string &firstName , const std::string &lastName , const std::string &email ,
           const std::string &telephoneNumber , const std::string &id);

    virtual void display();

    // int searchPerson(std::vector<std::shared_ptr<Person>> &Persons, std::string LastName, std::string FirstName);
    void searchPers(const std::vector<std::shared_ptr<Person>> &Persons);

    virtual void insertPerson(std::vector<std::shared_ptr<Person>> &Persons) = 0;

};


#endif //OOP_PERSON_HPP
