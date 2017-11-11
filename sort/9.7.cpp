#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <limits>

std::vector<size_t> GetIncreasingSeqence(const std::vector<size_t>& weights) {
    std::vector<int> length_min_element(weights.size() + 1, std::numeric_limits<int>::max());
    std::vector<int> previous_index(weights.size(), -1);
    std::vector<int> length_last_index(weights.size(), -1);
    length_last_index[0] = -1;
    length_min_element[0] = std::numeric_limits<int>::min();
    size_t max_length = 0;
    for (size_t i = 0; i < weights.size(); ++i) {
        size_t j = std::upper_bound(length_min_element.begin(), length_min_element.end(), static_cast<int>(weights[i])) - length_min_element.begin();
        if (length_min_element[j - 1] < static_cast<int>(weights[i]) && length_min_element[j] > static_cast<int>(weights[i])) {
            length_min_element[j] = weights[i];
            length_last_index[j] = i;
            previous_index[i] = length_last_index[j - 1];
            max_length = std::max(max_length, j);
        }
    }
    std::vector<size_t> indices;
    int index = length_last_index[max_length];
    while (index != -1) {
        indices.push_back(index);
        index = previous_index[index];
    }
    std::reverse(indices.begin(), indices.end());
    return indices;
}

std::vector<std::pair<size_t, size_t>> GetIncreasingTower(std::vector<std::pair<size_t, size_t>>& people) {
    std::sort(people.begin(), people.end());
    std::vector<size_t> weights;
    for (auto& pair: people) {
        weights.push_back(pair.second);
    }
    auto increasing_sequnce = GetIncreasingSeqence(weights);
    std::vector<std::pair<size_t, size_t>> tower;
    for (auto& index: increasing_sequnce) {
        tower.push_back(people[index]);
    }
    return tower;
}
int main() {
    std::vector<std::pair<size_t, size_t>> people{{1,2},{2,5},{3,3}};
    auto tower = GetIncreasingTower(people);
    for (auto& pair: tower) {
        std::cout << "(" << pair.first << " " << pair.second << ")" << " ";
    }
    return 0;
}
