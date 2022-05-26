#include "player.h"
#include <cstdlib>

Cards give_card(){
    int number = rand() % 52 + 1;
    Cards rand_card;
    for (auto cards_list : elem){
        if (elem.give_number() = number){
            rand_card = elem;
        }
    }
    return rand_cart;
}

bool can_split() {
    if card1.give_value() == card2.give_value()
    {
        return true;
    }
    else{
        return false;
    }
}

bool is_blackjack(){
    if (card1.give_value() == 10 and card2.give_value() == 11 or
    card1.give_value() == 11 and card2.give_value() == 10){
        return true;
    }
    else{
        return false;
    }
}