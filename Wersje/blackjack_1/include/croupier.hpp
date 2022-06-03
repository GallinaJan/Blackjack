#ifndef INCLUDE_CROUPIER_HPP_
#define INCLUDE_CROUPIER_HPP_

#include <vector>
#include <stdio.h>
#include "cards.hpp"

class Croupier {
public:
    void give_card(bool *need_to_shuffle) { croupier_cards_.push_back(cards_on_table_.take_card(need_to_shuffle)); }

    void show_second() { show_second_ = true; }

    void clean_hand() {
        croupier_cards_.clear();
        show_second_ = false;
    }

    void show_cards() {
        if (show_second_) {
            for (auto i: croupier_cards_) {
                std::cout << i.give_name() << " " << i.give_suit() << std::endl;
            }
        } else {
            std::cout << croupier_cards_[0].give_name() << " " << croupier_cards_[0].give_suit() << std::endl;
        }
    }

    bool is_blackjack();

    bool has_ace_as_first();

    int give_croupier_sum();

private:
    Hand cards_on_table_;
    std::vector<Cards> croupier_cards_;
    bool show_second_ = false;
};

void croupier_move(Croupier &croupier);

#endif //*INCLUDE_CROUPIER_HPP_