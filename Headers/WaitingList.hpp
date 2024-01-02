//
// Created by Lucia on 12/16/2023.
//

#ifndef OOP_WAITINGLIST_HPP
#define OOP_WAITINGLIST_HPP
#include "../Headers/Book.hpp"
#include "../Headers/Person.hpp"
#include <algorithm>



class ConcretePerson;
class WaitingList{
public:
    using PersonBookPair = std::tuple<std::shared_ptr<ConcretePerson>, Book>;
    void insertObserver(std::vector<PersonBookPair>& observers, std::vector<Book> &books);
    void display(std::vector<PersonBookPair>& observers);
    void anonuce(std::vector<PersonBookPair>& observers,std::vector<Book> books);
};




#endif //OOP_WAITINGLIST_HPP
