#include "player.hpp"
#include <cstdlib>
#include "cleaning.hpp"
#include <map>
#include <vector>
#include "cards.hpp"

bool Croupier::has_ace_as_first() {
    if (croupier_cards_[0].give_name() == "as") {
        return true;
    }
    else {
        return false;
    }
}

int Croupier::give_croupier_sum() {
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


bool Croupier::is_blackjack() {
    if (has_ace_as_first() && (croupier_cards_[1].give_name() == "walet" || croupier_cards_[1].give_name() == "dama" ||
                               croupier_cards_[1].give_name() == "krol")) {
        return true;
    }
    return false;
}

void croupier_move(Croupier &croupier) {
    int keep_playing = 17;
    int player_sum = Player::give_sum();
    if (player_sum >= keep_playing) {
        keep_playing = player_sum;
    }
    while (croupier.give_croupier_sum() <= keep_playing) {
        croupier.give_card();
    }
}
