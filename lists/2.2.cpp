#include "list_input_output.hpp"
#include <cassert>
#include <iostream>
#include <list>

int GetNthToLast(const std::list<int>& input_list, const size_t n) {
    assert(input_list.size() >= n);
    size_t position = static_cast<size_t>(static_cast<int>(input_list.size()) - static_cast<int>(n));
    auto it = input_list.begin();
    for (size_t i = 0; i < position; ++i) {
        ++it;
    }
    return *it;
}
int main() {
    auto list = GetListFromInput(std::cin);
    size_t n = 0;
    std::cin >> n;
    std::cout << GetNthToLast(list, n);
    return 0;
}
