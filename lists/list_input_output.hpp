#include <list>
#include <iostream>

std::list<int> GetListFromInput(std::istream& in) {
    std::list<int> input_list;
    size_t size;
    in >> size;
    for (size_t i = 0; i < size; ++i) {
        int element;
        in >> element;
        input_list.insert(input_list.end(), element);
    }
    return input_list;
}
void PrintList(const std::list<int> list, std::ostream& out) {
    for (auto element: list) {
        out << element << ' ';
    }
    out << "\n";
}
