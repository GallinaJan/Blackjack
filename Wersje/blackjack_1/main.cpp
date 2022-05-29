#include <iostream>
#include <stdio.h>
#include "player.hpp"
#include "croupier.hpp"
#include "cards.hpp"
#include "cleaning.hpp"

int main() {
    std::string start;
    std::cout << "Hello, if you want to play, type \"Y\", if you want to quit, type \"N\"" << std::endl;
    std::cin >> start;
    if(start == "N" || start == "n"){
        return 0;
    }
    if(start == "Y" || start == "y"){
        Croupier croupier;
        Player player;
        while(player.get_money() > -1){
            int bid = 0;
            std::cout<<"How much money do you bid?"<<std::endl;
            std::cin>>bid;
            while(bid - player.get_money() > -1 && bid !=0) {
                player.take_money(bid);
                croupier.add_money(bid);
                croupier.give_card();
                croupier.give_card();
                //croupier.hide_second();
                player.give_card();
                player.give_card();
                //show_current_status(croupier, player);
            }
        }
    }
    else{
        return -1;
    }
    return 0;
}
