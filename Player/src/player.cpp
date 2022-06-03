#include "player.h"
#include <cstdlib>
#include <iostream>


int Player::give_player_sum() {
    int ace_number = 0;
    int sum = 0;
    for (auto elem: player_cards_) {
        if (elem.give_id() == 13 || elem.give_id() == 26 || elem.give_id() == 39 || elem.give_id() == 52) {
            ace_number += 1;
        }
    }
    for (auto elem: player_cards_) {
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
                sum += 1 + (elem.give_id()) % 13;
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
}


bool Player::can_split() {
    if player_cards_[0].give_value() == player_cards_[1].give_value()
    {
        return true;
    }
    else{
        return false;
    }
}

bool Player::is_blackjack(){
    if (player_cards_.give_sum() == 21){
        return true;
    }
    else{
        return false;
    }
}
void Player::show_cards(){
    std::cout<<"Karty gracza: "<<endl;
    for (auto elem : player_cards_){
        std::cout<<elem.give_name() << elem.give_suit() << elem.give_value() <<endl;
    }
}