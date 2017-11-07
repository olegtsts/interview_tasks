#include <iostream>

void SetSubstringBits(int& n, const int m, const int i, const int j) {
    int substring_mask = ((1 << (j - i + 1)) - 1) << i;
    n &= ~substring_mask;
    n |= ((m << i) & substring_mask);
}
int main() {
    int n,m,i,j;
    std::cin >> n >> m >> i >> j;
    SetSubstringBits(n,m,i,j);
    std::cout << n;
}
