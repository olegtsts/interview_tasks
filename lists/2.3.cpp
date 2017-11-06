#include "my_linked_list.hpp"
#include <iostream>

int main() {
    List<int> list;
    std::cin >> list;
    auto it = list.begin();
    ++it;
    list.Remove(it);
    std::cout << list;
    return 0;
}
