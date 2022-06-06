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
    void give_card(bool *need_to_shuffle) { croupier_cards_.push_back(cards_on_table_.take_card(need_to_shuffle)); }

    void show_second() { show_second_ = true; }

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
            if (elem.give_id() == 13 || elem.give_id() == 26 || elem.give_id() == 39 || elem.give_id() == 52) {
                ace_number += 1;
            }
        }
        for (auto elem: croupier_cards_) {
            if (elem.give_id() != 13 && elem.give_id() != 26 && elem.give_id() != 39 && elem.give_id() != 52) {
                if (
                        elem.give_id() == 10 ||
                        elem.give_id() == 11 ||
                        elem.give_id() == 12 ||
                        elem.give_id() == 23 ||
                        elem.give_id() == 24 ||
                        elem.give_id() == 25 ||
                        elem.give_id() == 36 ||
                        elem.give_id() == 37 ||
                        elem.give_id() == 38 ||
                        elem.give_id() == 49 ||
                        elem.give_id() == 50 ||
                        elem.give_id() == 51
                        ) {
                    sum += 10;
                } else {
                    sum += 1 + (int(elem.give_id())) % 13;
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
        return 0;
    }

private:
    Hand cards_on_table_;
    std::vector<Cards> croupier_cards_;
    bool show_second_ = false;
};



#endif //*INCLUDE_CROUPIER_HPP_