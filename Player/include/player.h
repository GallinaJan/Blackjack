

#ifndef PLAYER_PLAYER_H
#define PLAYER_PLAYER_H
#include <map>
#include <vector>
#include <algorithm>

class Player{
public:
    Player(std::vector<Cards> player_cards, my_money) : player_cards_(player_cards), my_money_(my_money)
    void give_card(bool *need_to_shuffle) { croupier_cards_.push_back(cards_on_table_.take_card(need_to_shuffle)); }
    void take_money(x){my_money_ = my_money_ - x;}
    void show_cards(){}
    int give_player_sum() {}
    bool is_blackjack(){}
    void clear_cards(){ /*cleaning function*/}
    bool can_split(){}
    Cards give_cards_id(const Cards& card){return card.give_id(); }
    void hide_second(const Cards&card_2){ hidden_card_=card_2;}
    void show_second(){player_cards_.push_back(hidden_card_;)}

private:
    int my_money_ = 5000;
    std::vector<Cards> player_cards_;
    int sum_ = 0;
    Cards hidden_card_;
    void win_money(int prize){ my_money_ = my_money_ + prize;}
};
#endif //PLAYER_PLAYER_H
