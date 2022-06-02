#include <iostream>
#include <string>
#include "player.hpp"
#include "croupier.hpp"
#include "cards.hpp"
#include "cleaning.hpp"

void play(Croupier& croupier, Player& player);
void play_again();

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
            play(croupier, player);
        }
    }
    else{
        return -1;
    }
    return 0;
}

void play(Croupier& croupier, Player& player){
    int bid = 0;
    std::cout<<"How much money do you bid?"<<std::endl;
    std::cin>>bid;
    if(bid - player.get_money() > -1 && bid !=0) {
        player.take_money(bid);
        croupier.add_money(bid);
        croupier.give_card();
        croupier.give_card();
        //croupier.hide_second();
        player.give_card();
        player.give_card();
        //show_current_status(croupier, player);
        if(player.is_blackjack()){
            std::cout<<"You've got blackjack!"<<std::endl;
            //player.win_money(bid * 2);
        }
        if(player.can_split()){
            std::string choice;
            std::cout<<"Do you want to hit, stand or split?"<<std::endl;
            std::cin>>choice;
            if(choice == "hit"){
                //
            }
            if(choice == "stand"){
                //
            }
            if(choice == "split"){
                //
            }
        }
        if(/*croupier.has_ace*/){
            std::string choice;
            std::cout<<"Do you want to hit, stand or insurance?"<<std::endl;
            std::cin>>choice;
            if (choice == "hit"){
                //
            }
            if (choice == "stand"){
                //
            }
            if (choice == "insurance"){
                //
            }
        }
        else{
            again_default:
            if(player.give_sum() > 21) {
                cleaning_function();
            }
            std::string choice;
            std::cout<<"Do you want to hit, stand or insurance?"<<std::endl;
            std::cin>>choice;
            if (choice == "hit"){
                player.give_card();
                play_again();
            }
            if (choice == "stand"){
                croupier.show_second();
                //croupier_move();
                if(player.give_sum() > croupier.give_sum()) {
                    std::cout<<"You have won!"<<std::endl;
                    player.win_money(bid * 2);
                    cleaning_function();
                }
                if(player.give_sum() == croupier.give_sum()) {
                    std::cout <<"Draw"<< std::endl;
                    player.win_money(bid);
                }
                else {
                    std::cout<<"You have lost"<<std::endl;
                    cleaning_function();
                }
            }
            if (choice == "double"){
                player.take_money(bid);
                play_again();
            }
            }
        }
    }
    return;
}

void play_again(){
    std::string choice;
    std::cout<<"Do you want to hit, stand?"<<std::endl;
    std::cin>>choice;
    if (choice == "hit"){
        player.give_card();
        play_again();
    }
    if (choice == "stand") {
        croupier.show_second();
        //croupier_move();
        if (player.give_sum() > croupier.give_sum()) {
            std::cout << "You have won!" << std::endl;
            player.win_money(bid * 2);
        }
    }
}
