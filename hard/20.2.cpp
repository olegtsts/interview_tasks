#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>

void RandomShuffle(std::vector<size_t>& numbers) {
  for (size_t i = 0; i < numbers.size(); ++i) {
     size_t shift = i + (rand() % (numbers.size() - i));
     std::swap(numbers[i], numbers[shift]);
  }
}

int main() {
  size_t size;
  std::cin >> size;
  std::vector<size_t> numbers(size);
  for (size_t i = 0; i < size; ++i) {
    std::cin >> numbers[i];
  }
  RandomShuffle(numbers);
  for (auto element: numbers) {
    std::cout << element << ' ';
  }
  std::cout << '\n';
  return 0;
}

