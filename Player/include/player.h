

#ifndef PLAYER_PLAYER_H
#define PLAYER_PLAYER_H
#include <map>
#include <vector>
#include <algorithm>

class Player{
public:
    Player(std::vector<Cards> player_cards, my_money) : player_cards_(player_cards), my_money_(my_money)
    void take_money(x){my_money_ = my_money_ - x;}
    Cards give_card(){} /*player.cpp*/
    void show_cards(){}
    int give_sum() {return std::accumulate(std::begin(player_cards_), std::end(player_cards_), 0, [](int acc)
        {return acc + player_cards_.give_value();})}
    bool is_blackjack(){}
    void clear_cards(){ /*cleaning function*/}
    bool can_split(){}
    Cards give_cards_id(Cards card){return card.get_id(); }



private:
    int my_money_ = 5000;
    std::vector<Cards> player_cards_;
    int sum_ = 0;
    void win_money(){}
};
#endif //PLAYER_PLAYER_H
