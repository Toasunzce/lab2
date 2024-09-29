#include <iostream>

long double abs(long double x) {  // функция по нахождению модуля числа
    if (x < 0) return -x;
    else return x;
}

long double sqrt(long double x) {  // функция по нахождению квадратного корня
    double error = 0.0000000001; // разряд округления
    double s = x;
    while ((s - x / s) > error) {// цикл до достижения разряда округления
        s = (s + x / s) / 2;
    }
    return s;
}

long double sq(long double x) { // функция по нахождению квадрата числа
    return x * x;
}

int main() {

    long double x1, y1, r, x2, y2, R;
    std::cout << "введите координаты центра окружности М1(x1, y1) и её радиус(r): ";
    std::cin >> x1 >> y1 >> r;
    std::cout << "введите координаты центра окружности М2(x2, y2) и её радиус(R): ";
    std::cin >> x2 >> y2 >> R;   

    if (r >= R and r - R >= sqrt(sq(x1 - x2) + sq(y1 - y2))) {
        std::cout << "Да\n";
    } 
    else if (R >= r and R - r >= sqrt(sq(x1 - x2) + sq(y1 - y2))) {
        std::cout << "Да, но справедливо обратное для двух фигур\n";
    }
    else if (abs(r - R) < sqrt(sq(x1 - x2) + sq(y1 - y2)) and sqrt(sq(x1 - x2) + sq(y1 - y2)) < r + R) {
        std::cout << "Фигуры пересекаются\n";
    }
    else std::cout << "Ни одно условие не выполнено\n";

    return 0;
}