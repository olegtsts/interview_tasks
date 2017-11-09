#include <vector>
#include <string>

struct Move {
    size_t source_row;
    size_t source_col;
    size_t target_row;
    size_t target_col;
    bool is_first_turn;
};

struct MoveResponse {
    bool is_permitted;
    std::string decline_reason;
};

class Figure {
private:
    std::string figure_name_;
public:
    Figure(const std::string& figure_name)
        : figure_name_(figure_name)
    {}
    virtual bool CheckMove(const Move& move) const = 0;
    std::string GetName() const {
        return figure_name_;
    }
    virtual ~Figure() {}
};

class Pawn: public Figure {
public:
    Pawn()
        : Figure("Pawn")
    {}

    bool CheckMove(const Move& move) const {
        return (!move.is_first_turn && move.target_row == move.source_row + 1) || (move.is_first_turn && move.target_row == move.source_row - 1);
    };
};

class Chess {
private:
    bool is_first_turn_;
    std::vector<std::vector<Figure*>> board;
public:
    Chess()
        : is_first_turn_(true)
        , board(8, std::vector<Figure*>(8, nullptr))
    {}
    MoveResponse MakeMove(Move& move) {
        Figure* figure = board[move.source_row][move.source_col];
        if (figure == nullptr) {
            return MoveResponse{false, "there is no figure in source poision"};
        }
        move.is_first_turn = is_first_turn_;
        bool can_make_move = figure->CheckMove(move);
        if (can_make_move) {
            if (board[move.target_row][move.target_col]) {
                return MoveResponse{false, "there is a figure on target position"};
            }
            board[move.target_row][move.target_col] = board[move.source_row][move.source_col];
            board[move.source_row][move.source_col] = nullptr;
            is_first_turn_ = !is_first_turn_;
            return MoveResponse{true, ""};
        } else {
            return MoveResponse{false, "figure cannot move in such a manner"};
        }
    }
};
