#include "binary_tree.hpp"
#include <iostream>

Node* GetNextInOrder(Node* node) {
    if (node->right) {
        node = node->right;
        while (node->left) {
            node = node->left;
        }
        return node;
    } else {
        while (node->parent && node == node->parent->right) {
            node = node->parent;
        }
        return node->parent;
    }
}

int main() {
    BinaryTree binary_tree;
    std::cin >> binary_tree;
    size_t vertex;
    std::cin >> vertex;
    Node* next_node = GetNextInOrder(binary_tree.GetNode(vertex));
    if (next_node) {
        std::cout << next_node->index;
    } else {
        std::cout << "Traverse is over\n";
    }
    return 0;
}
