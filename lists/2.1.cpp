#include "list_input_output.hpp"
#include <iostream>
#include <list>

void RemoveDuplicates(std::list<int>& input_list) {
    std::list<int>::iterator last = input_list.begin();
    while (last != input_list.end()) {
        bool is_new_unique = true;
        for (auto it = input_list.begin(); it != last; ++it) {
            if (*it == *last) {
                is_new_unique = false;
                break;
            }
        }
        if (is_new_unique) {
            ++last;
        } else {
            auto before_last = last;
            --before_last;
            input_list.erase(last);
            last = before_last;
            ++last;
        }
    }
}
int main() {
    std::list<int> input_list = GetFromInput(std::cin);
    RemoveDuplicates(input_list);
    PrintList(input_list, std::cout);
    return 0;
}
