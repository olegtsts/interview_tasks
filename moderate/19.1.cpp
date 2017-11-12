#include <iostream>

void Swap(size_t& a, size_t& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

int main() {
    size_t a, b;
    std::cin >> a >> b;
    Swap(a, b);
    std::cout << a << " " << b;
    return 0;
}
