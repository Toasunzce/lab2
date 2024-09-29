#include <iostream>

int main() {

    long double x, y, z;
    std::cout << "введите x, y, x: ";
    std::cin >> x >> y >> z;
    if (x >= y + z || y >= x + z || z >= x + y) {
        std::cout << "Треугольник не существует";
    }
    else std::cout << "Треугольник существует";
    
    return 0;
}