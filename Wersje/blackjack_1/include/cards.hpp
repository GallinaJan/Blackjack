#ifndef CARDS_HPP
#define CARDS_HPP

#include <iostream>
#include <string>
#include "player.hpp"
#include <cstdlib>
#include <ctime>
#include <chrono>

//srand(static_cast<unsigned int>(time(NULL)));

class Cards {
public:
    Cards() = default;

    Cards(std::string name, std::string suit, std::size_t value, std::size_t id) :
            name_(name), suit_(suit), value_(value), id_(id) {}

    std::string give_name() { return name_; }

    std::string give_suit() { return suit_; }

    std::size_t give_value() { return value_; }

    std::size_t give_id() const { return id_; }

private:
    std::string name_;
    std::string suit_;
    std::size_t value_;
    std::size_t id_;
};


class Hand {
public:
    Hand() {
        bool visited_[52];
        std::size_t left_ = 52;
        for (int i = 0; i < 52; i++)
            visited_[i] = false;

        while (left_ > 0) {
            int new_idx = std::rand() % 52;
            while (visited_[new_idx]){
                new_idx = (new_idx + 7) % 52;
            }

            if (!visited_[new_idx]) {
                visited_[new_idx] = true;
                hand_.push_back(default_tab_[new_idx]);
                left_ -= 1;
            }
        }
    }

    Cards take_card(bool *need_to_shuffle){
        if(hand_.size() > 10){
            *need_to_shuffle = true;
        }
        if(hand_.size() > 0) {
            Cards tmp = hand_[hand_.size()-1];
            hand_.pop_back();
            return tmp;
        }
        else{
            return Cards("error","error",100,100);
        }
    }

private:
    std::vector<Cards> hand_;
    Cards default_tab_[52] = {
            Cards("as", "pik", 11, 0),
            Cards("as", "kier", 11, 1),
            Cards("as", "trefl", 11, 2),
            Cards("as", "karo", 11, 3),

            Cards("krol", "pik", 10, 4),
            Cards("krol", "kier", 10, 5),
            Cards("krol", "trefl", 10, 6),
            Cards("krol", "karo", 10, 7),

            Cards("dama", "pik", 10, 8),
            Cards("dama", "kier", 10, 9),
            Cards("dama", "trefl", 10, 10),
            Cards("dama", "karo", 10, 11),

            Cards("walet", "pik", 10, 12),
            Cards("walet", "kier", 10, 13),
            Cards("walet", "trefl", 10, 14),
            Cards("walet", "karo", 10, 15),

            Cards("10", "pik", 10, 16),
            Cards("10", "kier", 10, 17),
            Cards("10", "trefl", 10, 18),
            Cards("10", "karo", 10, 19),

            Cards("9", "pik", 10, 20),
            Cards("9", "kier", 10, 21),
            Cards("9", "trefl", 10, 22),
            Cards("9", "karo", 10, 23),

            Cards("8", "pik", 8, 24),
            Cards("8", "kier", 8, 25),
            Cards("8", "trefl", 8, 26),
            Cards("8", "karo", 8, 27),

            Cards("7", "pik", 7, 28),
            Cards("7", "kier", 7, 29),
            Cards("7", "trefl", 7, 30),
            Cards("7", "karo", 7, 31),

            Cards("6", "pik", 6, 32),
            Cards("6", "kier", 6, 33),
            Cards("6", "trefl", 6, 34),
            Cards("6", "karo", 6, 35),

            Cards("5", "pik", 5, 36),
            Cards("5", "kier", 5, 37),
            Cards("5", "trefl", 5, 38),
            Cards("5", "karo", 5, 39),

            Cards("4", "pik", 4, 40),
            Cards("4", "kier", 4, 41),
            Cards("4", "trefl", 4, 42),
            Cards("4", "karo", 4, 43),

            Cards("3", "pik", 3, 44),
            Cards("3", "kier", 3, 45),
            Cards("3", "trefl", 3, 46),
            Cards("3", "karo", 3, 47),

            Cards("2", "pik", 3, 48),
            Cards("2", "kier", 3, 49),
            Cards("2", "trefl", 3, 50),
            Cards("2", "karo", 3, 51)};
};

#endif //CARDS_HPP
