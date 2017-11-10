#include <vector>
#include <iostream>
#include <algorithm>

bool NextPermutation(std::vector<size_t>& permutation) {
    if (permutation.size() == 0) {
        return false;
    }
    if (permutation.size() == 1) {
        return false;
    }
    int last_index = static_cast<int>(permutation.size()) - 2;
    while (last_index >= 0 && permutation[last_index] > permutation[last_index + 1]) {
        --last_index;
    }
    if (last_index == -1) {
        return false;
    }
    int swap_index = static_cast<int>(permutation.size()) - 1;
    while (permutation[last_index] > permutation[swap_index]) {
        --swap_index;
    }
    std::swap(permutation[last_index], permutation[swap_index]);
    std::reverse(permutation.begin() + last_index + 1, permutation.end());
    return true;
}

void OutputVector(const std::vector<size_t>& sequence) {
    for (auto& el: sequence) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

void OutputPermutations(const size_t number) {
    std::vector<size_t> sequence(number);
    for (size_t i = 0; i < number; ++i) {
        sequence[i] = i + 1;
    }
    do {
        OutputVector(sequence);
    } while (NextPermutation(sequence));
}

int main() {
    size_t number;
    std::cin >> number;
    OutputPermutations(number);
    return 0;
}
