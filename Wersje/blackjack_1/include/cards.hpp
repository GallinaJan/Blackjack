#ifndef CARDS_HPP
#define CARDS_HPP

#include <iostream>
#include <string>
#include "player.hpp"
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "rand_idx.hpp"

//srand(static_cast<unsigned int>(time(NULL)));

class Cards {
public:
    Cards() = default;

    Cards(std::string name, std::string suit, std::size_t value, std::size_t id) :
            name_(name), suit_(suit), value_(value), id_(id) {}

    std::string give_name() { return name_; }

    std::string give_suit() { return suit_; }

    std::size_t give_value() { return value_; }

    std::size_t give_id() { return id_; }

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
            int new_idx = get_idx();
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
            Cards("Ace", "Hearts", 11, 0),
            Cards("Ace", "Diamonds", 11, 1),
            Cards("Ace", "Spades", 11, 2),
            Cards("Ace", "Clubs", 11, 3),

            Cards("King", "Hearts", 10, 4),
            Cards("King", "Diamonds", 10, 5),
            Cards("King", "Spades", 10, 6),
            Cards("King", "Clubs", 10, 7),

            Cards("Queen", "Hearts", 10, 8),
            Cards("Queen", "Diamonds", 10, 9),
            Cards("Queen", "Spades", 10, 10),
            Cards("Queen", "Clubs", 10, 11),

            Cards("Jack", "Hearts", 10, 12),
            Cards("Jack", "Diamonds", 10, 13),
            Cards("Jack", "Spades", 10, 14),
            Cards("Jack", "Clubs", 10, 15),

            Cards("10", "Hearts", 10, 16),
            Cards("10", "Diamonds", 10, 17),
            Cards("10", "Spades", 10, 18),
            Cards("10", "Clubs", 10, 19),

            Cards("9", "Hearts", 10, 20),
            Cards("9", "Diamonds", 10, 21),
            Cards("9", "Spades", 10, 22),
            Cards("9", "Clubs", 10, 23),

            Cards("8", "Hearts", 8, 24),
            Cards("8", "Diamonds", 8, 25),
            Cards("8", "Spades", 8, 26),
            Cards("8", "Clubs", 8, 27),

            Cards("7", "Hearts", 7, 28),
            Cards("7", "Diamonds", 7, 29),
            Cards("7", "Spades", 7, 30),
            Cards("7", "Clubs", 7, 31),

            Cards("6", "Hearts", 6, 32),
            Cards("6", "Diamonds", 6, 33),
            Cards("6", "Spades", 6, 34),
            Cards("6", "Clubs", 6, 35),

            Cards("5", "Hearts", 5, 36),
            Cards("5", "Diamonds", 5, 37),
            Cards("5", "Spades", 5, 38),
            Cards("5", "Clubs", 5, 39),

            Cards("4", "Hearts", 4, 40),
            Cards("4", "Diamonds", 4, 41),
            Cards("4", "Spades", 4, 42),
            Cards("4", "Clubs", 4, 43),

            Cards("3", "Hearts", 3, 44),
            Cards("3", "Diamonds", 3, 45),
            Cards("3", "Spades", 3, 46),
            Cards("3", "Clubs", 3, 47),

            Cards("2", "Hearts", 3, 48),
            Cards("2", "Diamonds", 3, 49),
            Cards("2", "Spades", 3, 50),
            Cards("2", "Clubs", 3, 51)} ;
};

#endif //CARDS_HPP
