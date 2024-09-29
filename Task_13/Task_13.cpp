#include <iostream>

int main() {
    int a, b;
    std::cout << "a = " << a << ", b = " << b << '\n';
    a = 1;
    b = 2;
    for (int i = 1; i < 6; i++) {
        std::cout << i << ". a = " << a << ", b = " << b << '\n';
        a += b;
        b += a;
    }
    return 0;
}