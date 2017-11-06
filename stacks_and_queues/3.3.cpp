#include <vector>
#include <iostream>
#include <stack>
#include <cassert>

template <typename T>
class SetOfStacks {
private:
    size_t max_size_;
    std::vector<std::stack<T>> stacks_;
public:
    SetOfStacks(const size_t max_size)
        : max_size_(max_size)
    {}
    void Push(const T& value) {
        if (stacks_.size() == 0) {
            stacks_.push_back(std::stack<T>());
        }
        if (stacks_.back().size() == max_size_) {
            stacks_.push_back(std::stack<T>());
        }
        stacks_.back().push(value);
    }
    void Truncate() {
        while (stacks_.size() > 0 && stacks_.back().size() == 0) {
            stacks_.pop_back();
        }
    }
    void Pop() {
        assert(stacks_.size() > 0);
        stacks_.back().pop();
        Truncate();
    }
    T Top() const {
        return stacks_.back().top();
    }
    void PopAt(const size_t index) {
        assert(stacks_[index].size() > 0);
        stacks_[index].pop();
        Truncate();
    }
    friend std::istream& operator>>(std::istream& in, SetOfStacks& set_of_stacks) {
        size_t size;
        in >> size;
        for (size_t i = 0; i < size; ++i) {
            T value;
            in >> value;
            set_of_stacks.Push(value);
        }
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, SetOfStacks& set_of_stacks) {
        out << "stacks count is " << set_of_stacks.stacks_.size() << "\n";
        while (set_of_stacks.stacks_.size() > 0) {
            auto element = set_of_stacks.Top();
            out << element << ' ';
            set_of_stacks.Pop();
        }
        out << "\n";
        return out;
    }
};
int main() {
    SetOfStacks<int> set_of_stacks(2);
    std::cin >> set_of_stacks;
    std::cout << set_of_stacks;
    return 0;
}
