#include <iostream>

size_t ShiftEvenOddBits(const size_t number) {
    size_t even_mask = 12297829382473034410ull;
    size_t odd_mask = 6148914691236517205ull;
    return ((number & odd_mask) << 1) | ((number & even_mask) >> 1);
}

int main() {
    size_t number;
    std::cin >> number;
    std::cout << ShiftEvenOddBits(number);
}
