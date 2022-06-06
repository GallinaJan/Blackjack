#ifndef PLAYER_PLAYER_H
#define PLAYER_PLAYER_H

#include <map>
#include <vector>
#include <algorithm>
#include "cards.hpp"

class Player {
public:
    void give_card(bool *need_to_shuffle) { player_cards_.push_back(cards_on_table_.take_card(need_to_shuffle)); }

    void take_money(int x) { my_money_ = my_money_ - x; }

    void show_cards() {
        std::cout << "Karty gracza: " << std::endl;
        for (auto elem: player_cards_) {
            std::cout << elem.give_name() << " " << elem.give_suit() << std::endl;
        }
    }

    int give_player_sum() {
        int ace_number = 0;
        int sum = 0;
        for (auto elem: player_cards_) {
            if (elem.give_id() == 0 || elem.give_id() == 1 || elem.give_id() == 2 || elem.give_id() == 3) {
                ace_number += 1;
            }
        }
        for (auto elem: player_cards_) {
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

    bool is_blackjack() {
        if (player_cards_[0].give_name() == "as" &&
            (player_cards_[1].give_name() == "walet" || player_cards_[1].give_name() == "dama" ||
             player_cards_[1].give_name() == "krol")) {
            return true;
        }
        if (player_cards_[1].give_name() == "as" &&
            (player_cards_[0].give_name() == "walet" || player_cards_[0].give_name() == "dama" ||
             player_cards_[0].give_name() == "krol")) {
            return true;
        } else {
            return false;
        }
    }


    void clean_hand() { player_cards_.clear(); }

    bool can_split() {
        if (player_cards_[0].give_value() == player_cards_[1].give_value()) {
            return true;
        } else {
            return false;
        }
    }

    std::size_t give_cards_id(Cards &card) { return card.give_id(); }

    void hide_second(Cards &card_2) { hidden_card_ = card_2; }

    void show_second() { player_cards_.push_back(hidden_card_); }

    void win_money(int prize) { my_money_ = my_money_ + prize; }

    int get_money() { return my_money_; }

private:
    int my_money_ = 5000;
    std::vector<Cards> player_cards_;
    int sum_ = 0;
    Cards hidden_card_;
    Hand cards_on_table_;
};

#endif //PLAYER_PLAYER_H