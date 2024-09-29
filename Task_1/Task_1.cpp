#include <iostream>

long double func(long double n) {
    return n * n * (23 * n + 69) + 32 * n + 8;
}

int main() {
    long double x;
    std::cout << "введите x: ";
    std::cin >> x;
    std::cout << func(x) << std::endl;
    std::cout << func(-x) << std::endl;
    return 0;
}
