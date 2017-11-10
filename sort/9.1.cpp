#include <vector>
#include <iostream>

void Merge(std::vector<size_t>& a, std::vector<size_t>& b) {
    for (size_t i = 0; i < a.size() - b.size(); ++i) {
        a[a.size() - i - 1] = a[a.size() - b.size() - i - 1];
    }
    size_t a_index = 0;
    size_t b_index = 0;
    size_t write_index = 0;
    while (a_index < a.size() - b.size() && b_index < b.size()) {
        if (a[a_index + b.size()] < b[b_index]) {
            a[write_index++] = a[a_index++ + b.size()];
        } else {
            a[write_index++] = b[b_index++];
        }
    }
    while (a_index < a.size() - b.size()) {
        a[write_index++] = a[a_index++ + b.size()];
    }
    while (b_index < b.size()) {
        a[write_index++] = b[b_index++];
    }
}
int main() {
    std::vector<size_t> a = {1,2,10,15,0,0,0};
    std::vector<size_t> b = {5,11,12};
    Merge(a, b);
    for (auto& el: a) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    return 0;
}
