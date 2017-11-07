#include "indexed_tree.hpp"
#include <iostream>

class PrintVisitor {
public:
    void Visit(const size_t vertex) {
        std::cout << vertex << "\n";
    }

    void Visit(const size_t vertex, const size_t, const bool) {
        std::cout << vertex << "\n";
    }
};

int main() {
    Tree tree;
    std::cin >> tree;
    PrintVisitor print_visitor;
    tree.DoDFS(print_visitor);
    tree.DoBFS(print_visitor);
    return 0;
}
