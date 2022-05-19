

#ifndef PLAYER_PLAYER_H
#define PLAYER_PLAYER_H
#include <map>

class Player{
public:
    void take_money(const int& x){my_money_ = my_money_ - x;}
    Cards give_card(){} /*player.cpp*/
    Cards show_cards(){return {card1, card2};}
    int give_sum() const {return card1.give_value()+card2.give_value();}
    void is_blackjack(){}
    void clear_cards(){ /*cleaning function*/}
    void can_split(){return true if card1.give_value() == card2.give_value();}
    Cards give_cards_id(Cards card){return card.get_id(); }



private:
    int my_money_ = 5000;
    Cards card1, card2;
    int sum_ = 0;
    void win_money(){}
};
#endif //PLAYER_PLAYER_H
