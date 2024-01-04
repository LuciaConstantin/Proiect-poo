/*#include <chrono>
#include "Headers/Book.hpp"
#include "Headers/Person.hpp"
#include "Headers/Customer.hpp"
#include "Headers/Employee.hpp"
#include "Headers/Sponsor.hpp"
#include "Headers/LoanHistory.hpp"*/
#include "Headers/Menu.hpp"


///library management system
///the Person class has a builder pattern and a template
///the Reservation class has a strategy pattern
///Book and Hall are defined using the factory pattern in Resource

int main() {
    Menu* M=Menu ::getInstance();
    M->displayMenu();

    return 0;
}
