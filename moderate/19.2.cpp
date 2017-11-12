#include <vector>
#include <iostream>

enum class Result{
    x_won,
    o_won,
    draw
};

struct Counters {
    size_t x_count = 0;
    size_t o_count = 0;
};

void AddSymbol(Counters& counter, char symbol) {
    if (symbol == 'x') {
        ++counter.x_count;
    }
    if (symbol == 'o') {
        ++counter.o_count;
    }
}

Result GetGameResult(const std::vector<std::vector<char>>& field) {
    std::vector<Counters> counters;
    Counters diag_counter;
    Counters other_diag_counter;
    for (size_t i = 0; i < field.size(); ++i) {
        Counters row_counter;
        Counters col_counter;
        for (size_t j = 0; j < field.size(); ++j) {
            AddSymbol(row_counter, field[i][j]);
            AddSymbol(col_counter, field[j][i]);
        }
        AddSymbol(diag_counter, field[i][i]);
        AddSymbol(other_diag_counter, field[i][field.size() - 1 - i]);
        counters.push_back(row_counter);
        counters.push_back(col_counter);
    }
    counters.push_back(diag_counter);
    counters.push_back(other_diag_counter);
    for (auto& counter: counters) {
        if (counter.x_count == field.size()) {
            return Result::x_won;
        }
        if (counter.o_count == field.size()) {
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
