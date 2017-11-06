#include <iostream>
#include <vector>
#include <string>

std::vector<size_t> GetSymbolCounts(const std::string& input_string) {
    std::vector<size_t> counts(256, 0);
    for (auto symbol : input_string) {
        ++counts[static_cast<uint8_t>(symbol)];
    }
    return counts;
}
bool AreAnagrams(const std::string& first_string, const std::string& second_string) {
    return GetSymbolCounts(first_string) == GetSymbolCounts(second_string);
}
int main() {
    std::string first_string, second_string;
    std::cin >> first_string >> second_string;
    std::cout << std::boolalpha << AreAnagrams(first_string, second_string);
    return 0;
}
