#include <vector>
#include <iostream>

void FillAreaRecursive(std::vector<std::vector<size_t>>& colors, const size_t color, const size_t i, const size_t j) {
    if (i >= colors.size()) {
        return;
    }
    if (i < 0) {
        return;
    }
    if (j < 0) {
        return;
    }
    if (colors.size() == 0) {
        return;
    }
    if (j >= colors[0].size()) {
        return;
    }
    if (colors[i][j] == color) {
        return;
    }
    colors[i][j] = color;
    FillAreaRecursive(colors, color, i - 1, j);
    FillAreaRecursive(colors, color, i + 1, j);
    FillAreaRecursive(colors, color, i, j - 1);
    FillAreaRecursive(colors, color, i, j + 1);
}
std::vector<std::vector<size_t>> GetColorsFromInput() {
    size_t rows, cols;
    std::cin >> rows >> cols;
    std::vector<std::vector<size_t>> colors(rows, std::vector<size_t>(cols, 0));
    for (size_t row = 0; row < rows; ++row) {
        for (size_t col = 0; col < cols; ++col) {
            std::cin >> colors[row][col];
        }
    }
    return colors;
}
void PrintColorsToOutput(const std::vector<std::vector<size_t>>& colors) {
    for (auto& row: colors) {
        for (auto& element: row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}
int main() {
    auto colors = GetColorsFromInput();
    size_t target_color;
    std::cin >> target_color;
    size_t start_row, start_col;
    std::cin >> start_row >> start_col;
    FillAreaRecursive(colors, target_color, start_row, start_col);
    PrintColorsToOutput(colors);
    return 0;
}
