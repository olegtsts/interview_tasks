#include <iostream>

bool IsBitSet(const size_t number, const size_t bit_number) {
    return number & (1ull << bit_number);
}
size_t GetBitCount(size_t number) {
    size_t bit_count = 0;
    while (number > 0){
        number &= (number - 1);
        ++bit_count;
    }
    return bit_count;
}
size_t GetDistinctBitsCount(const size_t a, const size_t b) {
    return GetBitCount(a ^ b);
}
int main() {
    size_t a, b;
    std::cin >> a >> b;
    std::cout << GetDistinctBitsCount(a, b);
    return 0;
}
