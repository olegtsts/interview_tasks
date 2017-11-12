#include <iostream>
#include <vector>
#include <algorithm>

size_t GetLargestContigousSum(const std::vector<int>& numbers) {
    std::vector<int> prefix_sums(numbers.size() + 1, 0);
    for (size_t i = 0; i < numbers.size(); ++i) {
        prefix_sums[i + 1] = numbers[i] + prefix_sums[i];
    }
    int max_sum = 0;
    int min_prefix_sum = 0;
    for (auto& sum: prefix_sums) {
        min_prefix_sum = std::min(min_prefix_sum, sum);
        int new_sum = sum - min_prefix_sum;
        max_sum = std::max(max_sum, new_sum);
    }
    return max_sum;
}
int main() {
    size_t size;
    std::cin >> size;
    std::vector<int> numbers(size);
    for (size_t i = 0; i < size; ++i) {
        std::cin >> numbers[i];
    }
    std::cout << GetLargestContigousSum(numbers);
    return 0;
}
