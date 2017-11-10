#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<size_t> GetArrayByString(const std::string& input_string) {
    std::vector<size_t> symbols_count(26, 0);
    for (auto& el: input_string) {
        ++symbols_count[el - 'a'];
    }
    return symbols_count;
}

bool IsLess(const std::vector<size_t>& first_vector, const std::vector<size_t>& second_vector) {
    for (size_t i = 0; i < first_vector.size(); ++i) {
        if (first_vector[i] < second_vector[i]) {
            return true;
        } else if (first_vector[i] > second_vector[i]) {
            return false;
        }
    }
    return false;
}

void SortStrings(std::vector<std::string>& strings) {
    std::sort(strings.begin(), strings.end(), [](const std::string& first_string, const std::string& second_string) {
        return IsLess(GetArrayByString(first_string), GetArrayByString(second_string));
    });
}
int main() {
    std::vector<std::string> strings{"abba", "aabb", "aaab"};
    SortStrings(strings);
    for (auto& one_string: strings) {
        std::cout << one_string << std::endl;
    }
    return 0;
}
