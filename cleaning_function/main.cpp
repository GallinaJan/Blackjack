#include "cleaning.hpp"

void cleaning_function(Croupier& croupier, Player& player) {
    show_current_status(croupier, player)
    croupier.clear_table
    croupier.clear_cards
    player.clear_cards
    continue
}
void show_current_status(Croupier& croupier, Player& player) {
    croupier.show_cards();
    player.show_cards();
}
