#include <iostream>
#include <vector>
#include <string>

size_t GetUniqueCharactersCount(const std::string& input_string) {
    std::vector<bool> is_met(256, false);
    for (auto& symbol : input_string) {
        uint8_t index = static_cast<uint8_t>(symbol);
        is_met[index] = true;
    }
    size_t result = 0;
    for (auto res: is_met) {
        if (res) {
            ++result;
        }
    }
    return result;
}
int main() {
    std::string input_string;
    std::cin >> input_string;
    std::cout << GetUniqueCharactersCount(input_string);
    return 0;
}
