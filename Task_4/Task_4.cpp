#include <iostream>

int main() {

    long int X, Y;
    std::cout << "enter X: ";
    std::cin >> X;
    std::cout << "enter Y: ";
    std::cin >> Y;

    if (X == Y) {
        X = 0, Y = 0;
    }
    else if (X > Y) {
        Y = 0;
    }
    else {
        X = 0;
    }

    long double A, B, C, K;

    std::cout << "enter A: ";
    std::cin >> A;
    std::cout << "enter B: ";
    std::cin >> B;
    std::cout << "enter C: ";
    std::cin >> C;
    std::cout << "enter K: ";
    std::cin >> K;
    
    if (A >= B && A >= C) {
        A -= K;
    }
    else if (B >= A && B >= C) {
        B -= K;
    }
    else if (C >= A && C >= B) {
        C -= K;
    }

    std::cout << "X = " << X << "; ";
    std::cout << "Y = " << Y << "; ";
    std::cout << "A = " << A << "; ";
    std::cout << "B = " << B << "; ";
    std::cout << "C = " << C << "; ";
    
    return 0;
}                                                                                                        