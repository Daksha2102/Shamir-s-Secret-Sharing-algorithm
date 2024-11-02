#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to convert a number string from any base to decimal (base 10)
long long base_to_decimal(const char *value, int base) {
    return strtoll(value, NULL, base);
}

// Lagrange interpolation function to find the constant term (c)
double lagrange_interpolation(int x[], long long y[], int k) {
    double constant_term = 0.0;
    for (int i = 0; i < k; i++) {
        double term = (double)y[i];
        for (int j = 0; j < k; j++) {
            if (i != j) {
                term *= (0.0 - x[j]) / (x[i] - x[j]);
            }
        }
        constant_term += term;
    }
    return constant_term;
}

int main() {
    // Sample input data for test case 1
    int x1[] = {1, 2, 3};                      // x values
    char *y_values1[] = {"4", "111", "12"};    // y values in different bases
    int bases1[] = {10, 2, 10};                // Corresponding bases for y values
    int k1 = 3;                                // Minimum number of roots needed

    // Decode y values for test case 1
    long long y1[k1];
    for (int i = 0; i < k1; i++) {
        y1[i] = base_to_decimal(y_values1[i], bases1[i]);
    }

    // Calculate the constant term for test case 1
    double constant_term1 = lagrange_interpolation(x1, y1, k1);
    printf("Constant term (c) for test case 1: %.0f\n", constant_term1);

    // Sample input data for test case 2
    int x2[] = {1, 2, 3, 4, 5, 6, 7};          // x values
    char *y_values2[] = {
        "13444211440455345511", "aed7015a346d63", "6aeeb69631c227c", 
        "e1b5e05623d881f", "316034514573652620673", 
        "2122212201122002221120200210011020220200", 
        "20120221122211000100210021102001201112121"
    };
    int bases2[] = {6, 15, 15, 16, 8, 3, 3};   // Corresponding bases for y values
    int k2 = 7;                                // Minimum number of roots needed

    // Decode y values for test case 2
    long long y2[k2];
    for (int i = 0; i < k2; i++) {
        y2[i] = base_to_decimal(y_values2[i], bases2[i]);
    }

    // Calculate the constant term for test case 2
    double constant_term2 = lagrange_interpolation(x2, y2, k2);
    printf("Constant term (c) for test case 2: %.0f\n", constant_term2);

    return 0;
}
