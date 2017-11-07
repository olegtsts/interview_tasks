#include "indexed_tree.hpp"
#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
#include <algorithm>

std::tuple<size_t, bool> MakeTreeFromArrayRecursive(const std::vector<size_t>& sorted_nodes,
                                const size_t start_index,
                                const size_t stop_index,
                                Tree& tree) {
    if (stop_index - start_index >= 2) {
        size_t middle_index = (start_index + stop_index) / 2;
        bool is_there_tree;
        size_t left_son;
        std::tie(left_son, is_there_tree) = MakeTreeFromArrayRecursive(sorted_nodes, start_index, middle_index, tree);
        if (is_there_tree) {
            tree.AddEdge(sorted_nodes[middle_index], left_son);
        }
        size_t right_son;
        std::tie(right_son, is_there_tree) = MakeTreeFromArrayRecursive(sorted_nodes, middle_index + 1, stop_index, tree);
        if (is_there_tree) {
            tree.AddEdge(sorted_nodes[middle_index], right_son);
        }
        return std::tuple(sorted_nodes[middle_index], true);
    } else if (stop_index - start_index == 1) {
        return std::tuple(sorted_nodes[start_index], true);
    } else {
        return std::tuple(std::numeric_limits<size_t>::max(), false);
    }
}

Tree MakeTreeFromArray(const std::vector<size_t>& sorted_nodes) {
    Tree tree;
    tree.SetNodesCount(sorted_nodes.size());
    MakeTreeFromArrayRecursive(sorted_nodes, 0, sorted_nodes.size(), tree);
    return tree;
}

int main() {
    Tree tree = MakeTreeFromArray({2, 1, 3, 0, 4, 5});
    std::cout << tree;
    return 0;
}
