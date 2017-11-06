#include <algorithm>
#include <iostream>
#include <stack>

template <typename T>
class Stack {
private:
    std::stack<T> data_stack_;
    std::stack<T> min_stack_;
public:
    void Push(const T& value) {
        data_stack_.push(value);
        if (min_stack_.size() > 0) {
            min_stack_.push(std::min(min_stack_.top(), value));
        } else {
            min_stack_.push(value);
        }
    }
    void Pop() {
        data_stack_.pop();
        min_stack_.pop();
    }
    T Top() const {
        return data_stack_.top();
    }
    T GetMin() const {
        return min_stack_.top();
    }
    friend std::istream& operator>>(std::istream& in, Stack& stack) {
        size_t size;
        in >> size;
        for (size_t i = 0; i < size; ++i) {
            T value;
            in >> value;
            stack.Push(value);
        }
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const Stack& stack) {
        for (auto& el: stack.data_stack_) {
            out << el << ' ';
        }
        out << "\n";
        return out;
    }
};
int main() {
    Stack<int> stack;
    std::cin >> stack;
    std::cout << stack.GetMin() << std::endl;
    stack.Pop();
    std::cout << stack.GetMin() << std::endl;
    return 0;
}
