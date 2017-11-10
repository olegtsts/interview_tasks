#include <vector>
#include <iostream>

size_t GetRepresentationCount(const size_t number, std::vector<size_t>& elements) {
    if (elements.size() == 0) {
        if (number == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    auto coin = elements.back();
    size_t options = 0;
    elements.pop_back();
    for (size_t i = 0; i <= number / coin; ++i) {
        options += GetRepresentationCount(number - i * coin, elements);
    }
    elements.push_back(coin);
    return options;
}

int main() {
    size_t number;
    std::cin >> number;
    std::vector<size_t> elements{25, 10, 5, 1};
    std::cout << GetRepresentationCount(number, elements);
    return 0;
}
