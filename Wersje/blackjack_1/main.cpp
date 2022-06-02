#include <iostream>
#include <string>
#include "player.hpp"
#include "croupier.hpp"
#include "cards.hpp"
#include "cleaning.hpp"

void play(Croupier& croupier, Player& player);
void play_again(Player& player, Croupier& croupier);

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
        play(croupier, player);
        while(player.get_money() > -1){
            std::cout << "If you want to play again, type \"Y\", if you want to quit, type \"N\"" << std::endl;
            std::cin >> start;
            if(start == "N" || start == "n") {
                return 0;
            }
            if(start == "Y" || start == "y") {
                play(croupier, player);
            }
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
    if(bid - player.get_money() > -1 && bid !=0){
        player.take_money(bid);
        croupier.add_money(bid);
        croupier.give_card();
        croupier.give_card();
        croupier.hide_second();
        player.give_card();
        player.give_card();
        show_current_status(croupier, player);
        if(player.is_blackjack()){
            std::cout<<"You've got blackjack!"<<std::endl;
            player.win_money(bid * 2);
        }
        if(player.can_split()){
            std::string choice;
            std::cout<<"Do you want to hit, stand or split?"<<std::endl;
            std::cin>>choice;
            if(choice == "hit"){
                player.give_card();
                play_again(player,croupier);
            }
            if(choice == "stand"){
                croupier.show_second();
                croupier_move(croupier);
                if (player.give_sum() > croupier.give_croupier_sum()) {
                    std::cout << "You have won!" << std::endl;
                    player.win_money(bid * 2);
                    cleaning_function(croupier, player);
                }
                if (player.give_sum() == croupier.give_croupier_sum()) {
                    std::cout << "Draw" << std::endl;
                    player.win_money(bid);
                    cleaning_function(croupier, player);
                }
            }
            if(choice == "split"){
                player.take_money(bid);
                player.hide_second();
                player.give_card();
                play_again(player, croupier);
                player.show_second();
                player.give_card();
                play_again(player, croupier);
                cleaning_function(croupier, player);
            }
        }
        if(croupier.has_ace_as_first()){
            std::string choice;
            std::cout<<"Do you want to hit, stand or insurance?"<<std::endl;
            std::cin>>choice;
            if (choice == "hit"){
                player.give_card();
                play_again(player,croupier);
                cleaning_function(croupier, player);
            }
            if (choice == "stand") {
                croupier.show_second();
                croupier_move(croupier);
                if (player.give_sum() > croupier.give_croupier_sum()) {
                    std::cout << "You have won!" << std::endl;
                    player.win_money(bid * 2);
                    cleaning_function(croupier, player);
                }
                if (player.give_sum() == croupier.give_croupier_sum()) {
                    std::cout << "Draw" << std::endl;
                    player.win_money(bid);
                    cleaning_function(croupier, player);
                }
            }
            else {
                std::cout<<"You have lost"<<std::endl;
                cleaning_function(croupier, player);
            }
        }
            if (choice == "insurance"){
                player.take_money(int(bid*0.5));
                if(croupier.is_blackjack()) {
                    player.win_money(bid);
                }
            }
        }
        else{
            if(player.give_sum() > 21) {
                std::cout<<"You have lost"<<std::endl;
                cleaning_function(croupier, player);
            }
            std::string choice;
            std::cout<<"Do you want to hit, stand or insurance?"<<std::endl;
            std::cin>>choice;
            if (choice == "hit"){
                player.give_card();
                play_again(player,croupier);
                cleaning_function(croupier, player);
            }
            if (choice == "stand"){
                croupier.show_second();
                croupier_move(croupier);
                if(player.give_sum() > croupier.give_croupier_sum()) {
                    std::cout<<"You have won!"<<std::endl;
                    player.win_money(bid * 2);
                    cleaning_function(croupier, player);
                }
                if(player.give_sum() == croupier.give_croupier_sum()) {
                    std::cout <<"Draw"<< std::endl;
                    player.win_money(bid);
                    cleaning_function(croupier, player);
                }
                else {
                    std::cout<<"You have lost"<<std::endl;
                    cleaning_function(croupier, player);
                }
            }
            if (choice == "double"){
                player.take_money(bid);
                play_again(player,croupier);
                cleaning_function(croupier, player);
            }
        }
}

void play_again(Player& player, Croupier& croupier){
    std::string choice;
    std::cout<<"Do you want to hit or stand?"<<std::endl;
    std::cin>>choice;
    if (choice == "hit"){
        player.give_card();
        play_again(player,croupier);
    }
    if (choice == "stand"){
        croupier.show_second();
        croupier_move(croupier);
        if(player.give_sum() > croupier.give_croupier_sum()) {
            std::cout<<"You have won!"<<std::endl;
            player.win_money(bid * 2);
        }
        if(player.give_sum() == croupier.give_croupier_sum()) {
            std::cout <<"Draw"<< std::endl;
            player.win_money(bid);
        }
        else {
            std::cout<<"You have lost"<<std::endl;
        }
    }
}
