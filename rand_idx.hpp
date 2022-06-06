#ifndef NIC_RAND_IDX_HPP
#define NIC_RAND_IDX_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

int get_idx() {
    srand(time(NULL));
    return (101 * std::rand()) % 52;
}

#endif //NIC_RAND_IDX_HPP