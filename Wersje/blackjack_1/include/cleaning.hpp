#ifndef MAIN_CPP_CLEANING_HPP
#define MAIN_CPP_CLEANING_HPP
#include "croupier.hpp"
#include "player.hpp"

void cleaning_function(Croupier& croupier, Player& player, bool* need_to_shuffle, Hand* hand) {
    croupier.clean_hand();
    player.clean_hand();
    if(need_to_shuffle){
        Hand new_hand;
        *hand = new_hand;
    }
}
void show_current_status(Croupier& croupier, Player& player) {
    croupier.show_cards();
    player.show_cards();
}
#endif //MAIN_CPP_CLEANING_HPP
