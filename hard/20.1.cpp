#include <iostream>

size_t GetSum(size_t first, size_t second) {
  if (second == 0) {
    return first;
  }
  return GetSum(first^second, (first&second) << 1);
}
int main() {
  size_t a, b;
  std::cin >> a >> b;
  std::cout << GetSum(a, b);
  return 0;
}