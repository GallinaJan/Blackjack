#ifndef INCLUDE_CROUPIER_HPP_
#define INCLUDE_CROUPIER_HPP_
#include <vector>
#include <stdio.h>
#include "cards.hpp"
class Croupier
{
public:
void add_money(double added) {money_on_table_ = added;}
void give_card() {croupier_cards_.push_back(take_card());}
void show_second() {std::cout<< croupier_cards_[1] << std::endl;}
void show_cards();
bool has_ace_as_first();
int give_croupier_sum();

private:
double money_on_table_;
std::vector<Cards> croupier_cards_;
};

void croupier_move(Croupier& croupier);

#endif //*INCLUDE_CROUPIER_HPP_