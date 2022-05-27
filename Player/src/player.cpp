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
    return rand_card;
}

bool can_split() {
    if player_cards_[0].give_value() == player_cards_[1].give_value()
    {
        return true;
    }
    else{
        return false;
    }
}

bool is_blackjack(){
    if (player_cards_.give_sum() == 21){
        return true;
    }
    else{
        return false;
    }
}
void show_cards(){
    for (auto elem : player_cards)
}