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
