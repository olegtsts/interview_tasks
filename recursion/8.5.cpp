#include <vector>
#include <iostream>
#include <string>

void OutputParenteses(const size_t number) {
    std::vector<std::vector<std::string>> parenteses_by_number(number + 1);
    parenteses_by_number[0] = {""};
    for (size_t i = 1; i <= number; ++i) {
        for (size_t j = 0; j < i; ++j) {
            for (auto& combination: parenteses_by_number[j]) {
                for (auto& second_combination: parenteses_by_number[i - j - 1]) {
                    parenteses_by_number[i].push_back("(" + combination + ")" + second_combination);
                }
            }
        }
    }
    for (auto& combination: parenteses_by_number[number]) {
        std::cout << combination << "\n";
    }
}
int main() {
    size_t number;
    std::cin >> number;
    OutputParenteses(number);
    return 0;
}
