#include <iostream>
#include <cmath>

int main() {
    int num, originalNum, remainder, digits = 0, sum = 0;

    std::cout << "Enter a number: ";
    std::cin >> num;

    originalNum = num;

    // 1. Count total digits
    int temp = num;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    // 2. Extract digits, compute power, and sum them up
    temp = num;
    while (temp > 0) {
        remainder = temp % 10;                     // Get last digit
        sum += std::round(std::pow(remainder, digits)); // Raise to digit count & add
        temp /= 10;                                // Remove last digit
    }

    // 3. Compare sum with original number
    if (sum == originalNum)
        std::cout << originalNum << " is an Armstrong number.";
    else
        std::cout << originalNum << " is NOT an Armstrong number.";

    return 0;
}