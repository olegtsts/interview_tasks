#include "indexed_tree.hpp"
#include <iostream>
#include <limits>
#include <algorithm>

class BalancingVisitor {
private:
    size_t min_height_;
    size_t max_height_;
public:
    BalancingVisitor()
        : min_height_(std::numeric_limits<size_t>::max()),
          max_height_(0)
    {
    }
    void Visit(const size_t vertex, const size_t depth, const bool is_there_children) {
        if (!is_there_children) {
            min_height_ = std::min(min_height_, depth);
            max_height_ = std::max(max_height_, depth);
        }
    }
    bool IsBalanced() const {
        return max_height_ <= min_height_ + 1;
    }
};

bool IsTreeBalanced(const Tree& tree) {
    BalancingVisitor balancing_visitor;
    tree.DoDFS(balancing_visitor);
    return balancing_visitor.IsBalanced();
}

int main() {
    Tree tree;
    std::cin >> tree;
    std::cout << std::boolalpha << IsTreeBalanced(tree) << std::endl;
    return 0;
}
