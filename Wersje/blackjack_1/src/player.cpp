#include "player.hpp"
#include <cstdlib>

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
void show_cards(){
    for (auto elem : player_cards)
}
