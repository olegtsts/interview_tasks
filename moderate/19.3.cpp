#include <iostream>
#include <algorithm>

size_t GetDegreeSum(size_t number, size_t base) {
    size_t result = 0;
    size_t current_base = base;
    while (number / current_base > 0) {
        result += number / current_base;
        current_base *= base;
    }
    return result;
}

size_t CountZerosInFactorial(const size_t number) {
    return std::min(GetDegreeSum(number, 2), GetDegreeSum(number, 5));
}
int main() {
    size_t number;
    std::cin >> number;
    std::cout << CountZerosInFactorial(number);
    return 0;
}
