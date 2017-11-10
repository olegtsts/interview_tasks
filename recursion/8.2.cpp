#include <vector>
#include <iostream>

class Field {
private:
    std::vector<std::vector<bool>> field_;
public:
    Field() {
    }
    void SetSize(const size_t size) {
        field_.resize(size, std::vector<bool>(size, true));
    }
    void MarkOffLimitSquare(const size_t row, const size_t col) {
        field_[row][col] = false;
    }
    bool IsInBound(const size_t row, const size_t col) const {
        return row >= 0 && row < field_.size() && col >= 0 && col < field_.size() && field_[row][col];
    }
    friend std::istream& operator>>(std::istream& in, Field& field) {
        size_t size;
        in >> size;
        field.SetSize(size);
        for (size_t row = 0; row < size; ++row) {
            for (size_t col = 0; col < size; ++col) {
                int is_available;
                in >> is_available;
                if (!is_available) {
                    field.MarkOffLimitSquare(row, col);
                }
            }
        }
        return in;
    }
    size_t CalculatePossiblePaths() const {
        size_t size = field_.size();
        std::vector<std::vector<size_t>> paths_count(size, std::vector<size_t>(size, 0));
        paths_count[0][0] = IsInBound(0, 0) ? 1 : 0;
        for (size_t row = 0; row < size; ++row) {
            for (size_t col = 0; col < size; ++col) {
                if (IsInBound(row, col)) {
                    if (IsInBound(row - 1, col)) {
                        paths_count[row][col] += paths_count[row - 1][col];
                    }
                    if (IsInBound(row, col - 1)) {
                        paths_count[row][col] += paths_count[row][col - 1];
                    }
                }
            }
        }
        return paths_count.back().back();
    }
};
int main() {
    Field field;
    std::cin >> field;
    std::cout << field.CalculatePossiblePaths();
    return 0;
}
