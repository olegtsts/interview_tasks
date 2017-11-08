#include <iostream>
#include <vector>

bool IsBitSet(const std::vector<size_t>& a, const size_t index, const size_t bit_number) {
    return a[index] & (1ull << bit_number);
}

size_t FindMissingNumber(const std::vector<size_t>& a) {
    size_t n = a.size();
    size_t result_xor = 0;
    for (size_t i = 1; i <= n; ++i) {
        result_xor ^= i;
    }
    for (size_t j = 0; j < 64; ++j) {
        for (size_t i = 0; i < a.size(); ++i) {
            if (IsBitSet(a, i, j)) {
                result_xor ^= (1ull << j);
            }
        }
    }
    return result_xor;
}

int main() {
    std::vector<size_t> a{0,1,2,3,5};
    std::cout << FindMissingNumber(a);
}
