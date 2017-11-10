#include <algorithm>
#include <vector>
#include <iostream>

size_t GetPosition(const std::vector<size_t>& shifted_vector, const size_t target_element) {
    size_t left = 0;
    size_t right = shifted_vector.size();
    while (right - left >= 2) {
        size_t middle = (right + left) / 2;
        if (shifted_vector[middle] > shifted_vector[left] ){
            left = middle;
        } else {
            right = middle;
        }
    }
    if (target_element >= shifted_vector[0]) {
        return std::lower_bound(shifted_vector.begin(), shifted_vector.begin() + right, target_element) - shifted_vector.begin();
    } else {
        return std::lower_bound(shifted_vector.begin() + right, shifted_vector.end(), target_element) - shifted_vector.begin();
    }
}
int main() {
    std::vector<size_t> input_vector{15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    for (auto& el: input_vector) {
        std::cout << GetPosition(input_vector, el) << std::endl;
    }
    return 0;
}
