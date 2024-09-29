#include <iostream>

const double pi = 3.1415926535;

long double abs(long double x) {
    if (x >= 0) return x;
    else return -x;
}

long double sqrt(long double x) {  // функция бинарного поиска по нахождению корня числа
    long double min, guess = 0;
    long double max = x;
    double error = 0.00001;  // погрешность измерения
    while (abs(guess * guess - x) >= error) {
        guess = (max + min) / 2;
        if (guess * guess > x) 
            max = guess;
        if (guess * guess < x)
            min = guess;
    }
    return guess;
}

long double pow(long double x, int n) {  // рекурсивная функция по возведению числа x в степень n
    if(n < 0)  return 1 / (x * pow(x, (-n) - 1));
    if(n == 0) return 1;
    if(n == 1) return x;
    return x * pow(x, n - 1);
}

unsigned long long fact(int x) {  // рекурсивная функция по нахождению факториала числа
    return x <= 0 ? 1 : x * fact(x-1);
}

double cos(long double x) { // функция нахождения косинуса через ряд Тейлора
    double cosine = 0;
    for (int i = 0; i < 20; i++) {  // 10 - количество итераций. Чем больше итераций, тем выше точность функции
        double term = pow(x, 2 * i) / fact(2 * i);  // вычисление элемента ряда Тейлора
        if (i % 2 == 0) cosine += term;  // каждый четный элемент ряда вычислеяется со знаком "плюс"
        else cosine -= term;  // каждый нечетный элемент ряда вычисляется со знаком "минус"
    }
    return cosine;
}

double sin(long double x) { // функция нахождения синуса через ряд Тейлора
    double sine = 0;
    for (int i = 0; i < 20; i++) {
        double term = pow(x, 2 * i + 1) / fact(2 * i + 1);
        if (i % 2 == 0) sine += term;
        else sine -= term;
    }
    return sine;
}

double acos(double x) {  // функция нахождения арккосинуса через ряд Тейлора
    int terms = 20;  // максимальное число итераций   
    double sum = 0;
    for (int n = 0; n < terms; ++n) {
        long double chislitel = fact(2 * n); // (2n)!
        long double znamenatel = pow(pow(2, n) * fact(n), 2); // (2^n * n!)^2
        double term = (chislitel / znamenatel) * pow(x, 2 * n + 1) / (2 * n + 1);  // n-ый член ряда Тейлора
        sum += term;
    }
    return pi / 2 - sum;
}

int main() {

    

    long double x1, y1, x2, y2, x3, y3;

    std::cout << "введите 6 чисел - x1, y1; x2, y2; x3, y3 - координаты вершин А, В, C соответственно: ";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    long double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); // длина АВ
    long double b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2)); // длина ВС
    long double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2)); // длина АС

    long double alpha = acos((pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c)); // угол альфа против стороны АВ
    long double betta = acos((pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * a * c)); // угол бетта против стороны ВС
    long double gamma = acos((pow(b, 2) + pow(a, 2) - pow(c, 2)) / (2 * b * a)); // угол гамма против стороны АС

    long double alphaDEG = alpha * 180 / pi; // градусная мера угла альфа
    long double bettaDEG = betta * 180 / pi; // градусная мера угла бетта
    long double gammaDEG = gamma * 180 / pi; // градусная мера угла гамма

    long double Ha = sin(gamma) * b; // длина высоты к АВ
    long double Hb = sin(alpha) * c; // длина высоты к ВС
    long double Hc = sin(betta) * a; // длина высоты к СА

    long double Ma = 0.5 * sqrt(2 * pow(c, 2) + 2 * pow(b, 2) - pow(a, 2)); // длина медианы к АВ
    long double Mb = 0.5 * sqrt(2 * pow(c, 2) + 2 * pow(a, 2) - pow(b, 2)); // длина медианы к ВС
    long double Mc = 0.5 * sqrt(2 * pow(a, 2) + 2 * pow(b, 2) - pow(c, 2)); // длина медианы к АС

    long double Ba = (2 * c * b * cos(alpha / 2) / (c + b)); // длина бис-сы угла альфа
    long double Bb = (2 * a * c * cos(betta / 2) / (a + c)); // длина бис-сы угла бетта
    long double Bc = (2 * a * b * cos(gamma / 2) / (a + b)); // длина бис-сы угла гамма

    long double R = a / (2 * sin(alpha)); // радиус описанной окружности

    long double C = a + b + c; // периметр треугольника
    long double S1 = 0.5 * sin(alpha) * b * c; // площадь треугольника первым способом
    long double S2 = sqrt((C / 2) * (C / 2 - a) * (C / 2 - b) * (C / 2 - c)); // площадь треугольника вторым способом
    long double S3 = a * b * c / (4 * R); // площадь треугольника третьим способом

    long double r = S1 / (C / 2);

    std::cout << std::endl;
    std::cout << "длина стороны AB = " << a << std::endl;
    std::cout << "длина стороны BC = " << b << std::endl;
    std::cout << "длина стороны AC = " << c << std::endl;
    std::cout << std::endl;
    std::cout << "длина высоты к стороне AB = " <<  Ha << std::endl;
    std::cout << "длина высоты к стороне BC = " << Hb << std::endl;
    std::cout << "длина высоты к стороне AC = " << Hc << std::endl;
    std::cout << std::endl;
    std::cout << "длина медианы к стороне AB = " << Ma << std::endl;
    std::cout << "длина медианы к стороне BC = " << Mb << std::endl;
    std::cout << "длина медианы к стороне AC = " << Mc << std::endl;
    std::cout << std::endl;
    std::cout << "длина биссектрисы угла против стороны AB = " << Ba << std::endl;
    std::cout << "длина биссектрисы угла против стороны BC = " << Bb << std::endl;
    std::cout << "длина биссектрисы угла против стороны AC = " << Bc << std::endl;
    std::cout << std::endl;
    std::cout << "величина угла альфа = " << alpha << ", или " << alphaDEG << "°" << std::endl;
    std::cout << "величина угла бетта = " << betta << ", или " << bettaDEG << "°" << std::endl;
    std::cout << "величина угла гамма = " << gamma << ", или " << gammaDEG << "°" << std::endl;
    std::cout << std::endl;
    std::cout << "радиус вписанной в треугольник окружности = " << r << std::endl;
    std::cout << "радиус описанной около треугольника окружности = " << R << std::endl;
    std::cout << std::endl;
    std::cout << "периметр треугольника = " << C << std::endl;
    std::cout << "площадь треугольника тремя способами = " << S1 << ", " << S2 << ", " << S3 << std::endl;
    std::cout << std::endl;

    return 0;
}