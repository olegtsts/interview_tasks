#include <iostream>

template <typename T>
struct Node {
    Node* next = nullptr;
    T value;
};

template<typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;

    bool is_corrupted_ = false;
public:
    List() {
        head = tail = new Node<T>();
    }
    ~List() {
        if (is_corrupted_) {
            return;
        }
        Node<T>* current_node = head;
        while (current_node != tail) {
            Node<T>* next_node = current_node->next;
            delete current_node;
            current_node = next_node;
        }
        delete current_node;
    }
    class Iterator {
    public:
        Node<T>* node_;

    public:
        Iterator(Node<T>* node)
            : node_(node)
        {}
        T& operator*() const {
            return node_->value;
        }
        Iterator& operator++() {
            node_ = node_->next;
            return *this;
        }
        bool operator!=(const Iterator& other) const {
            return node_ != other.node_;
        }
    };
    Iterator begin() {
        return {head};
    }
    Iterator end() {
        return {tail};
    }
    class ConstIterator {
    public:
        const Node<T>* node_;

    public:
        ConstIterator(const Node<T>* node)
            : node_(node)
        {}
        const T& operator*() const {
            return node_->value;
        }
        ConstIterator& operator++() {
            node_ = node_->next;
            return *this;
        }
        bool operator!=(const ConstIterator& other) const {
            return node_ != other.node_;
        }
    };
    ConstIterator begin() const {
        return {head};
    }
    ConstIterator end() const {
        return {tail};
    }
    void Remove(const Iterator& it) {
        Node<T>* next_node = it.node_->next;
        it.node_->next = next_node->next;
        it.node_->value = next_node->value;
        if (tail == next_node) {
            tail = it.node_;
        }
        delete next_node;
    }
    void Add(const T& value) {
        tail->value = value;
        tail->next = new Node<T>();
        tail = tail->next;
    }
    friend std::istream& operator>>(std::istream& in, List& list) {
        size_t size;
        in >> size;
        for (size_t i = 0; i < size; ++i) {
            T value;
            std::cin >> value;
            list.Add(value);
        }
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const List& list) {
        for (auto& el: list) {
            out << el << ' ';
        }
        return out;
    }
    void Corrupt(const Iterator& first_it, const Iterator& second_it) {
        is_corrupted_ = true;
        first_it.node_->next = second_it.node_;
    }
};
