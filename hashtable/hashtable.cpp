#include <vector>
#include <memory>
#include <iostream>
#include <string>

template <typename T>
class Node {
public:
    Node* next_ = nullptr;
    T value_;

    bool IsDumb() const {
        return next_ == nullptr;
    }
};

template <typename T>
class List {
private:
    Node* head_;
    Node* tail_;

    void Add(const T& value) {
        tail_->next = new Node();
        tail_->value = value;
        tail_ = tail_->next;
    }
    void Remove(Node* node) {
        Node* old_node = node->next_;
        node->value_ = node->next_->value_;
        node->next_ = node->next_->next_;
        delete old_node;
    }
    List() {
        head_ = tail_ = new Node();
    }
    Node* Find(const T& value) const {
        Node* current_node = head_;
        while (current_node != tail_) {
            if (current_node->value_ == value) {
                return current_node;
            }
            current_node = current_node->next_;
        }
        return current_node;
    }
    bool IsEmpty() const {
        return head_ == tail_;
    }
    ~List() {
        Node* current_node = head_;
        while (current_node != tail_) {
            Node* new_node = current_node->next_;
            delete current_node;
            current_node = new_node;
        }
        delete current_node;
    }
    class Iterator {
    private:
        Node* node_;
    public:
        T operator*() const {
            return node_->value_;
        }
        bool operator==(const Iterator& other) const {
            return node_ == other.node_;
        }
        Iterator& operator++() {
            node_ = node_->next_;
        }
    };

    Iterator begin() {
        return {head_};
    }
    Iterator end() {
        return {tail_};
    }
};

template <typename TKey, typename TValue>
class KeyAndValue {
public:
    TKey key_;
    TValue value_;
    bool operator==(const KeyAndValue& other) const {
        return key_ == other.key_;
    }
    bool operator!=(const KeyAndValue& other) const {
        return !(*this == other);
    }
};

template <typename TKey, typename TValue, typename THasher>
class HashMap {
private:
    THasher hasher;
    std::vector<List<KeyAndValue<TKey, TValue>>> lists_;
    double load_factor_;
    size_t added_counter;
public:
    HashMap(const double load_factor, const size_t initial_size)
        : hasher()
        , load_factor_()
        , added_counter(0)
    {}

    void Reshard() {
        if (static_cast<double>(added_counter) / static_cast<double>(lists_.size()) < load_factor_) {
            return;
        }
        std::vector<List<KeyAndValue<TKey, TValue>>> new_lists(lists_.size());
        for (auto& my_list: lists_) {
            for (auto& key_and_value: my_list) {
                new_list[hasher(key_and_value.key_) % (2 * lists_.size())].Add(key_and_value);
            }
        }
        lists_ = std::move(new_lists);
    }

    void Insert(const TKey& key, const TValue& value) {
        lists_[hasher(key) % lists_.size()].Add({key, value});
        Reshard();
    }

    void Remove(const TKey& key) {
        Node<KeyAndValue<TKey, TValue>>* node = lists_[hasher(key) % lists_.size()].Find({key, {}});
        if (node.IsEmpty()) {
            lists_[hasher(key) % lists_.size()].Remove(node);
        }
    }
    std::unique_ptr<TValue> Get(const TKey& key) const {
        auto node = lists_[hasher(key) % lists_.size()].Find({key, {}});
        if (node.IsEmpty()) {
            return {nullptr};
        } else {
            return std::make_unique<Node>(node->value_);
        }
    }
}

class IntHasher {
public:
    size_t operator() (const int number) {
        return static_cast<size_t>(number);
    }
};
int main() {
    HashMap<int, std::string, IntHasher> hash_map(2, 2);
    hash_map.Insert(123, "abc");
    hash_map.Insert(1234, "abcd");
    hash_map.Insert(4, "abcd");
    hash_map.Insert(5, "abce");
    hash_map.Insert(7, "abcf");
    auto node = hash_map.Get(123);
    if (!node.IsDumb()) {
        std::cout << *node << std::endl;
    } else {
        std::cout << "No data\n";
    }
    node = hash_map.Get(1234);
    if (!node.IsDumb()) {
        std::cout << *node << std::endl;
    } else {
        std::cout << "No data\n";
    }
    return 0;
}
