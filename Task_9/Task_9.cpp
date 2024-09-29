#include <iostream>
#include <cmath>

int main() {
    
    short n;
    std::cout << "выберите номер функции: " << std::endl;
    std::cout << "1. f(2x)" << std::endl;
    std::cout << "2. f(x^3)" << std::endl;
    std::cout << "3. f(x/3)" << std::endl;
    std::cin >> n;

    long double z, x, a, b, phi;
    std::cout << "введите значение x: ";
    std::cin >> z;
    std::cout << "введите значение a и b: ";
    std::cin >> a >> b;

    (z > 0) ? x = sqrt(z) : x = pow(z, 2) / 2;

    switch(n) {
        case(1):
            phi = 2 * x;
            break;
        case(2):
            phi = pow(x, 3);
            break;
        case(3):
            phi = x / 3;
            break;
        default:
            phi = x;
    }

    long double y = (b * phi) / cos(x) + a * log(abs(tan(x / 2)));

    std::cout << "y = " << y << ", при условии, что ";
    if (z > 0) std::cout << "z > 0 и ";
    else std::cout << "z <= 0 и ";

    switch(n) {
        case(1):
            std::cout << "f(2x)" << '\n';
            break;
        case(2):
            std::cout << "f(x^3)" << '\n';
            break;
        case(3):
            std::cout << "f(x/3)" << '\n';
            break;
        default:
            std::cout << "f(x)" << '\n';
    }

    return 0;
}