#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>

std::string GetBinaryRepresentation(const std::string& decimal_representation) {
    long double number = std::stold(decimal_representation);
    size_t dot_position = decimal_representation.find('.');
    size_t signs_after_dot = 0;
    if (dot_position != std::string::npos) {
        signs_after_dot = static_cast<size_t>(static_cast<int>(decimal_representation.size()) - 1 - static_cast<int>(dot_position));
    }
    number *= pow(2., signs_after_dot);
    double sign = 1;
    if (number < 0) {
        number *= -1;
        sign = -1;
    }
    if (number == floor(number)) {
        size_t int_number = floor(number);
        std::string binary_representation;
        while (int_number > 0) {
            binary_representation += (int_number % 2) ? '1' : '0';
            int_number /= 2;
        }
        std::reverse(binary_representation.begin(), binary_representation.end());
        double binary_representation_as_number = 0;
        for (auto symbol: binary_representation) {
            binary_representation_as_number *= 10;
            binary_representation_as_number += (symbol == '1' ? 1 : 0);
        }
        binary_representation_as_number *= sign;
        binary_representation_as_number /= pow(10, signs_after_dot);
        std::stringstream ss;
        ss << binary_representation_as_number;
        return ss.str();
    } else {
        return "ERROR";
    }
}

int main() {
    std::string input_string;
    std::cin >> input_string;
    std::cout << GetBinaryRepresentation(input_string);
    return 0;
}
