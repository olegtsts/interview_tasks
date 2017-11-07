#include "indexed_tree.hpp"
#include <iostream>

int main() {
    Tree tree;
    std::cin >> tree;
    std::cout << std::boolalpha << tree.IsThereARoute(0, 5);
    return 0;
}
