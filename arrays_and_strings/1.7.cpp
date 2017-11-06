#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<int>>;
void ExpandZeros(Matrix& matrix) {
    std::vector<size_t> zero_rows, zero_cols;
    for (size_t row = 0; row < matrix.size(); ++row) {
        for (size_t col = 0; col < matrix[0].size(); ++col) {
            if (matrix[row][col] == 0) {
                zero_rows.push_back(row);
                break;
            }
        }
    }
    if (matrix.size() == 0) {
        return;
    }
    for (size_t col = 0; col < matrix[0].size(); ++col) {
        for (size_t row = 0; row < matrix.size(); ++row) {
            if (matrix[row][col] == 0) {
                zero_cols.push_back(col);
                break;
            }
        }
    }
    for (auto col: zero_cols) {
        for (size_t row = 0; row < matrix.size(); ++row) {
            matrix[row][col] = 0;
        }
    }
    for (size_t row: zero_rows) {
        for (size_t col = 0; col < matrix[0].size(); ++col) {
            matrix[row][col] = 0;
        }
    }
}
Matrix GetFromInput(std::istream& in) {
    size_t rows, cols;
    in >> rows >> cols;
    Matrix matrix(rows, std::vector<int>(cols, 0));
    for (size_t row = 0; row < rows; ++row) {
        for (size_t col = 0; col < cols; ++col) {
            in >> matrix[row][col];
        }
    }
    return matrix;
}
void PrintMatrix(const Matrix& matrix, std::ostream& out) {
    for (size_t row = 0; row < matrix.size(); ++row) {
        for (size_t col = 0; col < matrix[0].size(); ++col) {
            out << matrix[row][col];
            if (col + 1 < matrix[0].size()) {
                out << ' ' ;
            }
        }
        out << "\n";
    }
}
int main() {
    Matrix matrix = GetFromInput(std::cin);
    ExpandZeros(matrix);
    PrintMatrix(matrix, std::cout);
    return 0;
}
