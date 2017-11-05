#include <algorithm>
#include <iostream>
#include <string>

void Reverse(char* string, const size_t size) {
    char* begin = string;
    char* end = string + size;
    while (end - begin > 0) {
        std::swap(*begin++, *--end);
    }
}
int main() {
    std::string input_string;
    std::cin >> input_string;
    Reverse(&input_string[0], input_string.size());
    std::cout << input_string;
    return 0;
}
