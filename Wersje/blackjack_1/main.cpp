#include <iostream>
#include <string>
#include "player.hpp"
#include "croupier.hpp"
#include "cards.hpp"

void play(Croupier &croupier, Player &player, bool *need_to_shuffle, Hand &hand, std::string difficulty); //funkcja rozpoczynajaca gre
void play_again(Player &player, Croupier &croupier, bool *need_to_shuffle, Hand &hand,
                int bid, std::string difficulty); //funkcja pozwalajaca a kolejne ruchy
void cleaning_function(Croupier &croupier, Player &player, bool *need_to_shuffle, Hand &hand) {
    croupier.clean_hand();
    player.clean_hand();
    if (need_to_shuffle) {
        Hand new_hand;
        hand = new_hand;
    }
}

void show_current_status(Croupier &croupier, Player &player) {
    croupier.show_cards();
    std::cout << std::endl;
    player.show_cards();
    std::cout << std::endl;
}

void croupier_move(Croupier &croupier, Player &player, bool *need_to_shuffle, std::string difficulty) {
    int keep_playing = 15;
    if(difficulty == "hard") {
        int player_sum = player.give_player_sum();
        if (player_sum >= keep_playing) {
            keep_playing = player_sum;
        }
    }
    while (croupier.give_croupier_sum() < keep_playing) {
        croupier.give_card(need_to_shuffle);
    }
}/*void split(Croupier& croupier, Player& player, bool* need_to_shuffle, Hand* hand, int bid) {
    player.take_money(bid);
    int potential_win1 = bid;
    int potential_win2 = bid;
    std::vector <Cards> secondhand;
    secondhand.push_back(player.get_player_cards().end()); //czy cos podobnego
    player.give_card(need_to_shuffle);
    show_current_status(croupier, player);
    show_secondhand_status();
    std::string choice;
    std::cout << "Do you want to hit, stand or double?" << std::endl;
    std::cin >> choice;
    if (choice == "double") {
        player.take_money(bid);
        player.give_card(need_to_shuffle);
        show_current_status(croupier, player);
        show_secondhand_status();
        potential_win1 += bid;
    } else {
        while (choice == "hit") {
            player.give_card(need_to_shuffle);
            std::cout << "Do you want to hit or stand?" << std::endl;
            std::cin >> choice;
        }
        // nie double
    }
    secondhand.give_card(need_to_shuffle);
    show_current_status(croupier, player);
    show_secondhand_status();
    std::cout << "hit, stand or double?" << std::endl;
    std::string choose;
    std::cin >> choose;
    if (choose == "double") {
        player.take_money(bid);
        secondhand.givecard(need_to_shuffle);
        show_current_status(croupier, player);
        show_secondhand_status();
        potential_win2 += bid;
    } else {
        while (choose == "hit") {
            secondhand.givecard(need_to_shuffle);
            std::cout << "Do you want to hit or stand?" << std::endl;
            std::cin >> choose;
        }
        // nie double
    }

//    croupiermove z uwzglednieniem obu rak( nie wiem z czego minimum chcecie dla krupiera)

    if (player.give_player_sum() > croupier.give_croupier_sum() || croupier.give_croupier_sum() > 21) {
        player.win_money(potential_win1 * 2);
        std::cout << "Your first hand wins!" << std::endl;
    } else if (player.give_player_sum() > croupier.give_croupier_sum()) {
        player.win_money(potential_win1);
        std::cout << "Your first hand draws." << std::endl;
    } else {
        std::cout << "Your first hand loses." << std::endl;
    }
    if (secondhand.give_sum > croupier.give_croupier_sum() || croupier.give_croupier_sum() > 21) {
        player.win_money(potential_win2 * 2);
        std::cout << "Your second hand wins!" << std::endl;
    } else if (secondhand.give_sum > croupier.give_croupier_sum()) {
        player.win_money(potential_win1);
        std::cout << "Your second hand draws." << std::endl;
    } else {
        std::cout << "Your second hand loses." << std::endl;
    }

}*/

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
        std::string difficulty_level;
        std::cout << "Choose difficulty level you want to play. Type \"medium\" or \"hard\". " << std::endl;
        std::cin >> difficulty_level;
        int starting_money;
        std::cout << "Type amount of money on your starting account." << std::endl;
        std::cin >> starting_money;
        player.set_starting_money(starting_money);
        play(croupier, player, need_to_shuffle, hand, difficulty_level); //rozpoczacie rozgrywki
        while (player.get_money() > -1) { //warunek rozpoczecia gry, stan konta dodatni
            std::cout << "If you want to play again, type \"Y\", if you want to quit, type \"N\"" << std::endl;
            std::cin >> start;
            if (start == "N" || start == "n") {
                return 0;
            }
            if (start == "Y" || start == "y") {
                play(croupier, player, need_to_shuffle, hand, difficulty_level); //kontynuowanie rozgrywki
            }
        }
    } else {
        return -1;
    }
    return 0;
}

void play(Croupier &croupier, Player &player, bool *need_to_shuffle, Hand &hand, std::string difficulty) {
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
            player.win_money(int(bid * 2.5)); //gracz wygrywa dwukrotnosc posatwionych pieniedzy
            std::cout << "You've got blackjack! Account status: " << player.get_money() << std::endl;
            cleaning_function(croupier, player, need_to_shuffle, hand);
            return;
        }
        if (player.can_split()) { //sprawdzenie czy gracz moze rozdzielic
            std::string choice;
            std::cout << "Do you want to hit, stand or split?" << std::endl;
            std::cin >> choice;
            if (choice == "hit") {
                player.give_card(need_to_shuffle);
                show_current_status(croupier, player);
                play_again(player, croupier, need_to_shuffle,
                           hand, bid, difficulty); //pobiera karte wypisuje ja na ekran i daje wybor co dalej
            }
            if (choice == "stand") {
                croupier.show_second();
                show_current_status(croupier, player); //pokazuje zakryta wczesniej karte krupiera
                croupier_move(croupier, player, need_to_shuffle, difficulty); //krupier wykonuje ruch
                show_current_status(croupier, player); //wypisuje na ekran stan po ruchahc krupiera
                if (player.give_player_sum() > croupier.give_croupier_sum()) { //sprawdza kto wygral
                    player.win_money(bid * 2);
                    std::cout << "You have won! Account status: " << player.get_money() << std::endl;
                    cleaning_function(croupier, player, need_to_shuffle, hand); //zabiera karty krupierowi i graczowi
                    return;
                }
                if (player.give_player_sum() == croupier.give_croupier_sum()) {
                    player.win_money(bid); //remis gracz otrzymuje tyle ile posatwil
                    std::cout << "Draw, account status: " << player.get_money() << std::endl;
                    cleaning_function(croupier, player, need_to_shuffle, hand);
                    return;
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
                cleaning_function(croupier, player, need_to_shuffle, hand);
                return;
            }*/
        }
        if (croupier.has_ace_as_first() && player.get_money() >= int(bid * 0.5)) { //sprawdza czy mozna ubezpieczyc
            std::string choice;
            std::cout << "Do you want to hit, stand or insurance?" << std::endl;
            std::cin >> choice;
            if (choice == "hit") { //gra dalej
                player.give_card(need_to_shuffle);
                show_current_status(croupier, player);
                play_again(player, croupier, need_to_shuffle, hand, bid, difficulty);
                cleaning_function(croupier, player, need_to_shuffle, hand);
                return;
            }
            if (choice == "stand") { //konczy gre
                croupier.show_second();
                show_current_status(croupier, player);
                croupier_move(croupier, player, need_to_shuffle, difficulty);
                show_current_status(croupier, player);
                if (player.give_player_sum() > croupier.give_croupier_sum() || croupier.give_croupier_sum() > 21) {
                    player.win_money(bid * 2);
                    std::cout << "You have won! Account status: " << player.get_money() << std::endl;
                    cleaning_function(croupier, player, need_to_shuffle, hand);
                    return;
                }
                if (player.give_player_sum() == croupier.give_croupier_sum()) {
                    player.win_money(bid);
                    std::cout << "Draw, account status: " << player.get_money() << std::endl;
                    cleaning_function(croupier, player, need_to_shuffle, hand);
                    return;
                } else {
                    std::cout << "You have lost, account status: " << player.get_money() << std::endl;
                    cleaning_function(croupier, player, need_to_shuffle, hand);
                    return;
                }
            }
            if (choice == "insurance") {
                player.take_money(int(bid * 0.5)); //pobieranie polowy z oplaty
                play_again(player, croupier, need_to_shuffle, hand, bid, difficulty);
                if (croupier.is_blackjack()) { //sprawdza czy krupier ma blackjacka
                    player.win_money(bid); //wyplaca ubezpieczenie
                    std::cout << "Croupier has blackjack, you have won an insurance, account status: "
                              << player.get_money() << std::endl;
                }
                cleaning_function(croupier, player, need_to_shuffle, hand);
                return;
            }
        } else { //zwyczajna rozgrywka
            if (player.give_player_sum() > 21) { //przegrywa
                std::cout << "You have lost, account status: " << player.get_money() << std::endl;
                cleaning_function(croupier, player, need_to_shuffle, hand);
                return;
            }
            std::string choice;
            std::cout << "Do you want to hit, stand or double?" << std::endl;
            std::cin >> choice;
            if (choice == "hit") { //graj dalej
                player.give_card(need_to_shuffle);
                show_current_status(croupier, player);
                play_again(player, croupier, need_to_shuffle, hand, bid, difficulty);
                cleaning_function(croupier, player, need_to_shuffle, hand);
                return;
            }
            if (choice == "stand") { //koniec dobierania kart
                croupier.show_second();
                show_current_status(croupier, player);
                croupier_move(croupier, player, need_to_shuffle, difficulty);
                show_current_status(croupier, player);
                if (player.give_player_sum() > croupier.give_croupier_sum() || croupier.give_croupier_sum() > 21) {
                    player.win_money(bid * 2);
                    std::cout << "You have won! Account status: " << player.get_money() << std::endl;
                    cleaning_function(croupier, player, need_to_shuffle, hand);
                    return;
                }
                if (player.give_player_sum() == croupier.give_croupier_sum()) {
                    player.win_money(bid);
                    std::cout << "Draw, account status: " << player.get_money() << std::endl;
                    cleaning_function(croupier, player, need_to_shuffle, hand);
                    return;
                } else {
                    std::cout << "You have lost, account status: " << player.get_money() << std::endl;
                    cleaning_function(croupier, player, need_to_shuffle, hand);
                    return;
                }
            }
            if (choice == "double") { //podwoj stawke
                player.take_money(bid);
                player.give_card(need_to_shuffle);
                croupier.show_second();
                croupier_move(croupier, player, need_to_shuffle, difficulty);
                show_current_status(croupier, player);
                if (player.give_player_sum() > croupier.give_croupier_sum() || croupier.give_croupier_sum() > 21) {
                    player.win_money(bid * 4);
                    std::cout << "You have won! Account status: " << player.get_money() << std::endl;
                    cleaning_function(croupier, player, need_to_shuffle, hand);
                    return;
                }
                if (player.give_player_sum() == croupier.give_croupier_sum()) {
                    player.win_money(bid * 2);
                    std::cout << "Draw, account status: " << player.get_money() << std::endl;
                    cleaning_function(croupier, player, need_to_shuffle, hand);
                    return;
                } else {
                    std::cout << "You have lost, account status: " << player.get_money() << std::endl;
                    cleaning_function(croupier, player, need_to_shuffle, hand);
                    return;
                }
            }
        }
    }
}

void play_again(Player &player, Croupier &croupier, bool *need_to_shuffle, Hand &hand, int bid, std::string difficulty) {
    if (player.give_player_sum() > 21) { //sprawdza czy nie przekroczylo 21
        croupier.show_second();
        show_current_status(croupier, player);
        std::cout << "You have lost, account status: " << player.get_money() << std::endl;
        return;
    }
    std::string choice;
    std::cout << "Do you want to hit or stand?" << std::endl;
    std::cin >> choice;
    if (choice == "hit") { //dobiera karty dalej
        player.give_card(need_to_shuffle);
        show_current_status(croupier, player);
        play_again(player, croupier, need_to_shuffle, hand, bid, difficulty);
        return;
    }
    if (choice == "stand") { //konczy dobieranie, sprawdza stan gry
        croupier.show_second();
        show_current_status(croupier, player);
        croupier_move(croupier, player, need_to_shuffle, difficulty);
        show_current_status(croupier, player);
        if (player.give_player_sum() > croupier.give_croupier_sum() || croupier.give_croupier_sum() > 21) {
            player.win_money(bid * 2);
            std::cout << "You have won! Account status: " << player.get_money() << std::endl;
            return;
        }
        if (player.give_player_sum() == croupier.give_croupier_sum()) {
            player.win_money(bid);
            std::cout << "Draw, account status: " << player.get_money() << std::endl;
            return;
        } else {
            std::cout << "You have lost, account status: " << player.get_money() << std::endl;
            return;
        }
    }
}