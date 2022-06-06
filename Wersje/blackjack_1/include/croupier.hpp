#ifndef INCLUDE_CROUPIER_HPP_
#define INCLUDE_CROUPIER_HPP_

#include "cards.hpp"
#include <iostream>
#include <string>
#include "player.hpp"
#include <cstdlib>
#include <ctime>
#include <chrono>

class Croupier {
public:
    //Dodaje do ręki croupiera nową karte z talii
    void give_card(bool *need_to_shuffle) { croupier_cards_.push_back(cards_on_table_.take_card(need_to_shuffle)); }

    //umożliwia wypisanie drugiej karty po turze gracza
    void show_second() { show_second_ = true; }

    //usuwa całą rękę croupiera po zakończonym rozdaniu
    void clean_hand() {
        croupier_cards_.clear();
        show_second_ = false;
    }


    void show_cards() {
        std::cout << "Karty krupiera: " << std::endl;
        if (show_second_) {
            for (auto i: croupier_cards_) {
                std::cout << i.give_name() << " " << i.give_suit() << std::endl;
            }
        } else {
            std::cout << croupier_cards_[0].give_name() << " " << croupier_cards_[0].give_suit() << std::endl;
        }
    }

    bool is_blackjack() {
        if (has_ace_as_first() && (croupier_cards_[1].give_name() == "walet" || croupier_cards_[1].give_name() == "dama" ||
                                   croupier_cards_[1].give_name() == "krol")) {
            return true;
        }
        return false;
    }

    bool has_ace_as_first() {
        if (croupier_cards_[0].give_name() == "as") {
            return true;
        }
        else {
            return false;
        }
    }

    int give_croupier_sum() {
        int ace_number = 0;
        int sum = 0;
        for (auto elem: croupier_cards_) {
            if (elem.give_id() == 0 || elem.give_id() == 1 || elem.give_id() == 2 || elem.give_id() == 3) {
                ace_number += 1;
            }
        }
        for (auto elem: croupier_cards_) {
            if (elem.give_id() != 0 && elem.give_id() != 1 && elem.give_id() != 2 && elem.give_id() != 3) {
                if (
                        elem.give_id() == 4 ||
                        elem.give_id() == 5 ||
                        elem.give_id() == 6 ||
                        elem.give_id() == 7 ||
                        elem.give_id() == 8 ||
                        elem.give_id() == 9 ||
                        elem.give_id() == 10 ||
                        elem.give_id() == 11 ||
                        elem.give_id() == 12 ||
                        elem.give_id() == 13 ||
                        elem.give_id() == 14 ||
                        elem.give_id() == 15
                        ) {
                    sum += 10;
                } else {
                    sum += int(elem.give_value());
                }
            }
            if (ace_number != 0) {
                if ((sum + 10 + ace_number) <= 21) {
                    sum += (10 + ace_number);
                } else {
                    sum += ace_number;
                }
            }
        }
        return sum;
    }
private:
    Hand cards_on_table_;
    std::vector<Cards> croupier_cards_;
    bool show_second_ = false;
};



#endif //*INCLUDE_CROUPIER_HPP_