#include <iostream>

int main() {

    long double b1;
    std::cout << "введите b1: ";
    std::cin >> b1;
    long double q = 1. / 20;
    std::cout << "Сумма геометрической прогрессии: " << b1 / (1 - q);
    
    return 0;
}