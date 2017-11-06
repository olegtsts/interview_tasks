#include <iostream>
#include <string>

void URLEncodeSpaces(std::string& input_string) {
    std::string output_string;
    for (auto symbol: input_string) {
        if (symbol == ' ') {
            output_string += "%20";
        } else {
            output_string += symbol;
        }
    }
    input_string = std::move(output_string);
}
int main() {
    std::string input_string;
    std::getline(std::cin, input_string);
    URLEncodeSpaces(input_string);
    std::cout << input_string;
    return 0;
}
