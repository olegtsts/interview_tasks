#include <stack>
#include <iostream>

template <typename T>
void SortStack(std::stack<T>& input_stack) {
    std::stack<T> another_stack;
    while (input_stack.size() > 0) {
        T element = input_stack.top();
        input_stack.pop();
        another_stack.push(element);
    }
    while (another_stack.size() > 0) {
        T element = another_stack.top();
        another_stack.pop();
        while (input_stack.size() > 0 && input_stack.top() < element) {
            another_stack.push(input_stack.top());
            input_stack.pop();
        }
        input_stack.push(element);
    }
}
template <typename T>
std::stack<T> GetStackFromInput(std::istream& in) {
    size_t size;
    in >> size;
    std::stack<T> stack;
    for (size_t i = 0; i < size; ++i) {
        T value;
        in >> value;
        stack.push(value);
    }
    return stack;
}
template <typename T>
void PrintStack(std::stack<T>& stack, std::ostream& out) {
    while (stack.size() > 0) {
        out << stack.top() << " ";
        stack.pop();
    }
}
int main() {
    std::stack<int> stack = GetStackFromInput<int>(std::cin);
    SortStack(stack);
    PrintStack(stack, std::cout);
    return 0;
}
