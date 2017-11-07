#include "binary_tree.hpp"
#include <iostream>

size_t GetDepth(Node* node) {
    size_t depth = 0;
    while (node->parent) {
        node = node->parent;
        ++depth;
    }
    return depth;
}

Node* GetLCA(Node* first_node, Node* second_node) {
    size_t first_depth = GetDepth(first_node);
    size_t second_depth = GetDepth(second_node);

    if (first_depth >= second_depth) {
        for (size_t index = second_depth; index < first_depth; ++index) {
            first_node = first_node->parent;
        }
        while (first_node != second_node) {
            first_node = first_node->parent;
            second_node = second_node->parent;
        }
        return first_node;
    } else {
        return GetLCA(second_node, first_node);
    }
}
int main() {
    BinaryTree tree;
    size_t first_node_index, second_node_index;
    std::cin >> tree >> first_node_index >> second_node_index;
    Node* result_node = GetLCA(tree.GetNode(first_node_index), tree.GetNode(second_node_index));
    std::cout << result_node->index;
    return 0;
}
