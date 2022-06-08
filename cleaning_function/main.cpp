void cleaning_function(Croupier &croupier, Player &player, bool *need_to_shuffle, Hand *hand) {
    croupier.clean_hand();
    player.clean_hand();
    if (*need_to_shuffle) {
        Hand new_hand;
        *hand = new_hand;
    }
}
