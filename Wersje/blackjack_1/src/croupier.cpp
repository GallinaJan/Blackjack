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
        
        value += give_value(elem);
    }
}
