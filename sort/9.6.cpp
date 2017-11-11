#include <cassert>
#include <vector>
#include <iostream>
#include <tuple>

std::tuple<size_t, size_t> FindElem(const std::vector<std::vector<size_t>>& field, const size_t target_element) {
    assert(field.size() > 0);
    int col = 0;
    int row = field.size() - 1;
    while (col < static_cast<int>(field[0].size()) && row >= 0) {
        if (field[row][col] == target_element) {
            return {row, col};
        } else if (field[row][col] > target_element) {
            --row;
        } else if (field[row][col]) {
            ++col;
        }
    }
    assert(false);
}
int main() {
    std::vector<std::vector<size_t>> field{{1,2,3},{2,3,4},{3,4,5}};
    size_t row, col;
    std::tie(row, col) = FindElem(field, 4);
    std::cout << row << " " << col;
    return 0;
}
