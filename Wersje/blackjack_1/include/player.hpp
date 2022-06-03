#ifndef PLAYER_PLAYER_H
#define PLAYER_PLAYER_H
#include <map>
#include <vector>
#include "cards.hpp"

class Player{
public:
    Player(int my_money = 5000) :  my_money_(my_money) {}
    void take_money( int x){my_money_ = my_money_ - x;}
    Cards give_card(bool *need_to_shuffle) { player_cards_.push_back(cards_on_table_.take_card(need_to_shuffle));}
    void clean_hand() { player_cards_.clear();}
    void show_cards(){}
    int get_money() {return my_money_;}
    int give_sum(Cards card1, Cards cards2) {return card1.give_value() + card2.give_value();}
    bool is_blackjack();
    void clear_cards(); //cleaning function
    bool can_split();
    Cards give_cards_id(Cards card){ return card.get_id(); }
    void win_money(){}
private:
    Hand cards_on_table_;
    int my_money_; // ilość monet gracza
    std::vector<Cards> player_cards_; //karty gracza w turze
    int sum_ = 0; //suma wartości kart w ręce gracza
};
#endif //PLAYER_PLAYER_H
