#ifndef CARDS_CARDS_H
#define CARDS_CARDS_H
#include <iostream>
#include <string>
class Cards{
public:
    Cards(std::string name, std::string suit, std::size_t value, std::size_t id):
    name_(name), suit_(suit), value_(value), id_(id){}

    std::string give_name(){ return name_;}
    std::size_t give_value(){ return value_;}
    std::size_t give_id(){return id_;}
    void give_card();
    
private:
    std::string name_;
    std::string suit_;
    std::size_t value_;
    std::size_t id_;
};

Cards card_1("AS", "pik", 11, 0)
Cards card_2("AS", "kier", 11, 1)
Cards card_3("AS", "trefl", 11, 2)
Cards card_4("AS", "karo", 11, 3)
    
#endif //CARDS_CARDS_H
