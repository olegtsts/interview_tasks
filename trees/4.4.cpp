#include "indexed_tree.hpp"
#include <algorithm>
#include <list>
#include <vector>
#include <iostream>

class MaxDepthVisitor {
private:
    size_t max_height_;
public:
    MaxDepthVisitor()
        : max_height_(0)
    {}

    void Visit(const size_t, const size_t depth, const bool) {
        max_height_ = std::max(max_height_, depth);
    }
    size_t GetMaxHeight() const {
        return max_height_;
    }
};

class SameLevelListsBuilder {
private:
    std::vector<std::list<size_t>> lists_;
public:
    SameLevelListsBuilder(const size_t max_depth)
        : lists_(max_depth + 1)
    {}

    void Visit(const size_t vertex, const size_t depth, const bool) {
        lists_[depth].push_back(vertex);
    }
    friend std::ostream& operator<<(std::ostream& out, const SameLevelListsBuilder& same_level_lists_builder) {
        for (auto& list: same_level_lists_builder.lists_) {
            for (auto& el: list) {
                std::cout << el << " ";
            }
            std::cout << "\n";
        }
        return out;
    }
};

SameLevelListsBuilder BuildSameLevelLists(const Tree& tree) {
    MaxDepthVisitor max_depth_visitor;
    tree.DoDFS(max_depth_visitor);
    size_t max_depth = max_depth_visitor.GetMaxHeight();
    SameLevelListsBuilder same_level_lists_builder(max_depth);
    tree.DoDFS(same_level_lists_builder);
    return same_level_lists_builder;
}

int main() {
    Tree tree;
    std::cin >> tree;
    SameLevelListsBuilder same_level_lists_builder = BuildSameLevelLists(tree);
    std::cout << same_level_lists_builder;
    return 0;
}
