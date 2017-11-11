#include <iostream>
#include <vector>
#include <string>

int FindString(const std::vector<std::string>& strings, const std::string& string_to_find) {
    std::vector<size_t> non_empty_indices;
    size_t index = 0;
    for (auto& some_string: strings) {
        if (some_string.size() > 0) {
            non_empty_indices.push_back(index);
        }
        ++index;
    }
    if (string_to_find.size() == 0) {
        if (non_empty_indices.size() > 0) {
            return non_empty_indices[0];
        } else {
            return -1;
        }
    }
    size_t left = 0;
    size_t right = non_empty_indices.size();
    while (right - left > 1) {
        size_t middle = (right + left) / 2;
        if (strings[non_empty_indices[middle]] > string_to_find) {
            right = middle;
        } else if (strings[non_empty_indices[middle]] < string_to_find) {
            left = middle;
        } else {
            return non_empty_indices[middle];
        }
    }
    if (strings[non_empty_indices[left]] == string_to_find) {
        return non_empty_indices[left];
    } else {
        return -1;
    }
}
int main() {
    std::vector<std::string> strings{"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    std::string string_to_find = "ball";
    std::cout << FindString(strings, string_to_find) << "\n";
    std::cout << FindString({"at", "", "", "", "", "ball", "car", "", "", "dad", "", ""}, "ballcar");
    return 0;
}
