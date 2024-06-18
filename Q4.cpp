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

// Function to find a solution to the linear congruence equation ax = b (mod m)
void solveLinearCongruence(int a, int b, int m) {
    int x, y;
    int gcd = extendedGCD(a, m, &x, &y);

    // Check if there are solutions
    if (b % gcd != 0) {
        printf("No solution exists.\n");
        return;
    }

    // Find the particular solution
    x = (x * (b / gcd)) % m;

    // Adjust the solution to be positive
    if (x < 0) {
        x += m;
    }

    // Print the solutions
    printf("One solution is x = %d (mod %d)\n", x, m);

    // Print all solutions
    for (int i = 0; i < gcd; i++) {
        printf("x = %d (mod %d)\n", (x + i * (m / gcd)) % m, m);
    }
}

int main() {
    int a, b, m;
    printf("Enter values for a, b, and m to solve the equation ax = b (mod m): ");
    scanf("%d %d %d", &a, &b, &m);

    solveLinearCongruence(a, b, m);

    return 0;
}
