#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

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
    Book () = default;

    ~Book () = default;

    Book (const std::string &title, const std::string &author, const std::string &domain,
          const std::string &availability, const std::string &isbn, const std::string &language,
          const std::string &publishingHouse, int publishingYear, const std::string &ID) : title (title),
                                                                                           author (author),
                                                                                           domain (domain),
                                                                                           availability (availability),
                                                                                           ISBN (isbn),
                                                                                           language (language),
                                                                                           publishingHouse (
                                                                                                   publishingHouse),
                                                                                           publishingYear (
                                                                                                   publishingYear),
                                                                                           ID (ID) {}


    friend std::ostream &operator<< (std::ostream &os, const Book &Book) {
        os << "title: " << Book.title << " author: " << Book.author << " domain: " << Book.domain
           << " availability: " << Book.availability << " ISBN: " << Book.ISBN << " language: " << Book.language
           << " publishingHouse: " << Book.publishingHouse << " publishingYear: " << Book.publishingYear << " ID: "
           << Book.ID << std::endl;
        return os;
    }

    void static bookInfo (const std::vector<Book> &books) {
        std::string bookTitle;
        std::cout << "For which Book do you want to find out the information: ";
        getline (std::cin, bookTitle);
        int i = 0;
        int ok = 0;
        for ( const Book &cart: books ) {
            if ( cart.title == bookTitle )///std::strcmp
            {
                ok = 1;
                break;
            }
            i++;
        }

        if ( ok == 0 )
            std::cout << "The book is not found in the database" << std::endl;
        else {
            std::cout << "The book is found in the database and has the informations: " << std::endl;
            std::cout << "title: " << books[ i ].title << " author: " << books[ i ].author << " domain: "
                      << books[ i ].domain
                      << " availability: " << books[ i ].availability << " ISBN: " << books[ i ].ISBN << " language: "
                      << books[ i ].language
                      << " publishingHouse: " << books[ i ].publishingHouse << " publishingYear: "
                      << books[ i ].publishingYear << " ID: "
                      << books[ i ].ID << std::endl;
        }

    }

    void static booksAuthor (const std::vector<Book> &books) {
        std::cout << "Search the books based on the author " << std::endl;
        std::string authorName;
        getline (std::cin, authorName);
        int ok = 0;
        int i = 0;
        for ( const Book &cart: books ) {
            if ( authorName == cart.author )///std::strcmp
            {
                std::cout << "The author " << authorName << " wrote: " << books[ i ].title << std::endl;
                ok = 1;
            }
            i++;
        }
        if ( ok == 0 )
            std::cout << "The author " << authorName << " doesn't exist in our library " << std::endl;

    }

    Book (const Book &c)
            : title (c.title), author (c.author), domain (c.domain), availability (c.availability),
              ISBN (c.ISBN), language (c.language), publishingHouse (c.publishingHouse),
              publishingYear (c.publishingYear),
              ID (c.ID) {}

    // Book  &operator=(const Book &Book) = default;
    Book &operator= (const Book &Book) {
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

class Customer {
private:
    std::string lastName;
    std::string firstName;
    std::string email;
    std::string phoneNumber;
    std::string registrationDate;

public:
    Customer () = default;

    ~Customer () = default;

    Customer (const std::string &lastName, const std::string &firstName, const std::string &email,
              const std::string &phoneNumber,
              const std::string &registrationDate)
            : lastName (lastName), firstName (firstName), email (email), phoneNumber (phoneNumber),
              registrationDate (registrationDate) {}

    friend std::ostream &operator<< (std::ostream &os, const Customer &Customer) {
        os << "lastName: " << Customer.lastName << " firstName: " << Customer.firstName << " email: " << Customer.email
           << " phoneNumber: "
           << Customer.phoneNumber << " registrationDate: " << Customer.registrationDate;
        return os;
    }

    void static findingCustomer (const std::vector<Customer> &Customers) {
        std::cout << "Searching for a customer in the database " << std::endl;
        std::string lastName_Customer, firstName_Customer;
        std::cout << "Last Name: ";
        getline (std::cin, lastName_Customer);
        std::cout << "First Name: ";
        getline (std::cin, firstName_Customer);
        int ok = 0;
        for ( const Customer &cli: Customers )
            if ( cli.lastName == lastName_Customer && cli.firstName == firstName_Customer )///std::strcmp
            {
                std::cout << "The customer" << lastName_Customer << " " << firstName_Customer
                          << " is already in the database" << std::endl;
                ok = 1;
                break;
            }

        if ( ok == 0 )
            std::cout << "The customer is not in the database" << std::endl;

    }

    static void insertCustomer (std::vector<Customer> &Customers) {
        std::cout << "Customer insert " << std::endl;
        std::string lastName, firstName, email, phoneNumber, registrationDate;
        std::cout << "Last name: ";
        std::cin >> lastName;
        std::cout << "First name: ";
        std::cin >> firstName;
        std::cout << "Email: ";
        std::cin >> email;
        std::cout << "Phone number: ";
        std::cin >> phoneNumber;
        std::cout << "Registration date: ";
        std::cin >> registrationDate;

        Customer newCustomer (lastName, firstName, email, phoneNumber, registrationDate);
        Customers.push_back (newCustomer);
        std::ofstream c ("client.in", std::ios::app);
        if ( c ) {
            c << lastName << '\n' << firstName << '\n' << email << '\n' << phoneNumber << '\n' << registrationDate
              << '\n';
            c.close ();
        } else {
            std::cerr << "Can't find the file" << std::endl;
        }

    }

};

class Employee {
private:
    std::string lastName;
    std::string firstName;
    std::string CNP;
    std::string address;
    std::string email;
    std::string phoneNumber;
    std::string position;
    std::string hireDate;
    int salary = 0;
public:
    Employee () = default;

    ~Employee () = default;

    Employee (const std::string &lastName, const std::string &firstName, const std::string &cnp,
              const std::string &address,
              const std::string &email, const std::string &phoneNumber, const std::string &position,
              const std::string &hireDate, int salary)
            : lastName (lastName), firstName (firstName), CNP (cnp), address (address), email (email),
              phoneNumber (phoneNumber),
              position (position), hireDate (hireDate), salary (salary) {}


    friend std::ostream &operator<< (std::ostream &os, const Employee &Employee) {
        os << "lastName: " << Employee.lastName << " firstName: " << Employee.firstName << " CNP: " << Employee.CNP
           << " address: "
           << Employee.address << " email: " << Employee.email << " phoneNumber: " << Employee.phoneNumber
           << " position: "
           << Employee.position << " hireDate: " << Employee.hireDate << " salary: " << Employee.salary;
        return os;
    }

    static void modifEmployee (std::vector<Employee> &employees) {
        std::string dataEmp, infoEmp, nameEmp;
        std::cout << "Employee data modification" << std::endl;
        std::cout << "Name: ";
        std::cin >> nameEmp;
        std::cout << "What do you want to change?" << std::endl;
        std::cin >> dataEmp;
        std::cout << "Insert the modification: " << std::endl;
        std::cin >> infoEmp;
        int i = 0;
        bool ok = 0;
        for ( Employee &ang: employees ) {
            {
                if ( ang.lastName == nameEmp ) {///gasesc Employeeul
                    ok = 1;
                    break;
                }
            }
            i++;
        }

        if ( ok == 1 ) {
            if ( "address" == dataEmp )
                employees[ i ].address = infoEmp;
            else if ( "email" == dataEmp )
                employees[ i ].email = infoEmp;
            else if ( "phoneNumber" == dataEmp )
                employees[ i ].phoneNumber = infoEmp;
            else if ( "salary" == dataEmp )
                employees[ i ].salary = std::stoi (infoEmp);
            else
                std::cout << "The data " << dataEmp << " can't be modified " << std::endl;
        } else
            std::cout << "The employee doesn't exist ";
        std::ofstream f ("angajati.in");
        for ( const Employee &ang: employees )
            f << ang.lastName << std::endl << ang.firstName << std::endl << ang.CNP << std::endl << ang.address
              << std::endl << ang.email << std::endl
              << ang.phoneNumber << std::endl << ang.position << std::endl << ang.hireDate << std::endl << ang.salary
              << std::endl;
        f.close ();
    }
};


int main () {
    std::ifstream f ("carte.in");
    if ( !f ) {
        std::cerr << "Can't open the file" << std::endl;
        return 1;
    }
    std::vector<Book> books;
    std::string title, author, domain, availability, ISBN, language, publishingHouse, ID;
    int publishingYear;
    while ( getline (f, title)) {
        getline (f, author);
        getline (f, domain);
        getline (f, availability);
        getline (f, ISBN);
        getline (f, language);
        getline (f, publishingHouse);
        f >> publishingYear;
        f.ignore ();//pt endline
        getline (f, ID);

        Book newBook (title, author, domain, availability, ISBN, language, publishingHouse, publishingYear, ID);
        books.push_back (newBook);

    }
    f.close ();

    for ( const Book &cart: books )
        std::cout << cart << std::endl;

    ///---------------------------------------

    std::ifstream c ("client.in");
    if ( !c ) {
        std::cerr << "Can't open the file " << std::endl;
        return 1;
    }
    std::string lastName, firstName, email, phoneNumber, data;
    std::vector<Customer> Customers;
    while ( getline (c, lastName)) {
        getline (c, firstName);
        getline (c, email);
        getline (c, phoneNumber);
        getline (c, data);
        Customer newCustomer (lastName, firstName, email, phoneNumber, data);
        Customers.push_back (newCustomer);
    }
    c.close ();
    for ( const Customer &i: Customers )
        std::cout << i << std::endl;

    std::ifstream a ("employees.in");
    std::string lastNameAng, firstNameAng, CNP, address, emailAng, phoneNr, position, data_ang;
    int salary;
    std::vector<Employee> employees;
    while ( getline (a, lastNameAng)) {
        getline (a, firstNameAng);
        getline (a, CNP);
        getline (a, address);
        getline (a, emailAng);
        getline (a, phoneNr);
        getline (a, position);
        getline (a, data_ang);
        a >> salary;
        a.ignore ();
        Employee newEmployee (lastNameAng, firstNameAng, CNP, address, emailAng, phoneNr, position, data_ang, salary);
        employees.push_back (newEmployee);
    }
    a.close ();
    std::cout << std::endl;
    for ( const Employee &ang: employees )
        std::cout << ang << std::endl;


    Book crte;
    Customer cli;
    Employee ang;
    std::cout << "First copy " << std::endl;
    Book Book_copiata1 (books[ 2 ]);
    std::cout << Book_copiata1 << std::endl;
    std::cout << "Second copy " << std::endl;
    Book Book_copiata2 = books[ 1 ];
    std::cout << Book_copiata2 << std::endl;
    crte.bookInfo (books);
    std::cout << std::endl;
    crte.booksAuthor (books);
    std::cout << std::endl;
    cli.findingCustomer (Customers);
    std::cout << std::endl;
    cli.insertCustomer (Customers);
    std::cout << std::endl;
    ang.modifEmployee (employees);

    return 0;
}
