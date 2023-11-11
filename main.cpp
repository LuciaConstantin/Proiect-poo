#include <iostream>
#include <fstream>
#include <vector>
//#include <string.h>
//#include <cstring>
#include <string>
///library management system

class Book {
private:
    std::string title;
    std::string author;
    std::string domain;
    std::string availability;
    std::string ISBN;
    std::string language;
    std::string publishingHouse;
    int publishingYear = 0;///optional
    std::string ID;
public:
    Book() = default;

    ~Book() = default;

    Book(const std::string &title, const std::string &author, const std::string &domain,
         const std::string &availability, const std::string &isbn, const std::string &language,
         const std::string &publishingHouse, int publishingYear, const std::string &ID) : title(title),
                                                                                          author(author),
                                                                                          domain(domain),
                                                                                          availability(availability),
                                                                                          ISBN(isbn),
                                                                                          language(language),
                                                                                          publishingHouse(
                                                                                                  publishingHouse),
                                                                                          publishingYear(
                                                                                                  publishingYear),
                                                                                          ID(ID) {
    }


    friend std::ostream &operator<<(std::ostream &os, const Book &Book) {
        os << "title: " << Book.title << " author: " << Book.author << " domain: " << Book.domain
           << " availability: " << Book.availability << " ISBN: " << Book.ISBN << " language: " << Book.language
           << " publishingHouse: " << Book.publishingHouse << " publishingYear: " << Book.publishingYear << " ID: "
           << Book.ID << std::endl;
        return os;
    }

    void static bookInfo(const std::vector<Book> &books) {
        std::string bookTitle;
        std::cout << "For which Book do you want to find out the information: ";
        getline(std::cin, bookTitle);
        int i = 0;
        int ok = 0;
        for (const Book &cart: books) {
            if (cart.title == bookTitle)///std::strcmp
            {
                ok = 1;
                break;
            }
            i++;
        }

        if (ok == 0)
            std::cout << "The book is not found in the database" << std::endl;
        else {
            std::cout << "The book is found in the database and has the informations: " << std::endl;
            std::cout << "title: " << books[i].title << " author: " << books[i].author << " domain: "
                      << books[i].domain
                      << " availability: " << books[i].availability << " ISBN: " << books[i].ISBN << " language: "
                      << books[i].language
                      << " publishingHouse: " << books[i].publishingHouse << " publishingYear: "
                      << books[i].publishingYear << " ID: "
                      << books[i].ID << std::endl;
        }

    }

    void static booksAuthor(const std::vector<Book> &books) {
        std::cout << "Search the books based on the author " << std::endl;
        std::string authorName;
        getline(std::cin, authorName);
        int ok = 0;
        int i = 0;
        for (const Book &cart: books) {
            if (authorName == cart.author)///std::strcmp
            {
                std::cout << "The author " << authorName << " wrote: " << books[i].title << std::endl;
                ok = 1;
            }
            i++;
        }
        if (ok == 0)
            std::cout << "The author " << authorName << " doesn't exist in our library " << std::endl;

    }

    Book(const Book &c)
            : title(c.title), author(c.author), domain(c.domain), availability(c.availability),
              ISBN(c.ISBN), language(c.language), publishingHouse(c.publishingHouse),
              publishingYear(c.publishingYear),
              ID(c.ID) {
    }

    // Book  &operator=(const Book &Book) = default;
    Book &operator=(const Book &Book) {
        /*if (this == &Book) {
            return *this;
        }*/
        title = Book.title;
        author = Book.author;
        domain = Book.domain;
        availability = Book.availability;
        ISBN = Book.ISBN;
        language = Book.language;
        publishingHouse = Book.publishingHouse;
        publishingYear = Book.publishingYear;
        ID = Book.ID;
        return *this;
    }


};

class Person {
protected:
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string telephoneNumber;
    std::string id;
public:
    Person() = default;

    ~Person() = default;

    Person(const std::string &firstName, const std::string &lastName, const std::string &email,
           const std::string &telephoneNumber, const std::string &id) : firstName(firstName), lastName(lastName),
                                                                        email(email),
                                                                        telephoneNumber(telephoneNumber), id(id) {
    }

    virtual void display() {
        std::cout << "Last name: " << lastName << " First name: " << firstName << " Email: " << email
                  << " Telephone number: " << telephoneNumber << " ID: " << id;
    }

    void search(const std::vector<Person *> &Persons) {
        std::cout << "Searching for a customer in the database " << std::endl;
        std::string lastName_pers, firstName_pers;
        std::cout << "Last Name: ";
        std::cin >> lastName_pers;
        std::cout << "First Name: ";
        std::cin >> firstName_pers;
        int ok = 0;
        for (const Person *cli: Persons)
            if (cli->lastName == lastName_pers && cli->firstName == firstName_pers)///std::strcmp
            {
                std::cout << lastName_pers << " " << firstName_pers << " is in the database" << std::endl;
                ok = 1;
                break;
            }
        if (ok == 0)
            std::cout << "This person is not in the database" << std::endl;

    }

};

class Customer : public Person {
private:
    std::string registrationDate;
public:
    Customer() = default;

    ~Customer() = default;

    Customer(const std::string &firstName, const std::string &lastName, const std::string &email,
             const std::string &telephoneNumber, const std::string &id, const std::string &registrationDate)
            : Person(firstName, lastName, email, telephoneNumber, id),
              registrationDate(registrationDate) {
    }

    void display() override {
        Person::display();
        std::cout << " Registration date: " << registrationDate << std::endl;
    }

    static void insertCustomer(std::vector<Customer> &Customers) {
        std::cout << "Customer insert " << std::endl;
        std::string lastName, firstName, email, phoneNumber, id, registrationDate;
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
        std::cout << "Registration date: ";
        std::cin >> registrationDate;

        Customer newCustomer(firstName, lastName, email, phoneNumber, id, registrationDate);
        Customers.push_back(newCustomer);
        std::ofstream c("client.in", std::ios::app);
        if (c) {
            c << lastName << '\n' << firstName << '\n' << email << '\n' << phoneNumber <<'\n'<< id<<'\n' << registrationDate
              << '\n';
            c.close();
        } else {
            std::cerr << "Can't find the file" << std::endl;
        }

    }

};

class Employee : public Person {
private:
    std::string CNP;
    std::string address;
    std::string position;
    std::string hireDate;
    int salary = 0;
public:
    Employee() = default;

    ~Employee() = default;

    Employee(const std::string &firstName, const std::string &lastName, const std::string &email,
             const std::string &telephoneNumber, const std::string &id, const std::string &cnp,
             const std::string &address, const std::string &position, const std::string &hireDate, int salary)
            : Person(firstName, lastName, email, telephoneNumber, id), CNP(cnp), address(address), position(position),
              hireDate(hireDate), salary(salary) {
    }

    void display() override {
        Person::display();
        std::cout << " CNP: " << CNP << " Address: " << address << " Position: " << position << " Hire date: "
                  << hireDate << std::endl;
    }

    static void modifEmployee(std::vector<Employee> &employees) {
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
};

class Sponsor : public Person {
private:
    std::string donationType;
    std::string donationDate;
public:
    Sponsor() = default;

    ~Sponsor() = default;

    Sponsor(const std::string &firstName, const std::string &lastName, const std::string &email,
            const std::string &telephoneNumber, const std::string &id, const std::string &donationType,
            const std::string &donationDate) : Person(firstName, lastName, email, telephoneNumber, id),
                                               donationType(donationType), donationDate(donationDate) {
    }

    void display() override {
        Person::display();
        std::cout << " Donation type: " << donationType << " Donation date: " << donationDate << std::endl;
    }

};

int main() {
    std::ifstream f("carte.in");
    if (!f) {
        std::cerr << "Can't open the file" << std::endl;
        return 1;
    }
    std::vector<Book> books;
    std::string title, author, domain, availability, ISBN, language, publishingHouse, ID;
    int publishingYear;
    while (getline(f, title)) {
        getline(f, author);
        getline(f, domain);
        getline(f, availability);
        getline(f, ISBN);
        getline(f, language);
        getline(f, publishingHouse);
        f >> publishingYear;
        f.ignore();//pt endline
        getline(f, ID);

        Book newBook(title, author, domain, availability, ISBN, language, publishingHouse, publishingYear, ID);
        books.push_back(newBook);

    }
    f.close();

    for (const Book &cart: books)
        std::cout << cart << std::endl;

    ///---------------------------------------

    std::ifstream c("client.in");
    if (!c) {
        std::cerr << "Can't open the file " << std::endl;
        return 1;
    }
    std::string lastName, firstName, email, phoneNumber, id, date;
    std::vector<Customer> Customers;
    while (getline(c, firstName)) {
        getline(c, lastName);
        getline(c, email);
        getline(c, phoneNumber);
        getline(c, id);
        getline(c, date);
        Customer newCustomer(firstName, lastName, email, phoneNumber, id, date);
        Customers.push_back(newCustomer);
    }
    c.close();
    for (std::vector<Customer>::size_type i = 0; i < Customers.size(); ++i)
        Customers[i].display();

    std::ifstream a("angajati.in");
    std::string lastNameEmp, firstNameEmp, CNP, address, emailAng, phoneNr, position, data_ang, id_emp;
    int salary;
    std::vector<Employee> employees;
    while (getline(a, firstNameEmp)) {
        getline(a, lastNameEmp);
        getline(a, emailAng);
        getline(a, phoneNr);
        getline(a, id_emp);
        getline(a, CNP);
        getline(a, address);
        getline(a, position);
        getline(a, data_ang);
        a >> salary;
        a.ignore();
        Employee newEmployee(lastNameEmp, firstNameEmp, emailAng, phoneNr, id_emp, CNP, address, position, data_ang,
                             salary);
        employees.push_back(newEmployee);
    }
    a.close();
    std::cout << std::endl;
    for (std::vector<Employee>::size_type i = 0; i < employees.size(); ++i)
        employees[i].display();


    std::vector<Person *> p;
    Person pers;

    for (const Customer &client: Customers) {
        p.push_back(new Customer(client));
    }
    for (const Employee &employee: employees) {
        p.push_back(new Employee(employee));
    }
    pers.search(p);
    Customer cli;
    Employee emp;
    cli.insertCustomer(Customers);
    emp.modifEmployee(employees);

    return 0;
}
