#include <iostream>

size_t GetMax(size_t a, size_t b) {
    return int(bool(a / b)) * a + int(bool(b / a)) * b;
}
int main() {
    size_t a,b;
    std::cin >> a >> b;
    std::cout << GetMax(a, b);
    return 0;
}
