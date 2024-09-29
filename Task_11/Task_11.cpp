#include <iostream>

int main() {

    int h1, min1, h2, min2;
    std::cout << "введите время начала занятия (часы): ";
    std::cin >> h1;
    std::cout << "введите время начала занятия (минуты): ";
    std::cin >> min1;  
    std::cout << "введите время конца занятия (часы): ";
    std::cin >> h2;
    std::cout << "введите время конца занятия (минуты): ";
    std::cin >> min2;

    int time = (h2 * 60 + min2) - (h1 * 60 + min1);

    if (time > 59 && time % 60 != 0) {
        std::cout << "студент решал задачи " << time / 60 << " час(а/ов) " << time % 60 << " минут(ы)";
    }
    else if (time > 59 && time % 60 == 0) {
        std::cout << "студент решал задачи " << time / 60 << " час(a/ов) ";
    }
    else std::cout << "студент решал задачи " << time % 60 << " минут(ы)";
    
    return 0;
}