#include <cassert>
#include <vector>
#include <iostream>

template <typename T>
class Allocator {
private:
    T* memory_;
    std::vector<T*> pointers_;
public:
    Allocator(const Allocator& other) = delete;
    Allocator(const size_t size) {
        memory_ = new T[size];
        for (size_t i = 0; i < size; ++i) {
            pointers_.push_back(memory_ + i);
        }
    }
    ~Allocator() {
        delete [] memory_;
    }
    T* GetPointer() {
        assert(pointers_.size() > 0);
        T* pointer = pointers_.back();
        pointers_.pop_back();
        std::cout << "Allocating pointer " << pointer << "\n";
        return pointer;
    }
    void ReturnPointer(T* pointer) {
        std::cout << "Returning pointer " << pointer << "\n";
        pointers_.push_back(pointer);
    }
};

template <typename T>
class Stack {
private:
    std::vector<T*> data_;
    Allocator<T>& allocator_;
public:
    Stack(Allocator<T>& allocator)
        : allocator_(allocator)
    {}
    ~Stack() {
        for (auto& pointer: data_) {
            allocator_.ReturnPointer(pointer);
        }
    }
    void Push(const T& value) {
        data_.push_back(allocator_.GetPointer());
        *data_.back() = value;
    }
    void Pop() {
        assert(data_.size() > 0);
        allocator_.ReturnPointer(data_.back());
        data_.pop_back();
    }
    T Top() const {
        assert(data_.size() > 0);
        return *data_.back();
    }
    class Iterator {
    public:
        size_t index;
        Stack& stack;
        Iterator(const size_t index, Stack& stack)
            : index(index)
            , stack(stack)
        {}
        T& operator*() const {
            return *stack.data_[index];
        }
        Iterator& operator++() {
            ++index;
            return *this;
        }
        bool operator!= (const Iterator& other) const {
            return index != other.index;
        }
    };
    class ConstIterator {
    public:
        size_t index;
        const Stack& stack;

        ConstIterator(const size_t index, const Stack& stack)
            : index(index)
            , stack(stack)
        {}
        const T& operator*() const {
            return *stack.data_.at(index);
        }
        ConstIterator& operator++() {
            ++index;
            return *this;
        }
        bool operator!=(const ConstIterator& other) const {
            return index != other.index;
        }
    };
    Iterator begin() {
        return {0, *this};
    }
    Iterator end() {
        return {data_.size(), *this};
    }
    ConstIterator begin() const {
        return {0, *this};
    }
    ConstIterator end() const {
        return {data_.size(), *this};
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
        for (auto& el: stack) {
            out << el << ' ';
        }
        out << '\n';
        return out;
    }
};

int main() {
    Allocator<int> allocator(9);
    Stack<int> first_stack(allocator);
    Stack<int> second_stack(allocator);
    Stack<int> third_stack(allocator);
    std::cin >> first_stack >> second_stack >> third_stack;
    std::cout << first_stack << second_stack << third_stack;
    return 0;
}
