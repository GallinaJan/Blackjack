#ifndef SPLIT_HPP
#define SPLIT_HPP

#include <iostream>
#include <vector>
#include <string>

void split(Croupier& croupier, Player& player, bool* need_to_shuffle, Hand* hand, bid) {
    player.getmoney(bid);
    int potential_win1 = bid;
    int potential_win2 = bid;
    std::vector <Cards> secondhand;
    secondhand.push_back(player.get_player_cards.pop_back()) //czy cos podobnego
    player.givecard(need_to_shuffle);
    show_current_status;
    show_secondhand_status;
    std::cout << "hit, stand or double?" << std::endl;
    std::string choose;
    std::cin >> choose;
    if (choose == "double") {
        player.take_money(bid);
        player.givecard(need_to_shuffle);
        show_current_status;
        show_secondhand_status;
        potential_win1 += bid;
    } else {
        while (choose == "hit") {
            player.givecard(need_to_shuffle);
            show_current_status;
            show_secondhand_status;
            std::cout << "hit, stand or double?" << std::endl;
            std::cin >> choose;
        }
        // nie double
    }
    secondhand.give_card(need_to_shuffle);
    show_current_status;
    show_secondhand_status;
    std::cout << "hit, stand or double?" << std::endl;
    std::string choose;
    std::cin >> choose;
    if (choose == "double") {
        player.take_money(bid);
        secondhand.givecard(need_to_shuffle);
        show_current_status;
        show_secondhand_status;
        potential_win2 += bid;
    } else {
        while (choose == "hit") {
            secondhand.givecard(need_to_shuffle);
            show_current_status;
            show_secondhand_status;
            std::cout << "hit, stand or double?" << std::endl;
            std::cin >> choose;
        }
        // nie double
    }

//    croupiermove z uwzglednieniem obu rak( nie wiem z czego minimum chcecie dla krupiera)

    if (player.give_player_sum > croupier.give_croupier_sum || croupier.give_croupier_sum > 21) {
        player.givemoney(potential_win1 * 2);
        std::cout << "Wygrana reki 1" << std::endl;
    } else if (player.give_player_sum > croupier.give_croupier_sum) {
        player.givemoney(potential_win1);
        std::cout << "Remis reki 1" << std::endl;
    } else {
        std::cout << "przegrana reki 1" << std::endl;
    }
    if (secondhand.give_sum > croupier.give_croupier_sum || croupier.give_croupier_sum > 21) {
        player.givemoney(potential_win2 * 2);
        std::cout << "Wygrana reki 2" << std::endl;
        cleaning_function;
    } else if (secondhand.give_sum > croupier.give_croupier_sum) {
        player.givemoney(potential_win1);
        std::cout << "Remis reki 2" << std::endl;
        cleaning_function;
    } else {
        std::cout << "przegrana reki 2" << std::endl;
        cleaning_function;
    }

}

#endif //SPLIT_HPP


/*
 Podsumowujac trzeba zmienic croupiermove
 dodac secondhand.givecard
 secondhand.givesum
 player.get_player_cards
 i zabieranie ostatniego elementu z player.get_player_cards
 */
