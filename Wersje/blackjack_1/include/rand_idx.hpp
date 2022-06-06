#ifndef RAND_IDX_HPP
#define RAND_IDX_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

int get_idx() {
    srand(static_cast<unsigned int>(time(NULL)));
    return (101 * std::rand()) % 52;
}

#endif //RAND_IDX_HPP
