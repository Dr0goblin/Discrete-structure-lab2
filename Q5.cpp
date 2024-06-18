#include <stdio.h>

// Function to implement the Extended Euclidean Algorithm
// It returns gcd of a and b and also updates x and y such that ax + by = gcd(a, b)
int extendedGCD(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extendedGCD(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

// Function to find the modular inverse of a under modulo m
// a and m are coprime, it returns the inverse, such that (a * inverse) % m == 1
int modInverse(int a, int m) {
    int x, y;
    int g = extendedGCD(a, m, &x, &y);
    if (g != 1) {
        return -1; // Inverse doesn't exist if gcd(a, m) != 1
    } else {
        // m is added to handle negative x
        return (x % m + m) % m;
    }
}

// Function to find the smallest x such that:
// x = num[i] (mod rem[i]) for all i from 0 to n-1
int findMinX(int num[], int rem[], int k) {
    int prod = 1;
    for (int i = 0; i < k; i++) {
        prod *= num[i];
    }

    int result = 0;

    for (int i = 0; i < k; i++) {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }

    return result % prod;
}

int main() {
    int num[] = {3, 4, 5};
    int rem[] = {2, 3, 1};
    int k = sizeof(num) / sizeof(num[0]);

    printf("x is %d\n", findMinX(num, rem, k));
    return 0;
}
