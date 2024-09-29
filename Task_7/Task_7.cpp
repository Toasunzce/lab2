#include <iostream>

int main() {

    long double a, b, c;
    long int N;
    std::cout << "enter a: ";
    std::cin >> a;
    std::cout << "enter b: ";
    std::cin >> b;
    std::cout << "enter c: ";
    std::cin >> c;
    std::cout << "enter N: ";
    std::cin >> N;

    switch(N) {
        case 2:
            std::cout << b * c - a * a;
            break;
        case 56:
            std::cout << b * c;
            break;
        case 7:
            std::cout << a * a + c;
            break;
        case 3:
            std::cout << a - b * c;
            break;
        default: 
            std::cout << (a + b) * (a + b) * (a + b);
    }

    return 0;
}


