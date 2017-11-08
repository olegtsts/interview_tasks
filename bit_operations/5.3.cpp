#include <iostream>

bool IsBitSet(const size_t number, const size_t bit_number) {
    return number & (1ull << bit_number);
}
void SetBit(size_t& number, const size_t bit_number) {
    number |= (1ull << bit_number);
}
void UnSetBit(size_t& number, const size_t bit_number) {
    number &= ~(1ull << bit_number);
}

size_t GetLowestNext(size_t number) {
    size_t index = 0;
    while (index < 63 && (!IsBitSet(number, index) || IsBitSet(number, index + 1))) {
        ++index;
    }
    if (index == 63) {
        return number;
    }
    SetBit(number, index + 1);
    UnSetBit(number, index);
    int ones_count = 0;
    for (size_t i = 0; i < index; ++i) {
        if (IsBitSet(number, i)) {
            ++ones_count;
        }
    }
    for (size_t i = 0; i < index; ++i) {
        if (ones_count-- > 0) {
            SetBit(number, i);
        } else {
            UnSetBit(number, i);
        }
    }
    return number;
}
size_t GetGreatestPrev(size_t number) {
    return ~GetLowestNext(~number);
}
int main() {
    size_t number;
    std::cin >> number;
    std::cout << GetGreatestPrev(number) << " " << GetLowestNext(number);
    return 0;
}
