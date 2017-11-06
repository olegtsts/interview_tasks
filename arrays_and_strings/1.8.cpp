#include <iostream>
#include <string>

bool IsCyclicShift(const std::string& first_string, const std::string& second_string) {
    return first_string.size() == second_string.size() && (first_string + first_string).find(second_string) != std::string::npos;
}
int main() {
    std::string first_string, second_string;
    std::cin >> first_string >> second_string;
    std::cout << std::boolalpha << IsCyclicShift(first_string, second_string);
    return 0;
}
