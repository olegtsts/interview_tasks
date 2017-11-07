#include "binary_tree.hpp"
#include <iostream>

bool ExactMatch(Node* first_node, Node* second_node) {
    if (second_node == nullptr) {
        return true;
    }
    if (first_node == nullptr) {
        return false;
    }
    if (first_node->index != second_node->index) {
        return false;
    }
    return ExactMatch(first_node->left, second_node->left) && ExactMatch(first_node->right, second_node->right);
}

bool IsSubtree(Node* first_node, Node* second_node) {
    if (ExactMatch(first_node, second_node)) {
        return true;
    }
    if (first_node == nullptr) {
        return false;
    }
    return IsSubtree(first_node->left, second_node) || IsSubtree(first_node->right, second_node);
}

int main() {
    BinaryTree first_tree, second_tree;
    std::cin >> first_tree >> second_tree;
    size_t first_root_index;
    size_t second_root_index;
    std::cin >> first_root_index >> second_root_index;
    std::cout << std::boolalpha << IsSubtree(first_tree.GetNode(first_root_index),
                           second_tree.GetNode(second_root_index));
    return 0;
}
