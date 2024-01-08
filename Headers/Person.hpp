//
// Created by Lucia on 11/24/2023.
//
////Here i also have a builder pattern and a template
#ifndef OOP_PERSON_HPP
#define OOP_PERSON_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <cstring>
#include "../Headers/WaitingList.hpp"

class WaitingList;

class Person{
protected:
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string telephoneNumber;
    std::string id;

public:
    Person() = default;

    virtual ~Person() = default;

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    Person(const std::string &firstName, const std::string &lastName, const std::string &email,
           const std::string &telephoneNumber, const std::string &id);

    virtual void display();

    void searchPers(const std::vector<std::shared_ptr<Person>> &Persons);

    virtual void insertPerson(std::vector<std::shared_ptr<Person>> &Persons) = 0;

    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setEmail(const std::string &email);
    void setTelephoneNumber(const std::string &telephoneNumber);

    const std::string &getEmail() const;

    const std::string &getTelephoneNumber() const;
};

template <typename T>
class PersonBuilder {
protected:
    std::shared_ptr<T> builder;

public:
    PersonBuilder() : builder(std::make_shared<T>()) {}

    virtual ~PersonBuilder() = default;

    virtual PersonBuilder &setFirstName(const std::string &fName) {
        builder->setFirstName(fName);
        return *this;
    }

    virtual PersonBuilder &setLastName(const std::string &lName) {
        builder->setLastName(lName);
        return *this;
    }

    virtual PersonBuilder &setEmail(const std::string &email) {
        builder->setEmail(email);
        return *this;
    }

    virtual PersonBuilder &setTelephoneNumber(const std::string &telNumber) {
        builder->setTelephoneNumber(telNumber);
        return *this;
    }

    virtual std::shared_ptr<T> build() {
        return builder;
    }
};

class ConcretePerson : public Person {
public:
    ConcretePerson() = default;

    void insertPerson(std::vector<std::shared_ptr<Person>> &Persons) override {
        Persons.push_back(std::make_shared<ConcretePerson>(*this));
    }
};

class ConcretePersonBuilder : public PersonBuilder<ConcretePerson> {
public:
    ConcretePersonBuilder() : PersonBuilder<ConcretePerson>() {}
    std::shared_ptr<ConcretePerson> build() override {
        return std::dynamic_pointer_cast<ConcretePerson>(builder);
    }
};



#endif //OOP_PERSON_HPP
