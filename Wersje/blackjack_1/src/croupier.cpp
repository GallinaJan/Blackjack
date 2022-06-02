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
    int sum = 0;
    for(auto elem : croupier_cards_)
    {
        if(elem.id_ == 13 || elem.id_ ==26 ||elem.id_ ==39|| elem.id_ == 52)
        {
        ace_number +=1;
        }
    }
    for(auto elem:croupier_cards_)
    {
        if(elem.id_ != 13 && elem.id_ !=26 && elem.id_ !=39 && elem.id_ != 52) {
            if (
                    elem.id_ == 10 ||
                    elem.id_ == 11 ||
                    elem.id_ == 12 ||
                    elem.id_ == 23 ||
                    elem.id_ == 24 ||
                    elem.id_ == 25 ||
                    elem.id_ == 36 ||
                    elem.id_ == 37 ||
                    elem.id_ == 38 ||
                    elem.id_ == 49 ||
                    elem.id_ == 50 ||
                    elem.id_ == 51 ||
                    ) {
                sum += 10;
            } else {
                sum += 1 + (elem.id_) % 13;
            }
        }
        if(ace_number != 0)
        {
            if((sum +10 + ace_number) <= 21)
            {
                sum += (10 + ace_number) ;
            }
            else
            {
                sum += ace_number;
            }
        }
    }
}

void croupier_move(Croupier& croupier){
    while(croupier.give_sum() < 17){
        croupier.give_card();
    }
}
