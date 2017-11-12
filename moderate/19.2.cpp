#include <vector>
#include <iostream>

enum class Result{
    x_won,
    o_won,
    draw
};
Result GetGameResult(const std::vector<std::vector<char>>& field) {
    for (size_t i = 0; i < field.size(); ++i) {
        bool is_x_won = true;
        bool is_o_won = true;
        for (size_t j = 0; j < field[i].size(); ++j) {
            if (field[i][j] != 'x') {
                is_x_won = false;
            }
            if (field[i][j] != 'o') {
                is_o_won = false;
            }
        }
        if (is_x_won) {
            return Result::x_won;
        } else if (is_o_won) {
            return Result::o_won;
        }
    }
    if (field.size() == 0) {
        return Result::draw;
    }
    for (size_t j = 0; j < field[0].size(); ++j) {
        bool is_x_won = true;
        bool is_o_won = true;
        for (size_t i = 0; i < field.size(); ++i) {
            if (field[i][j] != 'x') {
                is_x_won = false;
            }
            if (field[i][j] != 'o') {
                is_o_won = false;
            }
        }
        if (is_x_won) {
            return Result::x_won;
        } else if (is_o_won) {
            return Result::o_won;
        }
    }
    return Result::draw;
}
int main() {
    std::vector<std::vector<char>> field(3, std::vector<char>(3, '\0'));
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            std::cin >> field[i][j];
        }
    }
    auto result = GetGameResult(field);
    if (result == Result::x_won) {
        std::cout << "X won\n";
    } else if (result == Result::o_won) {
        std::cout << "O won\n";
    } else {
        std::cout << "draw\n";
    }
    return 0;
}
