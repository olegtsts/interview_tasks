#include <iostream>

size_t GetCountOfTwosInNumber(size_t number) {
  size_t count_of_twos = 0;
  while (number > 0) {
    if (number % 10 == 2) {
      ++count_of_twos; 
    }
    number /= 10; 
  }
  return count_of_twos;
}
size_t GetCountOfTwosInAllNumbersLessThan(size_t number) {
  if (number <= 0) {
    return 0;
  }
  return ((number + 8) / 10) + (number % 10 + 1) * GetCountOfTwosInNumber(number / 10) + GetCountOfTwosInAllNumbersLessThan(number / 10 - 1) * 10;
}
int main() {
  size_t number;
  std::cin >> number;
  std::cout << GetCountOfTwosInAllNumbersLessThan(number);
  return 0;
}