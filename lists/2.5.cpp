#include "my_linked_list.hpp"
#include <iostream>

List<int>::ConstIterator GetCycleStart(const List<int>& input_list) {
    List<int>::ConstIterator it1 = input_list.begin();
    List<int>::ConstIterator it2 = input_list.begin();
    do {
        ++it1;
        ++it2;
        ++it2;
    } while (it1 != it2);
    List<int>::ConstIterator it3 = input_list.begin();
    while (it3 != it2) {
        ++it3;
        ++it2;
    }
    return it3;
}

int main() {
    List<int> input_list;
    input_list.Add(1);
    input_list.Add(2);
    input_list.Add(3);
    input_list.Add(4);
    auto it = input_list.begin();
    auto it2 = input_list.begin();
    ++it;
    ++it2;
    ++it2;
    ++it2;
    input_list.Corrupt(it2, it);
    auto res_it = GetCycleStart(input_list);
    std::cout << *res_it;
    return 0;
}
