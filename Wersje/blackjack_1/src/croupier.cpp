#include "player.hpp"
#include <cstdlib>
#include "cleaning.hpp"
#include <map>
#include <vector>
#include "cards.hpp"

bool Croupier::has_ace_as_first()
{
    std::string name Cards::give_name(croupier_cards_[0]);
    if(name == "as" || name == "As")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Croupier::give_croupier_sum()
{
    int ace_number = 0;
    for(auto elem : croupier_cards_)
    {
        if(elem.id_ == 13 || elem.id_ ==26 ||elem.id_ ==39|| elem.id_ == 52)
        {
        ace_number +=1;
        }
    }
}

void croupier_move(Croupier& croupier){
    while(croupier.give_sum() < 17){
        croupier.give_card();
    }
}
