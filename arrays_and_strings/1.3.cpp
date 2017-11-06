#include <iostream>
#include <string>

void RemoveDuplicates(std::string& input_string) {
    size_t processed_characters = 0;
    for (size_t index = 0; index < input_string.size(); ++index) {
        bool is_new = true;
        for (size_t j = 0; j < processed_characters; ++j) {
            if (input_string[j] == input_string[index]) {
                is_new = false;
                break;
            }
        }
        if (is_new) {
            input_string[processed_characters++] = input_string[index];
        }
    }
    input_string.resize(processed_characters);
}
int main() {
    std::string input_string;
    std::cin >> input_string;
    RemoveDuplicates(input_string);
    std::cout << input_string;
    return 0;
}
