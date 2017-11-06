#include <cassert>
#include <stack>
#include <iostream>

template <typename T>
class MyQueue {
private:
    std::stack<T> head_stack_;
    std::stack<T> tail_stack_;
public:
    void PushBack(const T& value) {
        tail_stack_.push(value);
    }
    void Rebalance() {
        std::cout << "Rebalancing\n";
        while (tail_stack_.size() > 0) {
            auto element = tail_stack_.top();
            tail_stack_.pop();
            head_stack_.push(element);
        }
    }
    void PopFront() {
        if (head_stack_.size() == 0) {
            Rebalance();
        }
        assert(head_stack_.size() > 0);
        head_stack_.pop();
    }
    T Top() {
        if (head_stack_.size() == 0) {
            Rebalance();
        }
        return head_stack_.top();
    }
    size_t GetSize() const {
        return head_stack_.size() + tail_stack_.size();
    }
    friend std::istream& operator>>(std::istream& in, MyQueue& queue) {
        size_t size;
        in >> size;
        for (size_t i = 0; i < size; ++i) {
            T value;
            in >> value;
            queue.PushBack(value);
        }
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, MyQueue& queue) {
        while (queue.GetSize() > 0) {
            T element = queue.Top();
            out << element << " ";
            queue.PopFront();
        }
        out << "\n";
        return out;
    }
};
int main() {
    MyQueue<int> queue;
    std::cin >> queue;
    std::cout << queue;
    return 0;
}
