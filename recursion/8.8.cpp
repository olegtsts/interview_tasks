#include <algorithm>
#include <vector>
#include <iostream>

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

size_t GetQueensOptionsCount() {
    std::vector<size_t> sequence;
    for (size_t i = 0; i < 8; ++i) {
        sequence.push_back(i);
    }
    size_t options = 0;
    do {
        std::vector<size_t> row_counts(8, 0);
        std::vector<size_t> col_counts(8, 0);
        std::vector<size_t> diag_counts(16, 0);
        std::vector<size_t> rev_diag_counts(16, 0);
        bool is_option_ok = true;
        for (size_t row = 0; row < 8; ++row) {
            size_t col = sequence[row];
            if (++row_counts[row] > 1) {
                is_option_ok = false;
                break;
            }
            if (++col_counts[col] > 1) {
                is_option_ok = false;
                break;
            }
            if (++diag_counts[row + col] > 1) {
                is_option_ok = false;
                break;
            }
            if (++rev_diag_counts[row + 7 - col] > 1) {
                is_option_ok = false;
                break;
            }
        }
        if (is_option_ok) {
            ++options;
        }
    } while (NextPermutation(sequence));
    return options;
}
int main() {
    std::cout << GetQueensOptionsCount();
    return 0;
}
