//
// Created by Lucia on 12/16/2023.
//

#include "../Headers/WaitingList.hpp"

void WaitingList::insertObserver(std::vector<PersonBookPair> &observers, std::vector<Book> &books) {
    std::string lname, fname, eml, nrTel;
    ConcretePersonBuilder personBuilder;
    std::cout << "\nWhat information the waiting person wants to give:" << std::endl;
    std::cout << "The sections that are not completed need to be initialized with 0" << std::endl;
    std::cout << "Last name: ";
    getline (std::cin, lname);
    std::cout << "First name: ";
    getline (std::cin, fname);
    std::cout << "Email: ";
    getline (std::cin, eml);
    std::cout << "Telephone number ";
    getline (std::cin, nrTel);
    if (lname != "0")
        personBuilder.setLastName (lname);
    if (fname != "0")
        personBuilder.setFirstName (fname);
    if (eml != "0")
        personBuilder.setEmail (eml);
    if (nrTel != "0")
        personBuilder.setTelephoneNumber (nrTel);
    auto observer = personBuilder.build ();
    std::string bkName;
    std::cout << "What book do you want to find ?" << std::endl;
    getline (std::cin, bkName);
    auto foundBook = std::find_if (books.begin (), books.end (),
                                   [&](const Book &c) {
                                       return c.getTitle () == bkName;
                                   });///returns the an iterator to the first correct value
    if (foundBook != books.end () && foundBook->getAvailability () != "disponibila") {
        std::cout << " The book is not available at the moment so the person is going to be added on a waiting list ";
        observers.push_back (std::make_tuple (observer, *foundBook));
    } else if (foundBook != books.end () && foundBook->getAvailability () == "disponibila")
        std::cout << "The book is available";

}

void WaitingList::display(std::vector<PersonBookPair> &observers) {
    std::cout << "\nWaiting List Observers: " << std::endl;

    for (const auto &observer: observers) {
        auto person = std::get<std::shared_ptr<ConcretePerson>> (observer);
        auto book = std::get<Book> (observer);

        std::cout << "Observer Information:" << std::endl;
        std::cout << "First name: " << person->getFirstName () << std::endl;
        std::cout << " Last name: " << person->getLastName () << std::endl;
        std::cout << "Email: " << person->getEmail () << std::endl;
        std::cout << "Telephone: " << person->getTelephoneNumber () << std::endl;

        std::cout << "Book Information:" << std::endl;
        std::cout << "Title: " << book.getTitle () << std::endl;
        std::cout << "Author: " << book.getAuthor () << std::endl;

        std::cout << "-------------------------" << std::endl;
    }
}
void WaitingList::anonuce(std::vector<PersonBookPair>& observers,std::vector<Book>books){
    for (const auto &observer:observers){
        auto person = std::get<std::shared_ptr<ConcretePerson>> (observer);
        auto book = std::get<Book> (observer);
        auto foundBook = std::find_if (books.begin (), books.end (),
                                       [&](const Book &c) {
                                           return c.getTitle () == book.getTitle();
                                       });
        if(foundBook != books.end ())
            std::cout<<person->getLastName()<<" "<<person->getFirstName()<<" wanted book is finally available"<<std::endl;
    }

}