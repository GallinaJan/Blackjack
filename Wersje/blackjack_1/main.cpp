#include <iostream>
#include <stdio.h>
#include "player.hpp"
#include "croupier.hpp"
#include "cards.hpp"
#include "cleaning.hpp"

int main() {
    std::string start;
    std::cout << "Hello, if you want to play, type \"Y\", if you want to quit, type \"N\"" << std::endl;
    std::cin >> start;
    if(start == "N" || start == "n"){
        return 0;
    }
    if(start == "Y" || start == "y"){
        Croupier croupier;
        Player player;
    }
    else{
        return -1;
    }
    return 0;
}
