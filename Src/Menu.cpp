//
// Created by Lucia on 11/26/2023.
//

#include "../Headers/Menu.hpp"

void Menu::displayMenu() {
    std::vector<Book> books;
    bk.readFromFile(books);

    std::vector<std::shared_ptr<Person>> Customers;
    cst.CustomersFromFile(Customers);

    std::vector<std::shared_ptr<Person>> Employees;
    emp.employeesFromFile(Employees);

    std::vector<std::shared_ptr<Person>> Sponsors;
    newSpon.sponsorsFromFile(Sponsors);

    Hall hl;
    std::vector<std::shared_ptr<Hall>> Halls;
    hl.hallsFromFile(Halls);

    std::vector<WaitingList::PersonBookPair> observers;

    int choice;
    std::string spatiu;
    ReservationManager reservationManager;
    do {
        std::cout << "\n=== Library Management System ===" << std::endl;
        std::cout << "1. Add Loan" << std::endl;
        std::cout << "2. Return Book" << std::endl;
        std::cout << "3. Display Books" << std::endl;
        std::cout << "4. Book Info" << std::endl;
        std::cout << "5. Books by Author" << std::endl;
        std::cout << "6. Insert Book" << std::endl;
        std::cout << "7. Change Book" << std::endl;
        std::cout << "8. Display Customers" << std::endl;
        std::cout << "9. Add Customer" << std::endl;
        std::cout << "10. Search Customer" << std::endl;
        std::cout << "11. Display Employees" << std::endl;
        std::cout << "12. Add Employee" << std::endl;
        std::cout << "13. Insert sponsor" << std::endl;
        std::cout << "14. Modify employee" << std::endl;
        std::cout << "15. Search Employee" << std::endl;
        std::cout << "16. Insert Hall" << std::endl;
        std::cout << "17. Display Halls Information " << std::endl;
        std::cout << "18. Waiting List Insert " << std::endl;
        std::cout << "19. Waiting List Display" << std::endl;
        std::cout << "20. Make a reservation" << std::endl;
        std::cout << "0. Exit" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;
        getline(std::cin, spatiu);

        switch (choice) {
            case 1:
                lh.addLoan(Customers, books);
                break;
            case 2:
                lh.returnBook(books, observers);
                break;
            case 3: {
                for (const Book &cart: books)
                    std::cout << cart << std::endl;
            }
                break;
            case 4:
                bk.bookInfo(books);
                break;
            case 5:
                bk.booksAuthor(books);
                break;
            case 6: {   ///insert book
                resourceFactory = std::make_shared<BookFactory>();
                std::shared_ptr<Resource> book = resourceFactory->createResource();
                books.push_back(*std::dynamic_pointer_cast<Book>(book));
            }
                break;
            case 7:
                bk.changeBook(books);
                break;
            case 8: {
                for (const auto &person: Customers)
                    person->display();
            }
                break;
            case 9:
                cst.insertPerson(Customers);
                break;
            case 10:
                cst.searchPers(Customers);
                break;
            case 11: {
                for (const auto &person: Employees)
                    person->display();
            }
                break;
            case 12:
                emp.insertPerson(Employees);
                break;
            case 13:
                newSpon.insertPerson(Sponsors);
                break;
            case 14: {
                std::vector<std::shared_ptr<Employee>> employees;
                for (const auto &personPtr: Employees)
                    if ( auto employeePtr = std::dynamic_pointer_cast<Employee>(personPtr))
                        employees.push_back(employeePtr);
                try {
                    emp.modifEmployee(employees);
                }
                catch (std::exception &excep) {
                    std::cout << excep.what() << '\n';
                }
            }
                break;
            case 15:
                pers->searchPers(Employees);
                break;
            case 16: {
                resourceFactory = std::make_shared<HallFactory>();
                std::shared_ptr<Resource> hall = resourceFactory->createResource();
                Halls.push_back(std::dynamic_pointer_cast<Hall>(hall));
            }
                break;
            case 17: {
                std::shared_ptr<Resource> hall;
                std::shared_ptr<Hall> hallPtr = std::dynamic_pointer_cast<Hall>(hall);
                for (const auto &hll: Halls) {
                    hll->display();
                }
            }
                break;
            case 18: {
                WaitingList waitingList;
                waitingList.insertObserver(observers, books);
            }
                break;
            case 19: {
                WaitingList wl;
                wl.display(observers);
            }
                break;
            case 20:
                reservationManager.addReservation(Halls);
                break;
            case 0:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 0);
}

Menu::Menu(const Sponsor &newSpon, const LoanHistory &lh, const Book &bk, const Customer &cst, const Employee &emp,
           const std::shared_ptr<Person> &pers) : newSpon(newSpon), lh(lh), bk(bk), cst(cst), emp(emp), pers(pers) {}


Menu *Menu::getInstance() {
    if ( instancePtr == nullptr ) {
        instancePtr = new Menu(Sponsor(), LoanHistory(), Book(), Customer(), Employee(), std::shared_ptr<Person>());
    }
    return instancePtr;
}

Menu *Menu::instancePtr = nullptr;