#include <iostream>

class MatrixTwoByTwo {
public:
    size_t a;
    size_t b;
    size_t c;
    size_t d;
public:
    MatrixTwoByTwo()
        : a(1),
        b(0),
        c(0),
        d(1)
    {}
    MatrixTwoByTwo& operator*=(const MatrixTwoByTwo& other) {
        MatrixTwoByTwo new_matrix;
        new_matrix.a = a * other.a + b * other.c;
        new_matrix.b = a * other.b + b * other.d;
        new_matrix.c = c * other.a + d * other.c;
        new_matrix.d = c * other.b + d * other.d;
        *this = new_matrix;
        return *this;
    }
};

MatrixTwoByTwo RaiseMatrixToPower(MatrixTwoByTwo& initial_matrix, size_t power) {
    MatrixTwoByTwo x;
    while (power > 0) {
        if (power % 2 == 0) {
            power /= 2;
            initial_matrix *= initial_matrix;
        } else {
            x *= initial_matrix;
            --power;
        }
    }
    return x;
}

size_t GetFibonacciNumber(const size_t index) {
    MatrixTwoByTwo matrix;
    matrix.a = 1;
    matrix.b = 1;
    matrix.c = 1;
    matrix.d = 0;
    MatrixTwoByTwo result_matrix = RaiseMatrixToPower(matrix, index);
    return result_matrix.a;
}
int main() {
    size_t index;
    std::cin >> index;
    std::cout << GetFibonacciNumber(index);
    return 0;
}
