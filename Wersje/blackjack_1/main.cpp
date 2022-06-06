#include <iostream>
#include <string>
#include "player.hpp"
#include "croupier.hpp"
#include "cards.hpp"
#include "cleaning.hpp"
#include <cstdlib>
#include <ctime>
#include <chrono>



void play(Croupier &croupier, Player &player, bool *need_to_shuffle, Hand *hand); //funkcja rozpoczynajaca gre
void play_again(Player &player, Croupier &croupier, bool *need_to_shuffle, Hand *hand, int bid); //funkcja pozwalajaca a kolejne ruchy

int main() {
    bool false_ = false;
    bool *need_to_shuffle = &false_;
    //poczatek gry
    std::string start;
    std::cout << "Hello, if you want to play, type \"Y\", if you want to quit, type \"N\"" << std::endl;
    std::cin >> start;
    if (start == "N" || start == "n") {
        return 0; //koniec gry
    }
    if (start == "Y" || start == "y") {
        //nowa gra
        Croupier croupier; //utowrzenie instancji krupiera
        Player player; //utworzenie instancji gracza
        Hand hand;
        play(croupier, player, need_to_shuffle, &hand); //rozpoczacie rozgrywki
        while (player.get_money() > -1) { //warunek rozpoczecia gry, stan konta dodatni
            std::cout << "If you want to play again, type \"Y\", if you want to quit, type \"N\"" << std::endl;
            std::cin >> start;
            if (start == "N" || start == "n") {
                return 0;
            }
            if (start == "Y" || start == "y") {
                play(croupier, player, need_to_shuffle, &hand); //kontynuowanie rozgrywki
            }
        }
    } else {
        return -1;
    }
    return 0;
}

void play(Croupier &croupier, Player &player, bool *need_to_shuffle, Hand *hand) {
    int bid = 0;
    std::cout << "How much money do you bid?" << std::endl;
    std::cin >> bid; //stawka gracza
    if (player.get_money() - bid > -1 && bid != 0) { //warunek czy saldo dodatnie
        player.take_money(bid); //zabranie pieniedzy graczowi
        croupier.give_card(need_to_shuffle);
        croupier.give_card(need_to_shuffle); //dodanie to reki krupiera dwoch kart
        player.give_card(need_to_shuffle);
        player.give_card(need_to_shuffle); //dodanie dwoch kart graczowi
        show_current_status(croupier, player); //wypisanie na ekran kart gracza i jednej karty krupiera
        if (player.is_blackjack()) { //sprawdzenie czy gracz wygral blackjackiem
            std::cout << "You've got blackjack!" << std::endl;
            player.win_money(bid * 2); //gracz wygrywa dwukrotnosc posatwionych pieniedzy
        }
        if (player.can_split()) { //sprawdzenie czy gracz moze rozdzielic
            std::string choice;
            std::cout << "Do you want to hit, stand or split?" << std::endl;
            std::cin >> choice;
            if (choice == "hit") {
                player.give_card(need_to_shuffle);
                show_current_status(croupier, player);
                play_again(player, croupier, need_to_shuffle,
                           hand, bid); //pobiera karte wypisuje ja na ekran i daje wybor co dalej
            }
            if (choice == "stand") {
                croupier.show_second();
                show_current_status(croupier, player); //pokazuje zakryta wczesniej karte krupiera
                croupier_move(croupier, player, need_to_shuffle); //krupier wykonuje ruch
                show_current_status(croupier, player); //wypisuje na ekran stan po ruchahc krupiera
                if (player.give_player_sum() > croupier.give_croupier_sum()) { //sprawdza kto wygral
                    std::cout << "You have won!" << std::endl;
                    player.win_money(bid * 2);
                    cleaning_function(croupier, player, need_to_shuffle, hand); //zabiera karty krupierowi i graczowi
                }
                if (player.give_player_sum() == croupier.give_croupier_sum()) {
                    std::cout << "Draw" << std::endl;
                    player.win_money(bid); //remis gracz otrzymuje tyle ile posatwil
                    cleaning_function(croupier, player, need_to_shuffle, hand);
                }
            }
            /*if (choice == "split") {
                player.take_money(bid); //podawjana stawka
                player.hide_second(); //zakrywa karte garczowi zeby grac tylko na pierwszej
                player.give_card(need_to_shuffle); //dodaje do pierwszej karty druga
                show_current_status(croupier, player); //pokazuje obie
                play_again(player, croupier, need_to_shuffle, &hand, bid); //gra mini gre jeszcze raz
                player.show_second(); //gra druga gre
                player.give_card(need_to_shuffle);
                show_current_status(croupier, player); //pokazuje karty
                play_again(player, croupier, need_to_shuffle, &hand, bid); //decyzja garcza
                cleaning_function(croupier, player, need_to_shuffle, &hand);
            }*/
        }
        if (croupier.has_ace_as_first()) { //sprawdza czy mozna ubezpieczyc
            std::string choice;
            std::cout << "Do you want to hit, stand or insurance?" << std::endl;
            std::cin >> choice;
            if (choice == "hit") { //gra dalej
                player.give_card(need_to_shuffle);
                show_current_status(croupier, player);
                play_again(player, croupier, need_to_shuffle, hand, bid);
                cleaning_function(croupier, player, need_to_shuffle, hand);
            }
            if (choice == "stand") { //konczy gre
                croupier.show_second();
                show_current_status(croupier, player);
                croupier_move(croupier, player, need_to_shuffle);
                show_current_status(croupier, player);
                if (player.give_player_sum() > croupier.give_croupier_sum()) {
                    std::cout << "You have won!" << std::endl;
                    player.win_money(bid * 2);
                    cleaning_function(croupier, player, need_to_shuffle, hand);
                }
                if (player.give_player_sum() == croupier.give_croupier_sum()) {
                    std::cout << "Draw" << std::endl;
                    player.win_money(bid);
                    cleaning_function(croupier, player, need_to_shuffle, hand);
                } else {
                    std::cout << "You have lost" << std::endl;
                    cleaning_function(croupier, player, need_to_shuffle, hand);
                }
            }
            if (choice == "insurance") {
                player.take_money(int(bid * 0.5)); //pobieranie polowy z oplaty
                play_again(player, croupier, need_to_shuffle, hand, bid);
                if (croupier.is_blackjack()) { //sprawdza czy krupier ma blackjacka
                    std::cout << "Croupier has blackjack, you have won an insurance" << std::endl;
                    player.win_money(bid); //wyplaca ubezpieczenie
                }
                cleaning_function(croupier, player, need_to_shuffle, hand);
            }
        } else { //zwyczajna rozgrywka
            if (player.give_player_sum() > 21) { //przegrywa
                std::cout << "You have lost" << std::endl;
                cleaning_function(croupier, player, need_to_shuffle, hand);
            }
            std::string choice;
            std::cout << "Do you want to hit, stand or double?" << std::endl;
            std::cin >> choice;
            if (choice == "hit") { //graj dalej
                player.give_card(need_to_shuffle);
                show_current_status(croupier, player);
                play_again(player, croupier, need_to_shuffle, hand, bid);
                cleaning_function(croupier, player, need_to_shuffle, hand);
            }
            if (choice == "stand") { //koniec dobierania kart
                croupier.show_second();
                show_current_status(croupier, player);
                croupier_move(croupier, Player(), nullptr);
                show_current_status(croupier, player);
                if (player.give_player_sum() > croupier.give_croupier_sum()) {
                    std::cout << "You have won!" << std::endl;
                    player.win_money(bid * 2);
                    cleaning_function(croupier, player, need_to_shuffle, hand);
                }
                if (player.give_player_sum() == croupier.give_croupier_sum()) {
                    std::cout << "Draw" << std::endl;
                    player.win_money(bid);
                    cleaning_function(croupier, player, need_to_shuffle, hand);
                } else {
                    std::cout << "You have lost" << std::endl;
                    cleaning_function(croupier, player, need_to_shuffle, hand);
                }
            }
            if (choice == "double") { //podwoj stawke
                player.take_money(bid);
                play_again(player, croupier, need_to_shuffle, hand, 2 * bid);
                cleaning_function(croupier, player, need_to_shuffle, hand);
            }
        }
    }
}

void play_again(Player &player, Croupier &croupier, bool *need_to_shuffle, Hand *hand, int bid) {
    if (player.give_player_sum() > 21){ //sprawdza czy nie przekroczylo 21
        std::cout << "You have lost" << std::endl;
        return;
    }
    std::string choice;
    std::cout << "Do you want to hit or stand?" << std::endl;
    std::cin >> choice;
    if (choice == "hit") { //dobiera karty dalej
        player.give_card(need_to_shuffle);
        show_current_status(croupier, player);
        play_again(player, croupier, need_to_shuffle, hand, bid);
        return;
    }
    if (choice == "stand") { //konczy dobieranie, sprawdza stan gry
        croupier.show_second();
        show_current_status(croupier, player);
        croupier_move(croupier, Player(), nullptr);
        show_current_status(croupier, player);
        if (player.give_player_sum() > croupier.give_croupier_sum()) {
            std::cout << "You have won!" << std::endl;
            player.win_money(bid * 2);
        }
        if (player.give_player_sum() == croupier.give_croupier_sum()) {
            std::cout << "Draw" << std::endl;
            player.win_money(bid);
        } else {
            std::cout << "You have lost" << std::endl;
        }
    }
}
