//
// Created by Lucia on 11/26/2023.
//

#include "../Headers/Menu.hpp"

void Menu::displayMenu(std::vector<std::shared_ptr<Person>> &Customers, std::vector<Book> &books,
                       std::vector<std::shared_ptr<Person>> &Employees, std::vector<std::shared_ptr<Person>> &Sponsors) {
    int choice;
    std::string spatiu;

    do {
        std::cout << "=== Library Management System ===" << std::endl;
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
        std::cout << "13. Modify Employee" << std::endl;
        std::cout << "0. Exit" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;
        getline(std::cin,spatiu);

        switch (choice) {
            case 1:
                lh.addLoan(Customers, books);
                break;
            case 2:
                lh.returnBook(books);
                break;
            case 3:
            {
                for (const Book &cart : books)
                    std::cout << cart << std::endl;
            }
                break;
            case 4:
                bk.bookInfo(books);
                break;
            case 5:
                bk.booksAuthor(books);
                break;
            case 6:
                bk.insertBook(books);
                break;
            case 7:
                bk.changeBook(books);
                break;
            case 8:
            {
                for (const auto &person : Customers)
                    person->display();
            }
                break;
            case 9:
                cst.insertPerson(Customers);
                break;
            case 10:
                cst.searchPers(Customers);
                break;
            case 11:
            {
                for (const auto &person : Employees)
                    person->display();
            }
                break;
            case 12:
                emp.insertPerson(Employees);
                break;
            case 0:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 0);
}

Menu::Menu(const Sponsor &newSpon, const LoanHistory &lh, const Book &bk, const Customer &cst, const Employee &emp)
        : newSpon(newSpon), lh(lh), bk(bk), cst(cst), emp(emp) {}
