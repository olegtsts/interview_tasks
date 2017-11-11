struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
};
Node* GetCopy(Node* node) {
    if (node != nullptr) {
        Node* new_node = new Node();
        new_node->left = GetCopy(node->left);
        new_node->right = GetCopy(node->right);
        return new_node;
    } else {
        return nullptr;
    }
}
int main() {
    Node* first_node = new Node{};
    Node* second_node = new Node{};
    Node* third_node = new Node{first_node, second_node};
    GetCopy(third_node);
    return 0;
}
