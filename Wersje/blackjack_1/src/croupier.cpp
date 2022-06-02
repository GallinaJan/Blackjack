//
// Created by Jakub on 02.06.2022.
//
#include "croupier.hpp"

void croupier_move(Croupier& croupier){
    while(croupier.give_sum() < 17){
        croupier.give_card();
    }
}
