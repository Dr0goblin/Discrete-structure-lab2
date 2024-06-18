#include <iostream>

// Function to implement the Euclidean Algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to implement the Extended Euclidean Algorithm
int extendedGCD(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extendedGCD(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

int main() {
    int a, b;
    std::cout << "Enter two integers: ";
    std::cin >> a >> b;

    // Euclidean Algorithm
    std::cout << "GCD using Euclidean Algorithm: " << gcd(a, b) << std::endl;

    // Extended Euclidean Algorithm
    int x, y;
    int gcdExtended = extendedGCD(a, b, x, y);
    std::cout << "GCD using Extended Euclidean Algorithm: " << gcdExtended << std::endl;
    std::cout << "Coefficients x and y such that ax + by = gcd(a, b): x = " << x << ", y = " << y << std::endl;

    return 0;
}
