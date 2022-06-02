#ifndef CARDS_CARDS_H
#define CARDS_CARDS_H
#include <iostream>
#include <string>
class Cards{
public:
    Cards(std::string name, std::string suit, std::size_t value, std::size_t id):
            name_(name), suit_(suit), value_(value), id_(id){}
    std::string give_name() { return name_; }
private:
    std::string name_; //nazwa karty (dwójka, trójka, ..., walet, dama, król, as)
    std::string suit_; //rodzaj karty (serce, dzwonek, wino, żołądź)
    std::size_t value_; //wartość karty
    std::size_t id_; //numer dobierania karty (1 -13 - serce; 14 -26 - dzwonek; 27 - 39 - wino; 40 - 52 - żołądź)
};
#endif //CARDS_CARDS_H

