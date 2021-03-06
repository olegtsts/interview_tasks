#include <vector>
#include <iostream>

struct Node {
public:
    size_t index;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
};
class BinaryTree {
private:
    std::vector<Node> nodes;
public:
    void SetNodesCount(const size_t nodes_count) {
        nodes.resize(nodes_count);
        for (size_t i = 0; i < nodes_count; ++i) {
            nodes[i].index = i;
        }
    }
    void AddLeftSon(const size_t parent, const size_t son) {
        nodes[parent].left = &nodes[son];
        nodes[son].parent = &nodes[parent];
    }
    void AddRightSon(const size_t parent, const size_t son) {
        nodes[parent].right = &nodes[son];
        nodes[son].parent = &nodes[parent];
    }
    friend std::istream& operator>>(std::istream& in, BinaryTree& tree) {
        size_t size;
        in >> size;
        tree.SetNodesCount(size);
        for (size_t i = 0; i + 1 < size; ++i) {
            size_t parent, son;
            int is_left;
            in >> parent >> son >> is_left;
            if (is_left) {
                tree.AddLeftSon(parent, son);
            } else {
                tree.AddRightSon(parent, son);
            }
        }
        return in;
    }
    Node* GetRoot() {
        return &nodes[0];
    }
    Node* GetNode(const size_t index) {
        return &nodes[index];
    }
};

