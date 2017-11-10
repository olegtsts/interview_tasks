#include <vector>
#include <iostream>

std::vector<std::vector<size_t>> GetSubsets(std::vector<size_t>& input_set) {
    if (input_set.size() == 0) {
        return {{}};
    }
    size_t value = input_set.back();
    input_set.pop_back();
    std::vector<std::vector<size_t>> sets = GetSubsets(input_set);
    std::vector<std::vector<size_t>> another_sets = sets;
    for (auto& set: another_sets) {
        set.push_back(value);
    }
    input_set.push_back(value);
    for (auto& set: another_sets) {
        sets.push_back(set);
    }
    return sets;
}
int main() {
    size_t size;
    std::cin >> size;
    std::vector<size_t> input_set(size);
    for (size_t i = 0; i < size; ++i) {
        std::cin >> input_set[i];
    }
    std::vector<std::vector<size_t>> subsets = GetSubsets(input_set);
    for (auto& subset: subsets) {
        std::cout << "Subset: ";
        for (auto& el: subset) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
