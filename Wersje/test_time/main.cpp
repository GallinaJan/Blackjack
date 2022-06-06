#include <iostream>
#include <random>
#include <ctime>

int main()
{
    srand(static_cast<int>(time(NULL)));
    std::cout << rand()*101 % 52 << std::endl;
}