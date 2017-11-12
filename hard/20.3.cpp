#include <unordered_set>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

std::unordered_set<size_t> ChooseUnorderedSet(std::vector<size_t> numbers, const size_t subset_size) {
  for (size_t i = 0; i < subset_size; ++i) {
    size_t index = rand() % (numbers.size() - i) + i;
    std::swap(numbers[i], numbers[index]);
  }
  return {numbers.begin(), numbers.begin() + subset_size};
}
int main() {
  std::vector<size_t> numbers{1, 2, 3, 4, 5};
  auto set = ChooseUnorderedSet(numbers, 3);
  for (auto el: set) {
    std::cout << el << ' ';
  }
  return 0;
}
