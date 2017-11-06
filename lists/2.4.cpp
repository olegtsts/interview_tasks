#include "list_input_output.hpp"
#include <list>
#include <iostream>

std::list<int> GetSumOfNumbers(const std::list<int>& first_number, const std::list<int>& second_number) {
    int addon = 0;
    auto first_it = first_number.begin();
    auto second_it = second_number.begin();
    std::list<int> result_list;
    while (first_it != first_number.end() || second_it != second_number.end()) {
        int first_digit = 0;
        if (first_it != first_number.end()) {
            first_digit = *first_it++;
        }
        int second_digit = 0;
        if (second_it != second_number.end()) {
            second_digit = *second_it++;
        }
        int sum = first_digit + second_digit + addon;
        result_list.insert(result_list.end(), sum % 10);
        addon = sum / 10;
    }
    if (addon > 0) {
        result_list.insert(result_list.end(), addon);
    }
    return result_list;
}
int main() {
    std::list<int> first_list = GetListFromInput(std::cin);
    std::list<int> second_list = GetListFromInput(std::cin);
    PrintList(GetSumOfNumbers(first_list, second_list), std::cout);
    return 0;
}
